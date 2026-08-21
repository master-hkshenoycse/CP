#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> kthRemainingInteger(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        vector<int> cnt_even(n,0);
        for(int i=0;i<n;i++){
            cnt_even[i]=((nums[i]%2)==0);
            if(i-1>=0)cnt_even[i]+=cnt_even[i-1];
        }

        vector<int> sol;
        for(auto q:queries){
            int l=q[0];
            int r=q[1];
            int k=q[2];

            int lo=0,hi=2e9+1e6,ret=2e9+1e6;

            while(hi>=lo){
                int mid=lo+(hi-lo)/2;
                int cnt=mid/2;
                int cnt_excl=0;
                if(nums[r]<=mid){
                    cnt_excl=cnt_even[r];
                    if(l-1>=0)
                        cnt_excl-=cnt_even[l-1];
                    if(mid==10){
                        cout<<"10 here "<<cnt_even[r]<<" "<<cnt_excl<<endl;
                    }
                }else if(nums[l]>mid){

                }else{
                    int new_r=upper_bound(nums.begin(),nums.end(),mid)-nums.begin();
                    new_r--;
                    cnt_excl=cnt_even[new_r];
                    if(l-1>=0)
                        cnt_excl-=cnt_even[l-1];
                }
                cnt-=cnt_excl;
                if(cnt>=k){
                    ret=min(ret,mid);
                    hi=mid-1;
                }else{
                    lo=mid+1;
                }
            }
            sol.push_back(ret);
        }
        return sol;
    }
};