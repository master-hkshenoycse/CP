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
ll get_par(ll v,vector<ll> &par){
    if(par[v]==v)return v;
    return get_par(par[v],par);
}

set<ll> merge(set<ll>  &a, set<ll> &b){
    set<ll> c;
    for(auto e:a){
        c.insert(e);
    }

    for(auto e:b){
        c.insert(e);
    }

    while(c.size()>12){
        
        c.erase(--c.end());
    }

    return c;

}

void do_dsu(ll x,ll y,vector<ll> &par,vector<ll> &sz,vector<set<ll> >&conn){
    ll px=get_par(x,par);
    ll py=get_par(y,par);
    if(px==py){
        return;
    }


    if(sz[px]>sz[py]){
        swap(px,py);
    }

    par[px]=py;
    sz[py]+=sz[px];
    sz[px]=0;
    conn[py]=merge(conn[px],conn[py]);
}
void solve(ll tc){

    
    ll n,q;
    cin>>n>>q;

    vector<ll> par(n+1),sz(n+1);
    vector<set<ll> >conn (n+1);

    for(ll i=1;i<=n;i++){
        par[i]=i;
        sz[i]=1;
        conn[i].insert(-i);
    }


    ll ty,u,v;

    while(q--){
        cin>>ty;
        if(ty==1){
            cin>>u>>v;
            do_dsu(u,v,par,sz,conn);
        }else{
            cin>>u>>v;

            vector<ll> adj;
            ll pu=get_par(u,par);

            for(auto e:conn[pu]){
                adj.pb(-e);

            }



            ll ans=-1;
            ll req=v;
            for(auto e:adj){
               
                req--;
                if(req==0){
                    ans=e;
                    break;
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