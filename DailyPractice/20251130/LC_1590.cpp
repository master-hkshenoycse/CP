#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n=nums.size();
        int req=0,cs=0;

        for(auto e:nums){
            req=(req+e)%p;
        }

        if(req==0){
            return 0;
        }

        map<int,int> help;
        help[0]=0;

        
        int ans=n;
        for(int i=1;i<=n;i++){
            cs=(cs+nums[i-1])%p;
            int search=(cs-req+p)%p;
            if(help.find(search) != help.end()){
                ans=min(ans,i-help[search]);
            }
            help[cs]=i;
        }

        if(ans==n){
            ans=-1;
        }

        return ans;




    }
};