/*https://codeforces.com/contest/1278/problem/D*/
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
void dfs(ll v,vector<ll> &vis,vector<vector<ll> >&adj,ll &cnt){
    vis[v]=1;
    cnt++;
    for(auto to:adj[v]){
        if(vis[to]){
            continue;
        }
        dfs(to,vis,adj,cnt);
    }
}
void solve(ll tc){
    //run until n-1 edges are formed

    ll n;
    cin>>n;

    vector<arr<ll,2> > events;
    vector<ll> l(n+1),r(n+1);
    for(ll i=1;i<=n;i++){
        cin>>l[i]>>r[i];
        events.pb({l[i],i});
        events.pb({r[i],i});
    }


    sort(all(events));

    set<arr<ll,2> > curr;

    vector<vector<ll> > adj(n+1);
    vector<ll> vis(n+1,0);
    ll edg_cnt=0;

    for(auto e:events){
        
        if(edg_cnt>=n){
            break;
        }

        if(curr.find(e) != curr.end()){
            curr.erase(e);
        }else{

            ll ind=e[1];
            ll en=r[ind];

            for(auto c:curr){
                if(c[0]>en){
                    break;
                }

                //cout<<c[1]<<" "<<e[1]<<endl;
                edg_cnt++;
                //all open and not completrlet covering intervals
                adj[c[1]].push_back(e[1]);
                adj[e[1]].push_back(c[1]);
            }

            curr.insert({en,ind});
        }
    }

    ll cnt=0;
    dfs(1,vis,adj,cnt);
    if(cnt==n and edg_cnt==n-1){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
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