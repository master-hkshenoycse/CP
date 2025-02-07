#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        
        int n=startTime.size();
        vector<int> gaps_time(n+5,0);
        int ans=0;

        for(int i=0;i<=n;i++){
            if(i==0){
                gaps_time[i]=startTime[i];
            }else if(i==n){
                gaps_time[i]=eventTime-endTime[i-1];
            }else{
                gaps_time[i]=startTime[i]-endTime[i-1];
            }


            ans=max(ans,gaps_time[i]);

            if(i-1>=0){
                gaps_time[i]+=gaps_time[i-1];
            }
        }

        for(int i=0;i+k<=n;i++){
            int tot=gaps_time[i+k];
            if(i-1>=0){
                tot-=gaps_time[i-1];
            }
            ans=max(ans,tot);
        }

        return ans;




            
            
    }
};