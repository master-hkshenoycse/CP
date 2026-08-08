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
ll get_values(vector<pair<ll,ll> >&v,ll c1, ll c2){

    ll ans=0;
    for(ll i=v.size()-1;i>=0;){
       if(i-1>=0 && v[i].ff==v[i-1].ff){
            ans+=v[i].ff;
            if(c1>c2){
                c1--;
            }else{
                c2--;
            }
            i-=2;
        }else{
            
            if(v[i].ss==1 && c1>0){
                ans+=v[i].ff;
                c1--;
            }

            if(v[i].ss==2  && c2>0){
                ans+=v[i].ff;
                c2--;
            }

            i--;
        }

        if(c1==0 && c2==0)
            break;
    }

    return ans;


}
void solve(ll tc){
    
    ll n,m,x,y;
    cin>>n>>m>>x>>y;

    vector<pair<ll,ll> >values;
    ll e;

    for(ll i=0;i<x;i++)
        cin>>e,values.pb({e,1});
    
    for(ll i=0;i<y;i++)
        cin>>e,values.pb({e,2});
    
    sort(values.begin(),values.end());
    cout<<max(get_values(values,n,m-1),get_values(values,n-1,m))<<endl;



    
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