#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(),meetings.end());
        
        int st=-1,en=-1;
        vector<vector<int> > schdule;
        
        for(auto m:meetings){
            if(m[0]>en){
                if(en!=-1){
                  schdule.push_back({st,en});  
                }
                st=m[0];
                en=m[1];
            }else{
                en=max(en,m[1]);
            } 
        }
        
        schdule.push_back({st,en});
        
        int ans=0,sz=schdule.size();
        for(int i=0;i<sz;i++){
            if(i==0){
                ans=ans+schdule[i][0]-1;
            }else{
                ans=ans+schdule[i][0]-schdule[i-1][1]-1;
            }
            
            if(i==sz-1){
                ans=ans+days-schdule[i][1];
            }
        }
        
        return ans;
    }
};