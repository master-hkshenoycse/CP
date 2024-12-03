#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int getLargestOutlier(vector<int>& nums) {
        int total_sum=0;
        multiset<int> v;
        for(auto e:nums){
            total_sum+=e;
            v.insert(e);
        }

        int ans=INT_MIN;
        for(auto e:nums){
            v.erase(v.find(e));
            int rem_sum=total_sum-e;
            if(rem_sum%2==0){
                int req=rem_sum/2;
                if(v.find(req) != v.end()){
                    ans=max(ans,e);
                }
            }
            v.insert(e);
        }

        return ans;
    }
};