#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<bool> subsequenceSumAfterCapping(vector<int>& nums, int k) {
        int n=nums.size();
        int j=0;
        vector<int> poss(k+1,0);
        poss[0]=1;

        sort(nums.begin(),nums.end());
        vector<bool> sol;

        for(int i=1;i<=n;i++){
            int f=0;
            while(j<n && nums[j]<i){
                for(int v=k;v>=0;v--){
                    if(v+nums[j]<=k && poss[v]==1){
                        poss[v+nums[j]]=1;
                    }
                }
                j++;
            }

            int rem=n-j;
            for(int v=0;v<=k;v++){
                if(poss[v]==1){
                    int extra = k-v;
                    if(extra%i==0){
                        if(extra/i <= rem){
                            f=1;
                            break;
                        }
                    }
                }
            }

            if(f){
                sol.push_back(1);
            }else{
                sol.push_back(0);
            }
        }   

        return sol;
    }
};