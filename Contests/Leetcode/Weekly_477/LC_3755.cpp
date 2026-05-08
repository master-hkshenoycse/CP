#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxBalancedSubarray(vector<int>& nums) {
        int ans=0,n=nums.size(),c_xor=0,bal=0;
        map<pair<int,int>,int> help;
        help[{0,0}]=0;
        for(int i=1;i<=n;i++){
            c_xor=(c_xor ^ nums[i-1]);
            if(nums[i-1]%2)
                bal++;
            else
                bal--;
            
            if(help.find({c_xor,bal}) == help.end())
                help[{c_xor,bal}]=i;
            else
                ans=max(ans,i-help[{c_xor,bal}]);
        }
        return ans;



    }
};