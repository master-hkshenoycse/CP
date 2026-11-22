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
void dfs(int ind,int x,int y,string &s,set<vector<int> > &vis,int &ans){
    ans=max(ans,x+y);
 
    if(ind==s.size())
        return;

    vector<int> state={ind,x,y};
    if(vis.find(state) != vis.end() ) return;
    vis.insert(state);

    if(s[ind] == '+'){
        if(y>0)dfs(ind+1,x,y+1,s,vis,ans);
        if(x>0)dfs(ind+1,x-1,y+1,s,vis,ans);
    }else{
        if(x>0)dfs(ind+1,x-1,y,s,vis,ans);
        if(y>0)dfs(ind+1,x+1,y-1,s,vis,ans);
    }
}
void solve(ll tc){
    
    ll x,y,m;
    cin>>x>>y>>m;

    string s;
    cin>>s;

    int ans=0;
    set<vector<int> > vis;
    dfs(0,x,y,s,vis,ans);
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