#include <iostream>
#include <atomic> 
#include <ctime>
#include <time.h>
 
 
class TokenBucket {
	typedef enum color{
		GREEN,
		RED
	}COLOR;
private :
	int m_cir; // 添加令牌的速率
	int m_cbs; // 桶的容量
 
	std::atomic<int64_t> m_clsLastUpdateTime; // 上次桶内令牌数更新时间
	std::atomic<int64_t> m_clsCurTokenNum; // 当前桶内令牌数
 
	// 毫秒级时间，不够用可以自己重写
	int64_t _get_cur_time() {
		return clock();
	}
 
public:
	TokenBucket(int cir, int cbs) {
		m_cir = cir;
		m_cbs = cbs;
		m_clsLastUpdateTime = _get_cur_time();
	}
 
	~TokenBucket() {}
 
	/************************ 
	  数据包处理函数
	  参数：token, 数据包大小
	  返回值：RED, 惩罚处理
		     GREED, 放行
	************************/
	COLOR packetProcess(int token) {
		int64_t nowTime;
		int64_t timeInterval;
		int64_t updateTokenNum;
		int64_t curTokenNum = m_clsCurTokenNum.load();
		if (token <= curTokenNum) {
			m_clsCurTokenNum.fetch_sub(token);
			return GREEN;
		}
		nowTime = _get_cur_time();
		timeInterval = nowTime - m_clsLastUpdateTime.load();
		updateTokenNum = timeInterval * m_cir + curTokenNum;
		if (updateTokenNum < token) {
			return RED;
		}
		else {
			updateTokenBucket(nowTime, updateTokenNum);
		}
		m_clsCurTokenNum.fetch_sub(token);
        return GREEN;
	}
 
	/************************ 
	  更新令牌桶内的时间以及数量
	  参数：time, 更新时间
		    num, 数量
	  返回值：void
	************************/
	void updateTokenBucket(int64_t time, int64_t num) {
		m_clsLastUpdateTime.store(time);
		m_clsCurTokenNum.store(num);
	}
};