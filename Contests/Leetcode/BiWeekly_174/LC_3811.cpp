#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int alternatingXOR(vector<int>& nums, int target1, int target2) {
        map<int,int> help1,help2;
        int mod=1e9+7;
        int ret=0;

        int c_xor=0;
        for(auto e:nums){   
            c_xor=c_xor ^ e;
            int target_1_req=(target1 ^ c_xor);
            int target_2_req=(target2 ^ c_xor);
            int ways_1=help2[target_1_req];
            int ways_2=help1[target_2_req];
            if(c_xor == target1)
                ways_1=(ways_1+1)%mod;
            ret=(ways_1+ways_2)%mod;
            help1[c_xor]=(help1[c_xor]+ways_1)%mod;
            help2[c_xor]=(help2[c_xor]+ways_2)%mod;
        }

        return ret;
    }
};