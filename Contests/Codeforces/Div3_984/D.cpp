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
    ll n,m;
    cin>>n>>m;
    vector<vector<ll> > a(n,vector<ll> (m));
    
    string s;
    for(ll i=0;i<n;i++){
        cin>>s;


        for(ll j=0;j<m;j++){
            a[i][j]=s[j]-'0';
        }
    }

    ll l=0,r=m-1,p=0,q=n-1;
    ll ans=0;
    while(l<=r and p<=q){
        vector<ll> seq;
        for(ll j=l;j<=r;j++){
            seq.pb(a[p][j]);
        }

        for(ll i=p+1;i<=q-1;i++){
            seq.pb(a[i][r]);
        }

        if(p!=q){
            for(ll j=r;j>=l;j--){
                seq.pb(a[q][j]);
            }
        }

        if(l!=r){
            for(ll i=q-1;i>=p+1;i--){
                seq.pb(a[i][l]);
            }
        }   

        ll sz=seq.size();

        for(ll i=0;i<seq.size();i++){
            if(seq[i]==1 and seq[(i+1)%sz]==5 and seq[(i+2)%sz]==4 and seq[(i+3)%sz]==3){
                ans++;
            }
        }

        l++;
        r--;
        p++;
        q--;

    }

    cout<<ans<<endl;
    
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