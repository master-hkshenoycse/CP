#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    vector<long long> mostFrequentIDs(vector<int>& nums, vector<int>& freq) {
        map<ll,ll> help;
        multiset<ll> coll;
        vector<ll> sol;

        ll n=nums.size();
        for(ll i=0;i<n;i++){

            if(help.find(nums[i])!=help.end()){
                coll.erase(coll.find(help[nums[i]]));
            }


            help[nums[i]]+=freq[i];
            if(help[nums[i]]==0){
                help.erase(nums[i]);
            }else{
                coll.insert(help[nums[i]]);
            }

            sol.push_back(0);
            if(coll.size()>0){
                sol.back()=*(--coll.end());
            }
        }
        return sol;
    }
};