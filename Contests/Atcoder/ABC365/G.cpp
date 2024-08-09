#include<bits/stdc++.h>
#include <iterator>
#include <iostream>
#include <numeric>
#include <math.h>
#define ll int
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

    ll block=sqrt(m);
    vector<ll> t(m+1);
    vector<ll> p(m+1);
    vector<vector<ll> > events(n+1);
    vector<ll> is_heavy(n+1,0);


    for(ll i=1;i<=m;i++){
        cin>>t[i]>>p[i];
        events[p[i]].push_back(i);
    }


    map<ll,map<ll,ll> > heavy_precompute;

    vector<ll> sum(m+1,0);
    for(ll i=1;i<=n;i++){
        if(events[i].size()>=block){

            is_heavy[i]=1;

            
            ll active=0;

            for(ll j=1;j<=m;j++){
                sum[j]=sum[j-1];

                if(active){
                    sum[j]+=(t[j]-t[j-1]);
                }

                if(p[j]==i){
                    active=1-active;
                }
            }


            for(ll j=1;j<=n;j++){
                ll total_intersect=0;
                for(ll k=0;k<events[j].size();k+=2){
                    total_intersect+=(sum[events[j][k+1]]-sum[events[j][k]]);
                }
                heavy_precompute[i][j]=total_intersect;
            }

            for(ll j=1;j<=m;j++){
                sum[j]=0;
            }

        }
    }

    ll q;
    cin>>q;


    while(q--){
        ll a,b;
        cin>>a>>b;

        if(is_heavy[a]){
            cout<<heavy_precompute[a][b]<<endl;
        }else if(is_heavy[b]){
            cout<<heavy_precompute[b][a]<<endl;
        }else{

            ll a_active=0,b_active=0;
            ll ans=0;
            ll p=0,q=0,l=0;
            while(p<events[a].size() and q<events[b].size()){
                if(events[a][p]<events[b][q]){
                    if(a_active and b_active){
                        ans=ans+t[events[a][p]]-t[l];
                    }

                    l=events[a][p];
                    p++;
                    a_active=1-a_active;


                }else{

                    if(a_active and b_active){
                        ans=ans+t[events[b][q]]-t[l];
                    }

                    l=events[b][q];
                    q++;
                    b_active=1-b_active;

                }
            }

            cout<<ans<<endl;

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
    //cin>>t;

	while(t--){
		solve(tc);
        tc++;
    
	}

    return 0;
    
     
}