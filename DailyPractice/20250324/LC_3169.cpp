#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int countDays(int days, vector<vector<int>>& meetings) {
            int ret=days;
            sort(meetings.begin(),meetings.end());
    
            int st=-1,en=-1;
            for(auto m:meetings){
                if(m[0]>en){
                    if(st!=-1){
                        ret=ret-(en-st+1);
                    }
                    st=m[0];
                    en=m[1];
                    
                }else{
                    en=max(en,m[1]);
                }
            }
    
            ret=ret-(en-st+1);
            return ret;
        }
    };