#include<bits/stdc++.h>
using namespace std;

#define ll long long
class Solution {
  public:
    long long geekTasks(int n, int m, int q, vector<vector<int>> &tasks) {
        // code here
        
        ll min_x=n,min_y=m;
        vector<ll> max_row(n,-1);
        for(auto t:tasks){
            min_x=min(min_x,t[0]*1ll);
            min_y=min(min_y,t[1]*1ll);
            max_row[t[0]]=max(max_row[t[0]],t[1]*1ll);
        }
        
        ll max_cnt=(min_x+1)*(min_y+1);
        ll cnt_non_zero=0;
        for(ll i=n-1;i>=0;i--){
            if(i+1<n){
                max_row[i]=max(max_row[i],max_row[i+1]);
            }
            cnt_non_zero+=max_row[i]+1;
            
        }
        
        
        
        return cnt_non_zero-max_cnt;
        
        
    }
};
