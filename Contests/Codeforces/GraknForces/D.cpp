#include<bits/stdc++.h>
#include <iterator>
#include <iostream>
#include <numeric>
#include <math.h>
#define ll int
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

    vector<arr<ll,2> > a(n),b(m);

    for(ll i=0;i<n;i++){
        cin>>a[i][0]>>a[i][1];
    }    

    for(ll i=0;i<m;i++){
        cin>>b[i][0]>>b[i][1];
    }

    vector<vector< arr<ll,2>  > > ops_req(n,vector<arr<ll,2> >(m));
    vector<vector< ll  > > suffix_req(n,vector<ll>(m+1,0));

    for(ll i=0;i<n;i++){

        for(ll j=0;j<m;j++){
            ops_req[i][j][0]=max(0,b[j][0]-a[i][0]+1);
            ops_req[i][j][1]=max(0,b[j][1]-a[i][1]+1);
        }

        sort(ops_req[i].begin(),ops_req[i].end());
        for(ll j=m-1;j>=0;j--){
            suffix_req[i][j]=max(suffix_req[i][j+1],ops_req[i][j][1]);
        }


    }

    ll ans=1e8;

    vector<ll> index_curr(n,0);
    vector<ll> index_cons;
    for(ll i=0;i<n;i++){
        index_cons.pb(i);
    }


    for(ll i=0;i<=1e6;i++){//do i operations of type i, and check suffix max y of remaining indexes
        ll ma=0;

        if(index_cons.size()==0){
            ans=min(ans,i);
            continue;
        }

        vector<ll> to_remove(index_cons.size(),0);
        ll sz=index_cons.size();

        for(ll j=0;j<sz;j++){
            ll ind=index_cons[j];
            while(index_curr[ind]<m and ops_req[ind][index_curr[ind]][0]<=i){
                index_curr[ind]++;
            }
            if(index_curr[ind]==m){
                to_remove[j]=1;
            }   
            ma=max(ma,suffix_req[ind][index_curr[ind]]);
        }

        ans=min(ans,i+ma);

        vector<ll> tmp;
        for(ll j=0;j<sz;j++){
            if(to_remove[j]==0){
                tmp.push_back(index_cons[j]);
            }
        }

        index_cons=tmp;
    }

    cout<<ans<<endl;


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