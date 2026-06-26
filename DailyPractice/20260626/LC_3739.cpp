#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    void get_sol(vector<ll> &csum,ll l,ll r,ll &ret){
        if(l>=r)
            return;

        int mid=(l+r)/2;

        get_sol(csum,l,mid,ret);
        get_sol(csum,mid+1,r,ret);

        vector<ll> tmp;
        int i=l,j=mid+1;
        while(i<=mid && j<=r){
            if(csum[i]<csum[j]){
                tmp.push_back(csum[i]);
                i++;
            }else{
                ret+=(i-l);
                tmp.push_back(csum[j]);
                j++;
            }
        }

        while(i<=mid){
            tmp.push_back(csum[i]);
            i++;
        }

        while(j<=r){
            ret+=(i-l);
            tmp.push_back(csum[j]);
            j++;
        }


        for(int i=0;i<tmp.size();i++){
            csum[i+l]=tmp[i];
        }        

        
    }
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        ll n=nums.size();
        vector<ll> csum(n+1,0);
        for(int i=1;i<=n;i++){
            if(nums[i-1]==target)csum[i]=1;
            else csum[i]=-1;
            csum[i]+=csum[i-1];
        }

        ll ret=0;
        get_sol(csum,0,n,ret);
        
        return ret;



    }
};