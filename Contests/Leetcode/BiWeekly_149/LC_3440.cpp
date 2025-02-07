#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        int ans=0,n=startTime.size(),max_gap=0;
        vector<int> gap_time(n+5,0);
        multiset<int> check_other;

        for(int i=0;i<=n;i++){
            if(i==0){
                gap_time[i]=startTime[i];
            }else if(i==n){
                gap_time[i]=eventTime-endTime[i-1];
            }else{
                gap_time[i]=startTime[i]-endTime[i-1];
            }
            ans=max(ans,gap_time[i]);
            check_other.insert(gap_time[i]);
        }
        for(int i=0;i+1<=n;i++){
            int tot=gap_time[i]+gap_time[i+1];
            check_other.erase(check_other.find(gap_time[i]));
            check_other.erase(check_other.find(gap_time[i+1]));

            int eve_time=endTime[i]-startTime[i];
            if(eve_time <= *(--check_other.end())){
                ans=max(ans,tot+eve_time);
            }else{
                ans=max(ans,tot);
            }

            check_other.insert(gap_time[i]);
            check_other.insert(gap_time[i+1]);
        }

        return ans;
    }
};