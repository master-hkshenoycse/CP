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

    ll n,k;
    cin>>n>>k;

    vector<ll> c(n+1),v(n+1);

    for(ll i=1;i<=n;i++){
        cin>>c[i]>>v[i];
    }



    vector< vector< pair<ll,ll> > > dp(k+1); 
    vector< vector<pair<ll,ll> >  >tmp(k+1);

    dp[0].push_back({0,0});
    dp[0].push_back({-1e18,-1});



    for(ll i=1;i<=n;i++){

        //ith ball and j balls have been removed;
        

        for(ll j=0;j<=k;j++){

            tmp[j].clear();
           //ith ball is not removed,then the last color will be c(i)
           
            for(auto p:dp[j]){
               if(p.second != c[i] and p.first>=0){
                tmp[j].push_back({p.first+v[i],c[i]});
               }
            }


            //ith ball is removed
            if(j>0){
                for(auto p:dp[j-1]){
                    if(p.first>=0){
                        tmp[j].push_back(p);
                    }
                }
            }

            tmp[j].push_back({-1e18,-1});

            sort(all(tmp[j]));

            reverse(all(tmp[j]));

            vector<pair<ll,ll> > tmp_p;
            tmp_p.pb(tmp[j][0]);

            for(ll o=1;o<tmp[j].size();o++){
                if(tmp[j][o].second != tmp[j][0].second){
                    tmp_p.pb(tmp[j][o]);
                    break;
                }
            }

            tmp[j]=tmp_p;
        }

        /*for(ll j=0;j<=k;j++){
            for(auto p:dp[i][j]){
                //cout<<i<<" "<<j<<" "<<p.first<<" "<<p.second<<endl;
            }
        }*/
        //cout<<endl;
        dp=tmp;
    }

    ll ans=dp[k][0].first;
    
    if(dp[k].size()>1){
        ans=max(ans,dp[k][1].first);
    }

    if(ans<0){
        ans=-1;
    }

    cout<<ans<<endl;



}
int main(){
    boost;

    //pre_cum();
    //prec(20);
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