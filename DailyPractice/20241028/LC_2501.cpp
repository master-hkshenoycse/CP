#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        
        map<int,int> help;
        int ans=1;
        
        for(auto e:nums){
            help[e]=1;
            int sq=sqrt(e);
            if(sq*sq==e){
                if(help.find(sq)!=help.end()){
                    help[e]=max(help[e],help[sq]+1);
                }
            }
            ans=max(ans,help[e]);
        }
        
        if(ans<2){
            ans=-1;
        }
        
        return ans;
    }
};