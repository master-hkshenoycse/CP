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

    vector<ll> a(n+1),b(n+1);
    vector<ll> dp(n+1);

    for(ll i=1;i<=n;i++){
        cin>>a[i];
        dp[i]=a[i];
    }

    for(ll i=1;i<=n;i++){
        cin>>b[i];
    }

    ll ans=0;
    vector<vector<ll> > adj(n+1);
    vector<ll> in_deg(n+1);
    

    for(ll i=1;i<=n;i++){
        if(b[i] != -1){
            adj[i].pb(b[i]);
            in_deg[b[i]]++;
        }
    }

    queue<ll> q;
    for(ll i=1;i<=n;i++){
        if(in_deg[i]==0){
            q.push(i);
        }
    }

    vector<vector<ll> > op_adj(n+1);
    vector<ll> in_deg_op(n+1,0);


    while(q.size()>0){
        ll v=q.front();
        q.pop();
        ans=ans+dp[v];
        for(auto to:adj[v]){
            
            if(dp[to]>dp[to]+dp[v]){
                op_adj[to].pb(v);
                in_deg_op[v]++;
            }else{
                op_adj[v].pb(to);
                in_deg_op[to]++;
            }

            dp[to]=max(dp[to],dp[to]+dp[v]);
            in_deg[to]--;
            if(in_deg[to]==0){
                q.push(to);
            }
        }
    }

    for(ll i=1;i<=n;i++){
        if(in_deg_op[i]==0){
            q.push(i);
        }
    }
    cout<<ans<<endl;

    while(q.size()>0){
        ll v=q.front();
        q.pop();
        cout<<v<<" ";

        for(auto to:op_adj[v]){
            in_deg_op[to]--;
            if(in_deg_op[to]==0){
                q.push(to);
            }
        }
    }

    cout<<endl;

    








    
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