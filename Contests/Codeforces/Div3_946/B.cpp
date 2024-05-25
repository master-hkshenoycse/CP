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

    string r;
    vector<ll> cnt(26,0);

    for(ll i=0;i<n;i++){
        cnt[s[i]-'a']++;
        if(cnt[s[i]-'a']==1){
            r+=s[i];
        }
    }

    sort(r.begin(),r.end());
    //cout<<r<<endl;
    ll sz=r.size();
    vector<ll> index_v(26);
    for(ll i=0;i<sz;i++){
        index_v[r[i]-'a']=i;
    }

    for(ll i=0;i<n;i++){
        ll ind_req=sz-index_v[s[i]-'a']-1;

        s[i]=r[ind_req];
    }

    cout<<s<<endl;
    

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