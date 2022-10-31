#include <iostream>
#include<cstring>
#include <stack>
#include <map>

using namespace std;
 
bool isBalanced(string exp){
 
    map<char, char> mapping;
    mapping['}'] = '{';
    mapping[')'] = '(';
    mapping[']'] = '[';
 
    map<char, char>::iterator itr;
 
    // Create stack
    stack<char> stk;
 
    for (int i=0; i<exp.length(); i++){
        if (exp[i] == '{' || exp[i] == '[' || exp[i] == '('){
            stk.push(exp[i]);
        } else if (exp[i] == '}' || exp[i] == ']' || exp[i] == ')'){
            if (stk.empty()){
                return false;
            } else {
                char temp = stk.top();
                itr = mapping.find(exp[i]);
                if (temp == itr->second){  // itr->first is key, itr->second is value
                    stk.pop();
                } else {
                    return false;
                }
            }
        }
    }
    return stk.empty() ? true : false;
}








bool isValid(string s) {
        
        stack<char> st;
        st.push('#'); //To avoid underflow
        for(int i=0;i<s.length();i++){
            if(s[i] == '(' || s[i] == '{' || s[i] == '['){
                st.push(s[i]);
            }
            else{
                char ch = st.top();
                st.pop();
                if(ch == '#') return false;
                else if(!(ch == '(' && s[i] == ')') && !(ch == '{' && s[i] == '}') && !(ch == '[' && s[i] == ']')){
                    return false;
                }
            }
        }
        if(st.top() == '#') return true;
        return false;
    }

 
int main() {
 
    string A = "{]";
    cout<<isValid(A);

    
   
 
    return 0;
}