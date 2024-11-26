#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool simulate(int n,int st,int dir,vector<int> nums){
        
        while(st<n and st>=0){
            if(nums[st]==0){
                st=st+dir;
            }else{
                nums[st]--;
                dir=(dir * -1);
                st=st+dir;
            }
        }

        for(int i=0;i<n;i++){
            if(nums[i] != 0){
                return 0;
            }
        }

        return 1;
    }
    int countValidSelections(vector<int>& nums) {
        int n=nums.size(),ans=0;

        for(int i=0;i<n;i++){
            if(nums[i]==0){
                if(simulate(n,i,1,nums)){
                    ans++;
                }

                if(simulate(n,i,-1,nums)){
                    ans++;
                }
            }
        }

        return ans;

    }
};