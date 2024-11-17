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
void do_op(ll x,ll y,vector<set<ll> >&adj,vector<ll> &deg,set<arr<ll,2> >&s){
    s.erase({deg[x],x});
    s.erase({deg[y],y});

    if(adj[x].find(y) != adj[x].end()){
        adj[x].erase(y);
        adj[y].erase(x);
        deg[x]--;
        deg[y]--;

    }else{

        adj[x].insert(y);
        adj[y].insert(x);
        deg[x]++;
        deg[y]++;
    }

    s.insert({deg[x],x});
    s.insert({deg[y],y});
}
void solve(ll tc){
    ll n,m;
    cin>>n>>m;

    vector<set<ll> > adj(n+1);
    vector<ll> deg(n+1,0);

    ll u,v;
    for(ll i=0;i<m;i++){
        cin>>u>>v;
        adj[u].insert(v);
        adj[v].insert(u);
        deg[u]++;
        deg[v]++;
    }

    set<arr<ll,2>  > s;
    for(ll i=1;i<=n;i++){
        s.insert({deg[i],i});
    }

    vector<vector<ll> > ops;

    while(s.size()>0){
        auto it=*(--s.end());
        if(it[0]<2){
            break;
        }

        vector<ll> verts;
        verts.pb(it[1]);
        for(auto to:adj[it[1]]){
            if(verts.size()==3){
                break;
            }
            verts.pb(to);
        }

        sort(all(verts));
        ops.pb(verts);
        for(ll i=0;i<3;i++){
            for(ll j=i+1;j<3;j++){
                ll x=verts[i];
                ll y=verts[j];

                do_op(x,y,adj,deg,s);


            }
        }
    }

    



    vector<arr<ll,2> > deg_2;
    vector<ll> deg_0;
    for(ll i=1;i<=n;i++){
        if(adj[i].size()==0){
            deg_0.pb(i);
        }
    }


    if(deg_0.size()==n){
        cout<<ops.size()<<endl;
        for(auto op:ops){
            cout<<op[0]<<" "<<op[1]<<" "<<op[2]<<endl;
        }

        return ;
    }

    

   


    for(ll i=1;i<=n;i++){
        if(adj[i].size()==1){
            ll x=*adj[i].begin();
            deg_2.pb({i,x});
            adj[x].erase(i);
        }
    }

    ll sz=deg_2.size();
    for(ll i=1;i<sz;i++){
        ops.pb({deg_2[0][0],deg_2[i][0],deg_2[i][1]});
    }


    ll x=deg_2[0][0],y=deg_2[0][1];
    while(deg_0.size()>0){
        ll ls=deg_0.back();
        deg_0.pop_back();

        ops.pb({ls,x,y});
        y=x;
        x=ls;
    }


    
    
    

    

    cout<<ops.size()<<endl;
    for(auto op:ops){
        cout<<op[0]<<" "<<op[1]<<" "<<op[2]<<endl;
    }




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