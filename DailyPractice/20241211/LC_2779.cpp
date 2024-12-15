#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int csum[100005];
    int maximumBeauty(vector<int>& nums, int k) {
       int n=nums.size();
       for(int i=0;i<n;i++){
           csum[nums[i]]++;
       }
    
       for(int i=1;i<=100000;i++){
           csum[i]=csum[i]+csum[i-1];
       }
       
       int ans=0;
       for(int i=0;i<=100000;i++){
           int lo=max(0,i-k);
           int hi=min(100000,i+k);
           int cnt=csum[hi];
           if(lo>0){
               cnt-=csum[lo-1];
           }
           ans=max(ans,cnt);
       }
        return ans;
    }
};