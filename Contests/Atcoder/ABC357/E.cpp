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

    vector<ll> f(n+1);
    vector<ll> vis(n+1,0);
    vector<ll> in_deg(n+1);
    vector<ll> in_cycle(n+1,0);
    vector<ll> cycle_len(n+1,0);

    ll x;
    for(ll i=1;i<=n;i++){
        cin>>f[i];
        in_deg[f[i]]++;    
    }
    ll ans=0;
    for(ll i=1;i<=n;i++){
        
        if(in_deg[i]==0){

            ll st=i,len_tot=0;
            while(vis[st]==0 and in_cycle[st]==0){
                len_tot++;
                vis[st]=1;
                st=f[st];
            }

            if(in_cycle[st]==1){
                ans=ans+len_tot*cycle_len[st];
                ans=ans+(len_tot*len_tot-len_tot)/2ll;
                continue;
            }



            ll cycle_start=f[st];
            vector<ll> curr_cycle;
            curr_cycle.pb(st);

            while(cycle_start != st){
                curr_cycle.pb(cycle_start);
                cycle_start=f[cycle_start];
            }

            ll cycle_sz=curr_cycle.size();
            ans=ans+cycle_sz*(cycle_sz-1);
            cout<<len_tot<<" "<<cycle_sz<<endl;
            len_tot-=cycle_sz;
            ans=ans+(len_tot)*cycle_sz;
            ans=ans+(len_tot*len_tot-len_tot)/2ll;

            for(auto ch:curr_cycle){
                cout<<ch<<endl;
                in_cycle[ch]=1;
                cycle_len[ch]=cycle_sz;
            }

            

        }
    }

    cout<<ans+n<<endl;

    

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