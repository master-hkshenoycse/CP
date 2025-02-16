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

    ll ans=1e18;


    vector<ll> one_pos;
    for(ll i=0;i<n;i++){
        if(s[i]=='1'){
            one_pos.push_back(i);
        }
    }

    ll tot_ones=one_pos.size();
    for(ll i=1;i<tot_ones;i++){
        one_pos[i]+=one_pos[i-1];
    }

    ll c1=0;

    for(ll i=0;i<n;i++){
        if(s[i]=='1'){
            c1++;
        }

        ll ones_before=c1;
        ll ones_after=tot_ones-c1;

        ll tot=0;
        if(ones_before>0){
            tot+=i*ones_before-(ones_before*(ones_before-1))/2ll;
            tot-=one_pos[c1-1];
        }

        if(ones_after > 0){
            tot+=(one_pos.back());
            if(ones_before>0){
                tot-=one_pos[ones_before-1];
            }
            tot-=(i*ones_after+(ones_after*(ones_after+1))/2ll);

        }

        ans=min(ans,tot);
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
    //cin>>t;

	while(t--){
		solve(tc);
        tc++;
    
	}

    return 0;
    
     
}