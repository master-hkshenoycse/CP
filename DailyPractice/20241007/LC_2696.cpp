#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minLength(string s) {
        stack<char> st;
        for(auto ch:s){
            if(ch=='B' and st.size()>0 and st.top()=='A'){
                st.pop();
            }else if(ch=='D' and st.size()>0 and st.top()=='C'){
                st.pop();
            }else{
                st.push(ch);
            }
        }

        return st.size();

    }
};