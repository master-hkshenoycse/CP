#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    long long kSum(vector<int>& nums, int k) {
        int n=nums.size();
        ll maxsum=0;

        vector<ll> subtract;
        for(ll i=0;i<n;i++){
            if(nums[i]>=0){
                maxsum+=nums[i];
            }else{
                nums[i]=abs(nums[i]);
            }
        }

        if(k==1){
            return maxsum;
        }

        //sorting by absolute value
        sort(nums.begin(),nums.end());
        priority_queue<pair<ll,ll> ,vector<pair<ll,ll> > ,greater<pair<ll,ll> > > pq;
        pq.push({nums[0],0});

        while(pq.size()>0 and subtract.size()<k-1){
            pair<ll,ll> topp=pq.top();
            pq.pop();

            ll subt=topp.first;
            ll idx=topp.second;

            subtract.push_back(subt);
            if(idx<n-1){
                pq.push({subt+nums[idx+1],idx+1});//increase by adding next element
                pq.push({subt+nums[idx+1]-nums[idx],idx+1});//add next element and subtract current element
            }
        }

        
        return maxsum-subtract.back();

    }
};