#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    long long numberOfSubsequences(vector<int>& nums) {
        ll ans=0,n=nums.size();
        map<pair<ll,ll>,ll> help;

        for(ll i=n-1;i>=0;i--){
            
            for(ll j=i-2;j>=0;j--){
                ll num=nums[j];
                ll den=nums[i];
                ll gc=__gcd(num,den);

                num/=gc;
                den/=gc;

                if(help.find({num,den}) != help.end()){
                    
                    ans=ans+help[{num,den}]*1ll;
                }
            }

            for(ll j=i+3;j<n;j++){
                ll num=nums[j];
                ll den=nums[i+1];
                ll gc=__gcd(num,den);
                num/=gc;
                den/=gc;
                help[{num,den}]++;
            }
            



        }

        return ans;
    }
};