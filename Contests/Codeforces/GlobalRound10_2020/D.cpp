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

void solve(ll tc){ 

    ll n;
    cin>>n;
    
    string s;
    cin>>s;

    //only case of illogical player is when RRR,LLL occurs
    //so no occurences of 3 or more consecative same characters should be there
    //considering rounding the string;


    ll cnt=0,l=0,r=n-1;

    if(s[0]==s[n-1]){
        while(s[0]==s[l]){
            l++;
            cnt++;
        }

        //all the characters are same
        if(cnt==n){
            cout<<(n+2)/3<<endl;
            return;
        }

        while(s[n-1]==s[r]){
            r--;
            cnt++;
        }
    }

    ll ans=0;
    ans=ans+(cnt/3);


    while(l<=r){
        cnt=0;
        ll j=l;

        while(j<=r and s[j]==s[l]){
            cnt++;
            j++;
        }

        ans=ans+cnt/3;

        l=j;

    }

    cout<<ans<<endl;
}   
int main(){
    boost;

    //pre_cum();
    //prec(20);
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