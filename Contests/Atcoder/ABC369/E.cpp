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

ll get_solution(ll src,ll dest,vector<vector<ll> >&dp,vector<ll> &edge_list,vector<ll>&u,vector<ll> &v,vector<ll> &d){

    ll sz=edge_list.size();    
    ll ans=1e18;

    do{
        vector<vector<ll> > edge_dp(sz,vector<ll> (2,1e18));
        //dp[i][0] means used ith edges and start at u[ind] and end at v[ind] , where ind=edges_list[i].
        //dp[i][1] means used ith edges and start at v[ind] and end at u[ind] , where ind=edges_list[i].
        edge_dp[0][0]=dp[src][u[edge_list[0]]]+d[edge_list[0]];
        edge_dp[0][1]=dp[src][v[edge_list[0]]]+d[edge_list[0]];

        for(ll i=1;i<sz;i++){
            ll ind=edge_list[i];
            ll prev_ind=edge_list[i-1];

            edge_dp[i][0]=min(edge_dp[i-1][0]+dp[v[prev_ind]][u[ind]],edge_dp[i-1][1]+dp[u[prev_ind]][u[ind]])+d[ind];
            edge_dp[i][1]=min(edge_dp[i-1][0]+dp[v[prev_ind]][v[ind]],edge_dp[i-1][1]+dp[u[prev_ind]][v[ind]])+d[ind];

        }

        ans=min(ans,edge_dp[sz-1][0]+dp[v[edge_list[sz-1]]][dest]);
        ans=min(ans,edge_dp[sz-1][1]+dp[u[edge_list[sz-1]]][dest]);

    }while(next_permutation(all(edge_list)));

    return ans;
}
void solve(ll tc){
    ll n,m;
    cin>>n>>m;

    vector<ll> u(m+1),v(m+1),d(m+1);
    vector<vector<ll> > dp(n+1,vector<ll> (n+1,1e18));

    for(ll i=1;i<=m;i++){
        cin>>u[i]>>v[i]>>d[i];

        dp[u[i]][v[i]]=min(dp[u[i]][v[i]],d[i]);
        dp[v[i]][u[i]]=min(dp[v[i]][u[i]],d[i]);
    }

    for(ll i=1;i<=n;i++){
        dp[i][i]=0;
    }

    for(ll k=1;k<=n;k++){
        for(ll i=1;i<=n;i++){
            for(ll j=1;j<=n;j++){
                dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
            }
        }
    }

    ll q;
    cin>>q;
    
    while(q--){
        ll sz;
        cin>>sz;

        vector<ll> edge_list(sz);
        for(ll i=0;i<sz;i++){
            cin>>edge_list[i];
        }
        
        cout<<get_solution(1,n,dp,edge_list,u,v,d)<<endl;
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