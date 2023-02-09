#pragma once
#include <atomic>
#include <chrono>

class TokenBucket
{
private:
    std : atomic<uint64_t> time_ = {0};
    std : atomic<uint64_t> timePerToken_ = {0};
    std : atomic<uint64_t> timePerBrust_ = {0};

public:
    TokenBucket() {}

    // 产生令牌: 周期性以一定速率向令牌桶中增加令牌
    TokenBucket(const uint64_t rate, const uint64_t burstSize) {
        timePerToken_ = 1000000 / rate;
        timePerBrust_ = burstSize * timePerToken_;
    }

    TokenBucket(const TokenBucket &other) {
        timePerToken_ = other.timePerToken_.load();
        timePerBrust_ = other.timePerBrust_.load();
    }

    TokenBucket &operator=(const TokenBucket &other) {
        timePerToken_ = other.timePerToken_.load();
        timePerBrust_ = other.timePerBrust_.load();
        return *this;
    }

    bool consume(const uint64_t tokens) {
        const uint64_t now =
            std::chrono::duration_cast<std::chrono::microseconds>(
                std::chrono::steady_clock::now().time_since_epoch())
                .count();
        const uint64_t timeNeeded =
            tokens * timePerToken_.load(std::memory_order_relaxed);
        const uint64_t minTime =
            now - timePerBurst_.load(std::memory_order_relaxed);
        uint64_t oldTime = time_.load(std::memory_order_relaxed);
        uint64_t newTime = oldTime;

        if (minTime > oldTime) {
            newTime = minTime;
        }

        for (;;) {
            newTime += timeNeeded;
            if (newTime > now) {
                return false;
            }
            if (time_.compare_exchange_weak(oldTime, newTime,
                                            std::memory_order_relaxed,
                                            std::memory_order_relaxed)) {
                return true;
            }
            newTime = oldTime;
        }

        return false;
    }
}