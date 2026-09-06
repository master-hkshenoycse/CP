#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    bool check_sum(ll s,int x){
        ll fs_d=s%10;
        ll ls_d=fs_d;
        while(s>0){
            ls_d=(s%10);
            s/=10;
        }
        return (ls_d==x) && (fs_d==x);
    }
    int countValidSubarrays(vector<int>& nums, int x) {
        ll n=nums.size();
        int ans=0;
        for(ll i=0;i<n;i++){
            ll curr_sum=0;
            for(ll j=i;j<n;j++){
                curr_sum=curr_sum+nums[j]*1ll;
                if(check_sum(curr_sum,x))
                    ans++;
            }
        }
        return ans;
    }
};