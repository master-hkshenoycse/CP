#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:

    ll dp[137][17][2];
    ll solve(ll sum,ll ind,ll ti,string &s){
        if(ind==s.size())
            return sum==0;
        
        if(dp[sum][ind][ti] != -1)
            return dp[sum][ind][ti];
        
        int dig=s[ind]-'0';
        ll ret=0;
        for(int i=0;i<=9;i++){
            if(ti && i>dig)
                break;
            
            if(sum<i){
                break;
            }
            ret=ret+solve(sum-i,ind+1,ti && (i==dig),s);
        }
        return dp[sum][ind][ti]=ret;
    }
    ll get_sod(ll n){
        ll ret=0;
        while(n>0){
            ret=ret+(n%10);
            n/=10;
        }
        return ret;
    }
    ll get_cnt(ll sum, ll l,ll r){
        memset(dp,-1,sizeof(dp));
        string r_=to_string(r);
        string l_=to_string(l-1);
        ll ret=solve(sum,0,1,r_);
        memset(dp,-1,sizeof(dp));
        ret-=solve(sum,0,1,l_);
        return ret;
    }   
    long long countFancy(long long l, long long r) {
        set<ll> val;
        
        for(ll i=1;i<1024;i++){

            ll num=0,num_rev=0;
            for(ll j=0;j<10;j++){
                if(i & (1ll<<j))
                    num=num*10+j;   
            }
            val.insert(num);
            
            for(ll j=9;j>=0;j--){
                if(i & (1ll<<j))
                    num_rev=num_rev*10+j;
            }
            val.insert(num_rev);
        }


        ll ans=0;
        for(auto it:val){
            if(it <= 135){
                ans=ans+get_cnt(it,l,r);
            }
        }

        for(auto it:val){
            if(it>=l && it<=r){
                if(val.find(get_sod(it)) == val.end()){
                    ans++;
                }
            }
        }
        return ans;

    }
};