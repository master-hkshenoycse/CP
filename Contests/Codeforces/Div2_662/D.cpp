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

    vector<vector<char> > a(n+1,vector<char> (m+1));
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=m;j++){
            cin>>a[i][j];
        }
    }


    vector<vector<ll> > up_(n+1,vector<ll> (m+1,1)),down_(n+1,vector<ll> (m+1,1));
    vector<ll> L(m+1),R(m+1);
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=m;j++){
            if(i-1>=1 and a[i-1][j]==a[i][j]){
                up_[i][j]+=up_[i-1][j];
            }
        }
    }

    for(ll i=n;i>=1;i--){
        for(ll j=m;j>=1;j--){
            if(i+1<=n and a[i+1][j]==a[i][j]){
                down_[i][j]+=down_[i+1][j];
            }
        }
    }


    ll ans=0;

    for(ll i=1;i<=n;i++){
        ll j=1;

        //L stores the left endpoint of rhombus if center is at some j
        //R stores the right endpoint of rhobmus if center is at some j

        while(j<=m){
            ll k=j;
            while(k<=m and a[i][j]==a[i][k]){
                k++;
            }

            for(ll pos=j;pos<k;pos++){
                if(pos==j){
                    L[pos]=pos;
                }else{
                    L[pos]=max(L[pos-1],pos-min(up_[i][pos],down_[i][pos])+1);
                }
            }
            j=k;
        }
        
        j=m;
        while(j>=1){
            ll k=j;
            while(k<=m and a[i][j]==a[i][k]){
                k--;
            }

            for(ll pos=j;pos>k;pos--){
                if(pos==j){
                    R[pos]=pos;
                }else{
                    R[pos]=min(R[pos+1],pos+min(up_[i][pos],down_[i][pos])-1);
                }
            }
            j=k;
        }

        for(ll j=1;j<=m;j++){
            ans=ans+min(j-L[j]+1,R[j]-j+1);
        }
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