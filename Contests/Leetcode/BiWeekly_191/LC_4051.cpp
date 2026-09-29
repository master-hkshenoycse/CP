#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    void solve(vector<ll> &a,ll l,ll r,ll goal,ll k,ll &ret){
        if(l>=r){
            return ;
        }

        ll mid=(l+r)/2;
        vector<ll> lf,rf;
        solve(a,l,mid,goal,k,ret);
        solve(a,mid+1,r,goal,k,ret);

        ll p1=l,p2=l;
        //rf[j]-lf[p1]-goal>k
        //lf[p1]<=rf[j]-goal-k;
        //rf[j]-lf[p2]-goal<=-k
        //lf[p2] >= rf[j]-goal+k;
        for(ll i=mid+1;i<=r;i++){
            ll x = a[i]-goal-k;
            while(p1<=mid && a[p1]<=x)
                p1++;
            ret=ret+p1-l;

            x=a[i]-goal+k;
            while(p2<=mid && a[p2]<x)
                p2++;
            ret=ret+(mid-p2+1);
        }

        vector<ll> tmp;
        ll i=l,j=mid+1;
        while(i<=mid && j<=r){
            if(a[i]<=a[j])
                tmp.push_back(a[i]),i++;
            else
                tmp.push_back(a[j]),j++;
        }

        while(i<=mid)
            tmp.push_back(a[i]),i++;
        
        while(j<=r)
            tmp.push_back(a[j]),j++;

        for(int i=0;i<r-l+1;i++)
            a[l+i]=tmp[i];

    }
    long long distantSubarrays(vector<int>& nums, int goal, int k) {
        ll n=nums.size();
        vector<ll> csum(n+1,0);
        for(ll i=1;i<=n;i++)
            csum[i]=csum[i-1]+nums[i-1];
        
        ll ret=0;
        if(k==0)
            return (n*n+n)/2ll;
        solve(csum,0,n,goal,k,ret);
        return ret;
    }
};