#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll mod=1e9+7;
ll modpow(ll a,ll n){
    ll res=1;
    while(n>0){
        if(n%2){
            res=(res * a)%mod;
        }
        n/=2;
        a=(a*a)%mod;
    }
    return res;
}
int main() {
	// your code goes here
    
	/*
	If the first person falls off the first step, there are N-1 people and M-1 stepsleft.
    If the first person doesn’t fall, there are N people and M-1 steps left.
	Base cases=p(0,M)=1;
	if N>M p(N,M)=0;
	
	p(N,M)=half*p(N-1,M)+half*p(N-1,M-1);
	*/
	
	
	
    ll half=modpow(2,mod-2);
    
    ll t;
    cin>>t;
    
    while(t--){
        ll n,m;
        cin>>n>>m;
        
        vector<vector<ll> > dp(n+1,vector<ll> (m+1,0));
        for(ll i=0;i<=n;i++){
            for(ll j=0;j<=m;j++){
                if(i==0){
                    dp[i][j]=1;
                }else if(i>j){
                    dp[i][j]=0;
                }else{
                    dp[i][j]=half *(dp[i-1][j-1]+dp[i][j-1]);
                    dp[i][j]%=mod;
                }
            }
        }
        
        for(ll i=1;i<=m;i++){
            cout<<dp[n][i]<<" ";
        }
        
        cout<<endl;
    }
}
