#include<iostream>
#include<string>
#include<stack>
using namespace std;

int priority(char op) {
    if(op == '*'){
        return 1;
    }else{
        return 0;
    }
}

string getDigit(string& s, size_t &ptr) {
    string ret = "";
    while(isdigit(s[ptr])) {
        ret.push_back(s[ptr++]);
    }
    return ret;
}

int calculate(int num1, int num2, char op) {
    if(op == '*'){
        return num1 * num2;
    }else{
        return num1 + num2;
    }
}

void trim(string &s)
{
	int index = 0;
	if(!s.empty())
	{
		while( (index = s.find(' ',index)) != string::npos)
		{
			s.erase(index,1);
		}
	}
}

int main() {
    string s;
    cin >> s;
    stack<string> numstack;
    stack<char> charstack;
    trim(s);
    size_t ptr = 0;
    while(ptr < s.size()) {
        char cur = s[ptr];
        if(isdigit(cur)) {
            string digit = getDigit(s, ptr);
            numstack.push(digit);
        }else{
            ++ptr; 
            if(!charstack.empty()) {
                if(priority(cur) <= priority(charstack.top())) {
                    int num1 = stoi(numstack.top());
                    numstack.pop();
                    int num2 = stoi(numstack.top());
                    numstack.pop();
                    char op = charstack.top();
                    charstack.pop();
                    int result = calculate(num1, num2, op);
                    numstack.push(to_string(result));
                    charstack.push(cur);
                }
                else{
                    charstack.push(cur);
                }
            }else{
                charstack.push(cur);
            }
        }
    }
    while(!charstack.empty()) {
        char op = charstack.top();
        charstack.pop();
        int num1 = stoi(numstack.top());
        numstack.pop();
        int num2 = stoi(numstack.top());
        numstack.pop();
        int result = calculate(num1, num2, op);
        numstack.push(to_string(result));
    }
    string res = numstack.top();
    if(res.size() <= 4) {
        cout << stoi(res);
    }else{
        cout << stoi(res.substr(res.size() - 4, 4));
    }
    return 0;
}