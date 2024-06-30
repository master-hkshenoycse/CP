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
    string a,b;
    cin>>a>>b;

    ll n=a.size(),m=b.size();
    ll sub=0;

    vector<ll> ind_ch[26];
    for(ll i=0;i<n;i++){
        ind_ch[a[i]-'a'].pb(i);
    }
    for(ll i=0;i<m;i++){
        ll cnt=0;
        ll prev=-1;
        for(ll j=i;j<m;j++){
            auto nx=upper_bound(all(ind_ch[b[j]-'a']),prev);
            if(nx==ind_ch[b[j]-'a'].end()){
                break;
            }else{
                prev=*nx;
                cnt++;
            }

        }
        sub=max(sub,cnt);
    }

    

    cout<<n+m-sub<<endl;

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