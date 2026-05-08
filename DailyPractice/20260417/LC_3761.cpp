#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    ll get_rev(ll n){
        ll ret=0;
        while(n>0){
            ret=ret*10+(n%10);
            n/=10;
        }
        return ret;
    }
    int minMirrorPairDistance(vector<int>& nums) {
        int n=nums.size();
        map<ll,ll> index_rev;
        ll ret=n+1;
        for(ll i=0;i<n;i++){
            
            if(index_rev.find(nums[i]) != index_rev.end()){
                ret=min(ret,i-index_rev[nums[i]]);
            }   

            index_rev[get_rev(nums[i])]=i;
        }

        if(ret==n+1)
            ret=-1;

        return ret;
    }
};