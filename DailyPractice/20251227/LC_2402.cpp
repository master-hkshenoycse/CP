#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
    
        vector<ll> meeting_cnt(n,0),room_free(n,0);
        sort(meetings.begin(),meetings.end());
        
        for(auto m:meetings){
            ll st=m[0];
            ll en=m[1];
            
            
            ll min_time=1e18,min_ind=-1,allot=0;
            for(int j=0;j<n;j++){
                if(room_free[j]<min_time){
                    min_time=room_free[j];
                    min_ind=j;
                }
                
                if(room_free[j]<=st){
                    room_free[j]=en;
                    meeting_cnt[j]++;
                    allot=1;
                    break;
                }
            }
            
            
            if(allot==0){
                meeting_cnt[min_ind]++;
                room_free[min_ind]=max(room_free[min_ind],st)+(ll)(en-st);
            }
        }
        
        int cnt=0,sol=-1;
        for(int i=0;i<n;i++){
            if(meeting_cnt[i]>cnt){
                cnt=meeting_cnt[i];
                sol=i;
            }
        }
        
        return sol;
    }
};