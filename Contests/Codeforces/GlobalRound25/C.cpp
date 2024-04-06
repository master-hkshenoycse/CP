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
    ll n,m,k;
    cin>>n>>m>>k;

    ll req=(k+m-1)/m;
    
    ll rem=k;
    ll ex=0;
    ll value=0;
    for(ll i=1;i<=req;i++){
        ll take=min(rem,m);
        value=value+ex*take;
        ex+=take;
        rem-=take;
    }
    
    //cout<<value<<endl;

    


    vector<ll> a(n);
    

    ll ans=9e18;
    multiset<ll> x;
    ll sum_of_set=0;

    for(ll i=0;i<n;i++){
        cin>>a[i];
        
        x.insert(a[i]);
        sum_of_set+=a[i];

        if(x.size()>req){
            sum_of_set-=*(--x.end());
            x.erase(--x.end());    
        }
        
        if(x.size()==req){
            ll cost=m*sum_of_set;
            ll extra_in_last=req*m-k;

            if(extra_in_last>0){
                cost-=(*--x.end())*extra_in_last;
            }

            ans=min(ans,cost+value);
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
    cin>>t;

	while(t--){
		solve(tc);
        tc++;
    
	}

    return 0;
    
     
}