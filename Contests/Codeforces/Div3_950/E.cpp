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
vector<vector<ll> > get_row_sorted(vector<vector<ll> > &a,ll n,ll m){
    vector<vector<ll> > ret(n,vector<ll> (m));

    for(ll i=0;i<n;i++){
        vector<ll> curr;
        for(ll j=0;j<m;j++){
            curr.push_back(a[i][j]);
        }

        sort(all(curr));

        for(ll j=0;j<m;j++){
            ret[i][j]=curr[j];
        }
    }

    sort(all(ret));
    
    return ret;
}

vector<vector<ll> > get_col_sorted(vector<vector<ll> > &a,ll n,ll m){
    vector<vector<ll> > ret(n,vector<ll> (m));

    for(ll j=0;j<m;j++){
        vector<ll> curr;
        for(ll i=0;i<n;i++){
            curr.push_back(a[i][j]);
        }

        sort(all(curr));

        for(ll i=0;i<n;i++){
            ret[i][j]=curr[i];
        }
    }


    vector<vector<ll> > order;
    for(ll i=0;i<m;i++){
        order.push_back({ret[0][i],i});
    }
    sort(all(order));

    //sort(all(ret));
    vector<vector<ll> > sol(n,vector<ll> (m));

    for(ll j=0;j<m;j++){

        for(ll i=0;i<n;i++){

            sol[i][j]=ret[i][order[j][1]];
        }

    }


    return sol;
}


void solve(ll tc){
    ll n,m;
    cin>>n>>m;

    vector<vector<ll> > a(n,vector<ll> (m,0));
    vector<vector<ll> > b(n,vector<ll> (m,0));

    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++){
            cin>>a[i][j];
        }
    }

    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++){
            cin>>b[i][j];
        }
    }

    if(get_row_sorted(a,n,m) != get_row_sorted(b,n,m)){
        cout<<"NO"<<endl;
        return;
    }

    if(get_col_sorted(a,n,m) != get_col_sorted(b,n,m)){
        cout<<"NO"<<endl;
        return;
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