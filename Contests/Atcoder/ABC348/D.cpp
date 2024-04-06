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
    ll h,w;
    cin>>h>>w;

    vector<vector<ll> > grid(h,vector<ll> (w,0));
    vector<vector<ll> > dp(h,vector<ll> (w,-1));
    char ch;
    ll sx,sy,ex,ey;
    for(ll i=0;i<h;i++){
        for(ll j=0;j<w;j++){            
            cin>>ch;
            if(ch=='S'){
                sx=i;
                sy=j;
            }else if(ch=='T'){
                ex=i;
                ey=j;
            }else if(ch=='#'){
                grid[i][j]=-1;
            }
        }
    }

    ll n;
    cin>>n;

    ll x,y,e;
    for(ll i=0;i<n;i++){
        
        cin>>x>>y>>e;
        grid[x-1][y-1]=e;
    }

    //do dijstra for reaching a node with max possible energy

    ll dx[4]={-1,1,0,0};
    ll dy[4]={0,0,-1,1};

    priority_queue<vector<ll> >pq;
    pq.push({grid[sx][sy],sx,sy});
    dp[sx][sy]=grid[sx][sy];

    while(pq.size()>0){
        ll x=pq.top()[1];
        ll y=pq.top()[2];
        ll e_curr=pq.top()[0];

        if(x==ex and y==ey){
            cout<<"Yes"<<endl;
            return;
        }

        pq.pop();



        if(e_curr==0){
            continue;   
        }

        //cout<<e_curr<<" "<<x<<" "<<y<<endl;
        

        for(ll i=0;i<4;i++){
            ll nx=x+dx[i];
            ll ny=y+dy[i];
            if(nx>=0 and nx<h and ny>=0 and ny<w and grid[nx][ny]>=0){
                ll e_next=max(grid[nx][ny],e_curr-1);
                if(e_next>=0 and e_next>dp[nx][ny]){
                    dp[nx][ny]=e_next;
                    pq.push({e_next,nx,ny});
                    
                }
            }
        }
    }

    cout<<"No"<<endl;

     
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