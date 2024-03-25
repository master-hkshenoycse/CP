#include<bits/stdc++.h>
#define ll long long
#define dd double
using namespace std;



int main(){
    ll t;
    cin>>t;

    while(t--){
        ll x,l;
        cin>>x>>l;
    
        vector<ll> dp(x+2,0);
        dp[0]=1;
        dp[1]=1;

        for(ll i=2;i<=x;i++){
            dp[i]=min(dp[i-1]+dp[i-2],l);
        }

        cout<<dp[x]<<endl;
    }
    
}