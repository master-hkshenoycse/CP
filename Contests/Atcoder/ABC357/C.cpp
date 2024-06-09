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
ll get_sz(ll n){
    ll sz=1;
    for(ll i=1;i<=n;i++){
        sz=sz*3;
    }
    return sz;
}

void fill_all(ll x,ll y,ll len,vector<vector<char> > &sol){
    for(ll i=0;i<len;i++){
        for(ll j=0;j<len;j++){
            sol[x+i][j+y]='.';
        }
    }
}
void fill_rec(ll x,ll y,ll level,vector<vector<char> > &sol){
    if(level==0){
        sol[x][y]='#';
        return ;
    }

    ll len_each=get_sz(level-1);

    for(ll i=0;i<3;i++){
        for(ll j=0;j<3;j++){

            if(i==1 and j==1){
                fill_all(x+i*len_each,y+j*len_each,len_each,sol);
            }else{
                fill_rec(x+i*len_each,y+j*len_each,level-1,sol);
            }
        }
    }

}
void solve(ll tc){
    ll n;
    cin>>n;

    ll sz=get_sz(n);

    vector<vector<char> > sol(sz,vector<char> (sz));
    fill_rec(0,0,n,sol);

    for(ll i=0;i<sz;i++){
        for(ll j=0;j<sz;j++){
            cout<<sol[i][j];
        }
        cout<<endl;
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