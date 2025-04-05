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

    string s;
    vector<vector<ll> > a(n,vector<ll> (m,0));
    vector<vector<ll> > row_sum(n,vector<ll> (m,0));
    vector<vector<ll> > col_sum(n,vector<ll> (m,0));

    for(ll i=0;i<n;i++){
        cin>>s;

        for(ll j=0;j<m;j++){
            a[i][j]=s[j]-'0';
            
            row_sum[i][j]=a[i][j];
            col_sum[i][j]=a[i][j];

            if(j>0){
                row_sum[i][j]+=row_sum[i][j-1];
            }

            if(i>0){
                col_sum[i][j]+=col_sum[i-1][j];
            }
        }

    }

    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++){
            if(a[i][j]==1){
                ll f=0;
                if(row_sum[i][j]==j+1 || col_sum[i][j]==i+1){
                    f=1;
                }


                if(f==0){
                    cout<<"NO"<<endl;
                    return;
                }

            }
        }
    }

    cout<<"YES"<<endl;
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