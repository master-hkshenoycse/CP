#include<bits/stdc++.h>
#include <iterator>
#include <iostream>
#include <numeric>
#include <math.h>
#define ll long long
#define ull long
#define mpa make_pair
#define pb push_back
#define ff first
#define pii pair<ll,ll>
#define dd long double
#define trace(x) cerr << #x << " : " << x << endl
#define ss second
#define boost ios_base::sync_with_stdio(0)
#define forp(i,a,b) for(ll i=a;i<=b;i++)
#define rep(i,n)    for(ll i=0;i<n;++i)
#define ren(i,n)    for(ll i=n-1;i>=0;i--)
#define forn(i,a,b) for(ll i=a;i>=b;i--)
#define all(c) (c).begin(),(c).end()
#define tr(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end();
#define sc(x) scanf("%lld",&x)
#define clr(x,val) memset(x,val,sizeof(x))
#define pr(x) printf("%lld\n",x) 
#define gc getchar
#define pdd pair<dd,dd>
#define prec(x) cout<<fixed<<setprecision(x)
#define fre freopen("rental.in","r",stdin),freopen("rental.out","w",stdout)
#define arr array 
using namespace std;
bool check(string &s,ll c){
    vector<ll> dp(7,0),tmp(7,0);

    dp[3]=1;
    
    for(char ch:s){
        fill(tmp.begin(),tmp.end(),0);

        for(ll p=-3;p<=3;p++){
            if(!dp[p+3])
                continue;
            
                for(ll q=-3;q<=3;q++){
                    if(p==q || abs(p-q)>c)
                        continue;
                    
                    if(ch=='+' && q<=0)
                        continue;
                    
                    if(ch=='-' && q>=0)
                        continue;
                    
                    if(ch=='0' && q!=0)
                        continue;
                    
                    tmp[q+3]=1;
                }
        }

        dp=tmp;
    }

    for(auto x:dp)
        if(x)
            return true;
    return false;
}
void solve(ll tc){
    ll n;
    string s;
    cin>>n>>s;

    if(s[0]=='0'){
        cout<<-1<<endl;
        return;
    }

    for(ll i=1;i<n;i++){
        if(s[i]=='0' && s[i-1]=='0'){
            cout<<-1<<endl;
            return;
        }
    }

    for(ll cost=1;cost<=3;cost++){
        if(check(s,cost)){
            cout<<cost<<endl;
            return;
        }
    }
}
int main(){
    boost;

    //pre_cum();
    //prec(10);
	//fre;


    ll t=1;
    ll tc=1;
    cin>>t;

	while(t--){
		solve(tc);
        tc++;
    
	}

    return 0;
    
     
}