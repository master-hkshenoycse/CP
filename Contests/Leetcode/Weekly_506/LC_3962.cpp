#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    long long maxSum(vector<int>& nums, int k) {
        ll n=nums.size();
        ll ans=-1e18;

        vector<int> sorted=nums;
        sort(sorted.begin(),sorted.end());

        multiset<ll> candidates, others;
        multiset<ll> initCandidates,initOthers;

        for(ll i=0;i<n-k;i++)
            initOthers.insert(sorted[i]);
        
        for(ll i=n-k;i<n;i++)
            initCandidates.insert(sorted[i]);
        
        for(ll start=0;start<n;start++){
              candidates = initCandidates;
              others = initOthers;
              ll currentSum = 0;
              for(ll end=start;end<n;end++){
            
                //Try to extend the candidates
                if(!others.empty()){
                    ll val;
                    auto itOther = others.find(nums[end]);

                    if(itOther != others.end()){
                        val=nums[end];
                        others.erase(itOther);
                    }else{
                        auto itLargestOther = prev(others.end());
                        val = *itLargestOther;
                        others.erase(itLargestOther);
                    }
                    candidates.insert(val);
                }


                //As window size increases number of candidate also
                //increases, so pick the largest possible candidate
                
                auto itLargestCandidate = prev(candidates.end());
                currentSum += *itLargestCandidate;
                candidates.erase(itLargestCandidate);
                ans = max(ans, currentSum);

              }
        }
        
         return ans;


    }
};