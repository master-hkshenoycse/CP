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

    vector<ll> dp(n,1);

    set<string> curr;
    for(ll i=1;i<n;i++){
        dp[i]=dp[i-1]+1;
        ll ex=0;
        string c;
        c+=s[i-1];
        c+=s[i];
        
        if(i-2>=0){
            ex=dp[i-2];
        }

        if(curr.find(c) != curr.end()){
            dp[i]=min(dp[i],ex+1);
        }

        if(i-2>=0){
            string c;
            c+=s[i-2];
            c+=s[i-1];
            curr.insert(c);
        }


    }   

    if(dp[n-1]<n){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
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
