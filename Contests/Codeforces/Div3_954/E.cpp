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

    map<ll,vector<ll> > help;
    ll n,k;
    cin>>n>>k;

    ll e;

    for(ll i=1;i<=n;i++){
        cin>>e;
        help[e%k].push_back(e);
    }

    ll ans=0,cnt_od=0;
    for(auto it:help){
        vector<ll> tmp=it.second;
        sort(all(tmp));
        ll sz=tmp.size();
        if(sz%2){
            cnt_od++;
        }

        if(cnt_od>1){
            cout<<-1<<endl;
            return;
        }

        if(sz%2==0){
            for(ll i=0;i<sz;i+=2){
                ans=ans+(tmp[i+1]-tmp[i])/k;
            }
        }else{
            ll tot_min=1e18;
            
            ll cs=0;
            vector<ll> prefix(sz,0),suffix(sz,0);
            for(ll i=1;i<sz;i+=2){
                cs=cs+(tmp[i]-tmp[i-1])/k;
                prefix[i]=cs;
            }

            cs=0;
            for(ll i=sz-2;i>=0;i-=2){
                 cs=cs+(tmp[i+1]-tmp[i])/k;
                 suffix[i]=cs;
            }

            for(ll i=0;i<sz;i++){
                if(i%2==0){
                    ll x=0;
                    if(i-1>=0)x+=prefix[i-1];
                    if(i+1<sz)x+=suffix[i+1];
                    tot_min=min(tot_min,x);
                }else{
                    ll x=0;
                    if(i-2>=0)x+=prefix[i-2];
                    if(i+2<sz)x+=suffix[i+2];
                    if(i-1>=0 and i+1<sz){
                        x+=(tmp[i+1]-tmp[i-1])/k;
                    }
                    tot_min=min(tot_min,x);
                }
            }

            ans+=tot_min;

        }

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