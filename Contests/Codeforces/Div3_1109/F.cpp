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

vector<ll> dfs(ll v,ll p, vector<vector<ll> > &adj,vector<ll> &val){
    
    vector<ll> ret(4);
    ret[3]=0;

    vector<vector<ll> > segs;
    for(auto to:adj[v]){
        if(to==p){
            continue;
        }
        segs.push_back(dfs(to,v,adj,val));
    }


    sort(segs.begin(),segs.end());

    ll f=1,cnt_leaf=0,mi_nx=1e18,ma_nx=-1e18;
    for(auto s:segs){
        cnt_leaf+=s[2];
        mi_nx=min(mi_nx,s[0]);
        ma_nx=max(ma_nx,s[1]);
        f&=s[3];
    }

    if(segs.size()==0){
        ret[0]=val[v];
        ret[1]=val[v];
        ret[2]=1;
        ret[3]=1;
    }else{
        
        if(ma_nx-mi_nx+1!=cnt_leaf)
            f=0;
        
        ret[0]=mi_nx;
        ret[1]=ma_nx;
        ret[2]=cnt_leaf;
        ret[3]=f;
    }


    return ret;
}
void solve(ll tc){
    ll n;
    cin>>n;

    vector<vector<ll> >adj(n+1);
    ll x,y;
    for(ll i=1;i<=n-1;i++){
        cin>>x>>y;
        adj[x].pb(y);
        adj[y].pb(x);
    }

    vector<ll> val(n+1);
    for(ll i=1;i<=n;i++)    
        cin>>val[i];
    
    if(dfs(1,0,adj,val)[3])
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
    
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