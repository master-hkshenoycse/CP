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
    ll n,q;
    cin>>n>>q;

    vector<ll> csum(q+2,0);
    
    vector<ll> index_req[n+1];
    //mark the indices where parity of elements chaged
    //get the value of updates b y cumilative sun on size of set 


    set<ll> curr;
    ll e;
    for(ll i=1;i<=q;i++){
        cin>>e;
        
        if(curr.find(e)==curr.end()){
            curr.insert(e);
            index_req[e].pb(i-1);
            index_req[e].pb(i);
            

        }else{
            curr.erase(e);
        }


        
        csum[i]=csum[i-1]+curr.size()*1ll;
    }


    
    for(auto e:curr){
        index_req[e].pop_back();
        index_req[e].pb(q);
    }

    for(ll i=1;i<=n;i++){
        ll s=0;
        /*for(auto e:index_req[i]){
            cout<<e<<" ";
        }
        cout<<endl;*/
        
        for(ll j=1;j<index_req[i].size();j+=2){
            s=s+csum[index_req[i][j]]-csum[index_req[i][j-1]];
        }
        cout<<s<<" ";
    }

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