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

    vector<vector<ll> > p(n+1,vector<ll> (n+1));
    vector<vector<ll> >r(n+1,vector<ll> (n+1));
    vector<vector<ll> >d(n+1,vector<ll> (n+1));

    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=n;j++){
            cin>>p[i][j];
        }
    } 

    for(ll i=1;i<=n;i++){
        for(ll j=1;j+1<=n;j++){
            cin>>r[i][j];
        }
    }

    for(ll i=1;i+1<=n;i++){
        for(ll j=1;j<=n;j++){
            cin>>d[i][j];
        }
    }

    vector<vector<ll> > cost(n+1,vector<ll> (n+1,1e18));//minimum time to reach (i,j) such that money is never <=0
    vector<vector<ll> > money(n+1,vector<ll> (n+1,0));//maximum money remaing given it has reached (i,j) in mimumm possible moves
    cost[1][1]=0;

    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=n;j++){
            vector<vector<ll> > tmp(n-i+1,vector<ll> (n-j+1,1e18));
            tmp[0][0]=0;

            //from (i,j) calculate the miniumum cost and max money to (ni,nj)

            for(ll ni=i;ni<=n;ni++){
                for(ll nj=j;nj<=n;nj++){
                    
                    ll dx=ni-i;
                    ll dy=nj-j;


                    if(dx==0 and dy==0){
                        continue;
                    }

                    if(dx==0){
                        tmp[dx][dy]=tmp[dx][dy-1]+r[ni][nj-1];
                    }else if(dy==0){    
                        tmp[dx][dy]=tmp[dx-1][dy]+d[ni-1][nj];
                    }else{  
                        tmp[dx][dy]=min(tmp[dx][dy-1]+r[ni][nj-1],tmp[dx-1][dy]+d[ni-1][nj]);
                    }

                    ll extra_req=max(0ll,tmp[dx][dy]-money[i][j]);
                    ll wait=(extra_req+p[i][j]-1)/p[i][j]; //time required to gain the extra money
                    ll value=wait+dx+dy+cost[i][j];
                    ll money_rem=wait*p[i][j]+money[i][j]-tmp[dx][dy];

                    if(value < cost[ni][nj]){
                        cost[ni][nj]=value;
                        money[ni][nj]=money_rem;
                    }else if(value==cost[ni][nj]){
                        money[ni][nj]=max(money[ni][nj],money_rem);
                    }
                }
            }
        }
    }

    cout<<cost[n][n];


    

 



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