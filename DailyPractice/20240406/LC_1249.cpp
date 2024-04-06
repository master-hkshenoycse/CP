#include<bits/stdc++.h>

using namespace std; 
lass Solution {
public:
    string minRemoveToMakeValid(string s) {
        int n=s.size();
        vector<int> rem(n,0);
        stack<int> st;
        
        for(int i=0;i<n;i++){
            if(s[i]=='(' or s[i]==')'){
                
                if(s[i]=='('){
                    st.push(i);
                }else{
                    
                    if(st.size()==0){
                        rem[i]=1;
                    }else{
                        st.pop();
                    }
                }
            }
        }
        
        while(st.size()>0){
            rem[st.top()]=1;
            st.pop();
        }
        
        string sol;
        for(int i=0;i<n;i++){
            if(rem[i]==0){
                sol+=s[i];
            }
        }
        return sol;
    }
};