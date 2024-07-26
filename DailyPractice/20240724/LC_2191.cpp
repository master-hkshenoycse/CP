#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        vector<vector<ll> > coll;
        int n=nums.size();

        for(int i=0;i<n;i++){
            string str=to_string(nums[i]);
            ll value=0;

            for(auto ch:str){
                value=value*10+mapping[ch-'0'];
            }

            coll.push_back({value,i*1ll});
        }

        sort(coll.begin(),coll.end());
        

        vector<int> sol;

        for(auto c:coll){
            sol.push_back(nums[c[1]]);
        }

        return sol;

    }
};