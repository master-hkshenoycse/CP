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

void dfs(ll v,ll p,vector<vector<ll> >&adj,map<ll,ll> &hash,map<vector<ll>,ll> &children_hash,ll &value){

    vector<ll> children;
    for(auto to:adj[v]){
        if(to==p){
            continue;
        }
        dfs(to,v,adj,hash,children_hash,value);
        children.push_back(hash[to]);
    }

    if(children_hash.find(children)==children_hash.end()){
        value++;
        children_hash[children]=value;
    }
    
    hash[v]=children_hash[children];
    //cout<<v<<" "<<hash[v]<<endl;

}
void solve(ll tc){
    ll n;
    cin>>n;
    
    string s;
    cin>>s;



    vector<vector<ll> > adj(n/2);
    vector<ll> parent(n/2);
    ll prev=-1;
    ll lst=0,curr=-1;
    
    for(ll i=0;i<n;i++){
        if(s[i]=='('){
            if(curr != -1){
                lst++;
                //cout<<i<<" "<<curr<<" "<<lst<<endl;
                adj[curr].pb(lst);
                adj[lst].pb(curr);

                parent[lst]=curr;
            }
            

            curr=lst;

            
        }else{
            curr=parent[curr];
        }
    }

    //cout<<endl;
    map<ll,ll> hash;
    map<vector<ll>,ll> children_hash;
    ll value=0;

    //tree hash

    dfs(0,-1,adj,hash,children_hash,value);

    ll ans=0;

    //count values
    map<ll,ll> cnt;
    for(auto it:hash){
        cnt[it.ss]++;
    }
    for(auto it:cnt){
        ans=ans+(it.ss*it.ss-it.ss)/2ll;
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