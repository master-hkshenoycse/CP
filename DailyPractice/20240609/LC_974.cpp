#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        vector<int> help(k,0);
        help[0]=1;

        int ans=0,cs=0;
        for(auto e:nums){
            cs=(cs+e)%k;
            if(cs<0){
                cs=cs+k;
            }
            ans=ans+help[cs];
            help[cs]++;
        }

        return ans;
    }
};