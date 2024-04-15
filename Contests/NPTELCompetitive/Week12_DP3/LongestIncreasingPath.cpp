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
ll dx[4]={-1,1,0,0};
ll dy[4]={0,0,-1,1};

ll get_longest_path(vector<vector<ll> > &a,ll n,ll m){
    
    vector<ll> in_deg(n*m,0);
    vector<ll> dp(n*m,1);
    vector<vector<ll> > adj(n*m);

    ll ans=1;

    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++){

            for(ll k=0;k<4;k++){
                ll ni=i+dx[k];
                ll nj=j+dy[k];
                if(ni>=0 and ni<n and nj>=0 and nj<m and a[ni][nj]<a[i][j]){
                    in_deg[ni*m+nj]++;
                    adj[i*m+j].push_back(ni*m+nj);
                }
            }
        }
    }
    queue<ll> q;

    for(ll i=0;i<n*m;i++){
        if(in_deg[i]==0){
            q.push(i);
        }
    }

    while(q.size()>0){
        ll v=q.front();
        q.pop();
        ans=max(ans,dp[v]);

        for(auto to:adj[v]){
            dp[to]=max(dp[to],dp[v]+1);
            in_deg[to]--;

            if(in_deg[to]==0){
                q.push(to);
            }
        }
    }

    return ans;
}
void solve(ll tc){
    ll n,m;
    cin>>n>>m;

    vector<vector<ll> > a(n,vector<ll> (m));

    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++){
            cin>>a[i][j];
        }
    }

    ll path_a=get_longest_path(a,n,m);



    for(ll j=0;j<m;j++){
        for(ll i=0;i<n;i++){
            cin>>a[i][j];
        }
    }

    ll path_b=get_longest_path(a,n,m);

    if(path_a>path_b){
        cout<<1<<endl;
    }else if(path_a<path_b){
        cout<<-1<<endl;
    }else{
        cout<<0<<endl;
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