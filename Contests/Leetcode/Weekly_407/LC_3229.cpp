#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    long long minimumOperations(vector<int>& nums, vector<int>& target) {
        ll n=nums.size();
        vector<ll> diff(n),montone(n,0);

        for(ll i=0;i<n;i++){
            diff[i]=target[i]-nums[i];
        }

        ll ans=abs(diff[0]);
        for(int i=1;i<n;i++){
            if(diff[i]==0){
                continue;
            }
            if(diff[i]*diff[i-1]>0){
                if(abs(diff[i])>abs(diff[i-1])){
                    ans=ans+abs(diff[i])-abs(diff[i-1]);
                }
            }else{
                ans=ans+abs(diff[i]);
            }
        }
        return ans;
    }
};