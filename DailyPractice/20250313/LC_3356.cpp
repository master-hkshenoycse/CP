#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    int chk(vector<int> &nums,vector<vector<int>>& queries,int l){
        int n=nums.size();
        vector<ll> csum(n+1,0);

        for(ll i=0;i<l;i++){
            ll a=queries[i][0];
            ll b=queries[i][1];
            ll v=queries[i][2];

            csum[a]+=v;
            csum[b+1]-=v;
        }

        for(ll i=1;i<n;i++){
            csum[i]+=csum[i-1];
        }

        for(ll i=0;i<n;i++){
            if(nums[i]>csum[i]){
                return 0;
            }
        }

        return 1;
    }
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int sz=queries.size();
        int lo=0,hi=sz,ans=sz+1;
        while(hi>=lo){
            int mid=(hi+lo)/2;
            if(chk(nums,queries,mid)){
                ans=min(ans,mid);
                hi=mid-1;
            }else{
                lo=mid+1;
            }
        }

        if(ans>sz){
            ans=-1;
        }

        return ans;

    }
};