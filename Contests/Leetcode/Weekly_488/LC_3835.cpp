#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    
    long long countSubarrays(vector<int>& nums, long long k) {
        ll ans=0,n=nums.size();
        deque<ll> min_dq,max_dq;

        ll j=0;
        for(ll i=0;i<n;i++){
            while(min_dq.size()>0 && nums[min_dq.back()]>=nums[i])
                min_dq.pop_back();
            
            while(max_dq.size()>0 && nums[max_dq.back()]<=nums[i])
                max_dq.pop_back();
            
            min_dq.push_back(i);
            max_dq.push_back(i);

            while(j<=i && (nums[max_dq.front()]-nums[min_dq.front()])*(i-j+1)>k){
                if(max_dq.size()>0  && max_dq.front()==j)
                    max_dq.pop_front();
                
                if(min_dq.size()>0  && min_dq.front()==j)
                    min_dq.pop_front();

                j++;
            }
            ans=ans+(i-j+1);
        }
            return ans;
    }
};