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
ll get_sum(ll x1,ll y1,ll x2,ll y2,vector<vector<ll> > &csum){
    return csum[x2][y2]-csum[x2][y1-1]-csum[x1-1][y2]+csum[x1-1][y1-1];
}

void solve(ll tc){
    ll n,m,k;
    cin>>n>>m>>k;


    vector<vector<ll> > a(n+1,vector<ll> (m+1));
    vector<vector<ll> > mountain(n+1,vector<ll> (m+1,0));
    vector<vector<ll> > csum_mountain(n+1,vector<ll> (m+1,0));

    
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=m;j++){
            cin>>a[i][j];
        }
    }

    ll diff=0;
    string s;
    for(ll i=1;i<=n;i++){
        cin>>s;
        for(ll j=1;j<=m;j++){
            mountain[i][j]=s[j-1]-'0';
            if(mountain[i][j]){
                diff+=a[i][j];
            }else{
                diff-=a[i][j];
            }
            csum_mountain[i][j]=(csum_mountain[i-1][j]+csum_mountain[i][j-1]-csum_mountain[i-1][j-1]+mountain[i][j]);
        }
    }

    

    ll gc=0;
    for(ll i=1;i+k-1<=n;i++){
        for(ll j=1;j+k-1<=m;j++){
            ll snow=get_sum(i,j,i+k-1,j+k-1,csum_mountain);
            ll without_snow=k*k-snow;
            //cout<<snow<<" "<<without_snow<<endl;
            gc=__gcd(gc,snow-without_snow);
        }
    }

   // cout<<diff<<" "<<gc<<endl;
    

    if(gc==0){
        if(diff==0){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
        return;
    }

    if(diff%gc==0){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
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