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
/*https://codeforces.com/contest/1926/submission/248892021*/

//dp[i][0]= min total sheets such that node i is a type party
//dp[i][1]= min total sheets such that node i is a type silence
//dp[i][2]= min total sheets such that node i is a type don't care


void dfs(ll v,ll p,vector<vector<ll> >&adj,vector<vector<ll> >&dp,string &s){

    
    char ch=s[v-1];
    ll cost_s=0,cost_p=0,cost_c=0;
    

    for(auto to:adj[v]){
        
        if(to==p){
            continue;
        }

        dfs(to,v,adj,dp,s);

        cost_p=cost_p+min(dp[to][1]+1,min(dp[to][0],dp[to][2]));
        cost_s=cost_s+min(dp[to][0]+1,min(dp[to][1],dp[to][2]));
        cost_c=cost_c+min(dp[to][0]+1,min(dp[to][1]+1,dp[to][2]));

    }

    if(ch=='P'){
        dp[v][0]=cost_p;
    }else if(ch=='S'){
        dp[v][1]=cost_s;
    }else{    
        dp[v][0]=cost_p;
        dp[v][1]=cost_s; 
        dp[v][2]=cost_c;
    }



    
    
}
void solve(ll tc){ 
    ll n;
    cin>>n;

    ll p;   
    vector<vector<ll> > adj(n+1),dp(n+1,vector<ll> (3,1e9));
    for(ll i=2;i<=n;i++){
        cin>>p;
        adj[p].pb(i);
        adj[i].pb(p);
    }

    string s;
    cin>>s;


    
    dfs(1,-1,adj,dp,s);

    cout<<min(dp[1][0],min(dp[1][1],dp[1][2]))<<endl;


}
int main(){
    boost;

    //pre_cum();
    //prec(20);
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