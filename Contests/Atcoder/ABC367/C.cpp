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
void rec(ll ind,vector<ll> &range,ll k,ll sum,vector<ll> &curr,vector<vector<ll> > &sol){
    if(ind==range.size()){
        if(sum%k==0){
            sol.push_back(curr);
        }
        return;
    }

    for(ll i=1;i<=range[ind];i++){
        curr.push_back(i);
        rec(ind+1,range,k,sum+i,curr,sol);
        curr.pop_back();
    }
}
void solve(ll tc){
    
    ll n,k;
    cin>>n>>k;

    vector<ll> range(n);
    for(ll i=0;i<n;i++){
        cin>>range[i];
    }


    vector<vector<ll> > sol;
    vector<ll> curr;

    rec(0,range,k,0,curr,sol);

    sort(all(sol));

    for(auto s:sol){
        for(auto e:s){
            cout<<e<<" ";
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