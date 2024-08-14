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

    vector<ll> csum(n+1,0);

    for(ll i=1;i<=n;i++){
        cin>>csum[i];
        csum[i]+=csum[i-1];
    }

    set<ll> pos_r,pos_l;
    string s;
    cin>>s;

    for(ll i=0;i<n;i++){
        if(s[i]=='L'){
            pos_l.insert(i+1);
        }else{
            pos_r.insert(i+1);
        }
    }

    ll ans=0;
    while(pos_l.size()>0 and pos_r.size()>0){
        ll last_r=*(--pos_r.end());
        ll first_l=*pos_l.begin();

        if(first_l >last_r){
            break;
        }

        pos_r.erase(last_r);
        pos_l.erase(first_l);

        ans=ans+csum[last_r]-csum[first_l-1];
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