#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    ll get_value(vector<vector<ll> >&csum,ll l,ll r){
        ll value=0;
        for(ll i=0;i<=30;i++){
            if(csum[r][i]-csum[l-1][i]==r-l+1){
                value=value+(1ll<<i);
            }
        }
        return value;
    }
    ll get_sol(vector<vector<ll> > &csum,ll n,ll k){
        ll cnt=0;
        for(ll i=1;i<=n;i++){

            ll lo=i,hi=n,r=i-1,q=i-1;
            while(hi>=lo){
                ll mid=(hi+lo)/2ll;
                ll value=get_value(csum,i,mid);

                if(value>=k){
                    r=max(r,mid);
                    lo=mid+1;
                }else{
                    hi=mid-1;
                }
            }

            lo=i,hi=n;
            while(hi>=lo){
                ll mid=(hi+lo)/2ll;
                ll value=get_value(csum,i,mid);
                if(value>k){
                    q=max(q,mid);
                    lo=mid+1;
                }else{
                    hi=mid-1;
                }
            }

           // cout<<i<<" "<<r<<" "<<q<<endl;
            if(r>=i and r>=q){

                cnt=cnt+(r-q);
            }


        }

        return cnt;
    }
    long long countSubarrays(vector<int>& nums, int k) {
        ll n=nums.size();

        vector<vector<ll> > csum(n+1,vector<ll> (35,0));
        for(ll i=1;i<=n;i++){
            ll val=nums[i-1];
            for(ll j=0;j<=30;j++){
                csum[i][j]=csum[i-1][j];
                if(val & (1ll<<j)){
                    csum[i][j]++;
                }
            }
        }



        return get_sol(csum,n,k);
    }
};