#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    
    bool parseBoolExpr(string expression) {
        stack<char> st;
        for(char ch:expression){
            if(ch!=')' and ch!=','){
                st.push(ch);
            }else if(ch==')'){
                vector<bool> exp;
                while(st.size()>0 and st.top() !='('){
                    char t=st.top();
                    st.pop();
                    if(t=='t')exp.push_back(true);
                    else exp.push_back(false);
                }
                st.pop();

                if(!st.empty()){
                    char t=st.top();
                    st.pop();

                    bool v=exp[0];
                    if(t=='&'){
                        for(bool b:exp){
                            v=(v & b);
                        }
                    }else if(t=='|'){
                        for(bool b:exp){
                            v=(v | b);
                        }
                    }else{
                        v = !v;
                    }

                    if(v)st.push('t');
                    else st.push('f');
                }

                
            }
        }    

        return st.top()=='t'?true:false;    
   

    }
};