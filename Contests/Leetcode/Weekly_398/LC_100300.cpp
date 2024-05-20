#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    ll get_nod(ll n){
        ll c=0;
        while(n>0){
            c++;
            n/=10;
        }
        return c;
    }
    long long sumDigitDifferences(vector<int>& nums) {
        ll n=nums.size();
        ll pairs=(n*n-n)/2ll;
        ll nod=get_nod(nums[0]);
        ll ans=nod*pairs;
        vector<vector<ll> > cnt(nod,vector<ll> (10,0));
        
        for(auto e:nums){
            vector<ll> digs;
            while(e>0){
                digs.push_back(e%10);
                e/=10;
            }
            
            reverse(digs.begin(),digs.end());
            for(ll i=0;i<nod;i++){
                cnt[i][digs[i]]++;
            }
        }
        
        for(ll i=0;i<nod;i++){
            for(ll j=0;j<10;j++){
                ans=ans-(cnt[i][j]*cnt[i][j]-cnt[i][j])/2ll;
            }
        }
        
        return ans;
    }
};