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
void dfs(ll x,ll y,ll px,ll py,vector<string> &a,set<vector<ll> > &vis,ll &f){

    //cout<<x<<" "<<y<<" "<<px<<" "<<py<<endl;
    if(x==1 and y==a[0].size()-1){
        f=1;
        return;
    }

    vis.insert({x,y,px,py});

    ll n=a[0].size();

    for(ll i=0;i<4;i++){
        ll nx=x+dx[i];
        ll ny=y+dy[i];
        if(nx>=0 and nx<2 and ny>=0 and ny<n){
            if(a[nx][ny]=='<'){
                ny--;
            }else{
                ny++;
            }

            if(vis.find({nx,ny,x,y})==vis.end()){
                dfs(nx,ny,x,y,a,vis,f);
            }
        }
    }


}
void solve(ll tc){ 


    ll n;
    cin>>n;

    vector<string> a(2);
    cin>>a[0]>>a[1];

    set<vector<ll> > vis;

    
    ll f=0;
    dfs(0,0,-1,-1,a,vis,f);





    if(f){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }

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