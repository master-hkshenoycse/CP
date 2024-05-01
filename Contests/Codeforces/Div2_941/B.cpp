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
    
    ll n,m;
    cin>>n>>m;

    vector<vector<char> > a(n,vector<char> (m));
    ll min_x_w=n,max_x_w=-1,min_y_w=m,max_y_w=-1;
    ll min_x_b=n,max_x_b=-1,min_y_b=m,max_y_b=-1;
    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++){
            cin>>a[i][j];
            if(a[i][j]=='B'){
                min_x_b=min(min_x_b,i);
                max_x_b=max(max_x_b,i);
                min_y_b=min(min_y_b,j);
                max_y_b=max(max_y_b,j);
            }else{
                min_x_w=min(min_x_w,i);
                max_x_w=max(max_x_w,i);
                min_y_w=min(min_y_w,j);
                max_y_w=max(max_y_w,j);
            }
        }
    }

    //if W is in each of extreme ends
    if(min_x_w==0 and max_x_w==n-1 and min_y_w==0 and max_y_w==m-1){
        cout<<"YES"<<endl;
        return;
    }

    //if B is in each of extreme ends
    if(min_x_b==0 and max_x_b==n-1 and min_y_b==0 and max_y_b==m-1){
        cout<<"YES"<<endl;
        return;
    }

    cout<<"NO"<<endl;

    

    
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