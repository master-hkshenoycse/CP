#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        vector<vector<int> > tmp;
        int n=positions.size();
        
        for(int i=0;i<n;i++){
            tmp.push_back({positions[i],healths[i],i});
        }
        sort(tmp.begin(),tmp.end());
        
        stack<int> st;
        for(int i=0;i<n;i++){
            
            if(directions[tmp[i][2]]=='L'){
                
                while(st.size()>0 and healths[st.top()]<healths[tmp[i][2]]){
                    healths[st.top()]=0;
                    healths[tmp[i][2]]--;
                    st.pop();
                }
                
                if(st.size()>0 and healths[st.top()]==healths[tmp[i][2]]){
                    healths[st.top()]=0;
                    healths[tmp[i][2]]=0;
                    st.pop();
                }else if(st.size()>0 and healths[st.top()]>healths[tmp[i][2]]){
                    healths[st.top()]--;
                    healths[tmp[i][2]]=0;
                }
                
            }else{
                st.push(tmp[i][2]);
            }
        }
        
        vector<int> sol;
        for(int i=0;i<n;i++){
            if(healths[i]>0){
                sol.push_back(healths[i]);
            }
        }
        
        return sol;
    }
};