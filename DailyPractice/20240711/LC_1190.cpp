#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string reverseParentheses(string s) {
        int n=s.size();
        stack<int> st;
        for(int i=0;i<n;i++){
            if(s[i]==')'){
                int start=st.top();
                st.pop();
                int end=i;

                string tmp=s.substr(start,end-start+1);
                reverse(tmp.begin(),tmp.end());

                for(int j=start;j<=end;j++){
                    s[j]=tmp[j-start];
                }


            }else if(s[i]=='('){
                st.push(i);
            }
        }

        string sol;
        for(auto ch:s){
            if(ch>='a' and ch<='z'){
                sol+=ch;
            }
        }

        return sol;
    }
};