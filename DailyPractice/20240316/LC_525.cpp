#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        map<int,int> help;
        help[0]=0;
        int n=nums.size(),ans=0,cs=0;

        for(int i=1;i<=n;i++){
            if(nums[i-1])cs++;
            else cs--;

            if(help.find(cs) != help.end()){
                ans=max(ans,i-help[cs]);
            }else{
                help[cs]=i;
            }
        }
        return ans;
    }
};