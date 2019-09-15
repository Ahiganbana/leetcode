#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution{
public :
    bool isValid(string s){
        if(s == ""){
            cout << "true";
            return true;
        }
        vector<char> brace;
        for (int i = 0; i < s.length();i++){
            if(s[i] == '{' || s[i] == '(' || s[i] == '['){
                brace.push_back(s[i]);
            }
            else if(s[i] == '}' && !brace.empty() && brace.back() == '{'){
                    brace.pop_back();
            }
            else if(s[i] == ')' && !brace.empty() && brace.back() == '('){
                    brace.pop_back();
            }
            else if(s[i] == ']' && !brace.empty() && brace.back() == '['){
                    brace.pop_back();
            }
            else{
                return false;
            }
        }
        if(brace.empty())
            return true;
        else
            return false;
    } 
    bool isValid1(string s) {
    if(s=="") return true;
    if(s.length()%2!=0) return false;
    stack<char> ss;
    for(auto i:s) {
        if (i=='{' || i=='('|| i=='[') ss.push(i);
        else {
            if (ss.size() == 0 && (i == ']' || i == '}' || i == ')')) return false;
            else if ((i == '}' && ss.top() != '{') || (i == ']' && ss.top() != '[') || (i == ')' && ss.top() != '(') )
                return false;
            else
                ss.pop();
        }
    }
    if (ss.size() != 0 ) return false; 
    return true;
}
};

int main(){
    string input;
    cin >> input;
    Solution solution;
    bool result = solution.isValid(input);
    //solution.isValid(input);
    if(result == false){
        cout << "false" <<endl;
    }
    else{
        cout << "true" << endl;
    }
    system("pause");
    return 0;
}