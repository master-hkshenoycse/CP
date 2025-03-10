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
    ll n,t;
    cin>>n>>t;

    string s;
    cin>>s;

    vector<ll> a(n);
    for(ll i=0;i<n;i++){
        cin>>a[i];
    }

    vector<vector<ll> > coll(n);
    for(ll i=0;i<n;i++){
        coll[i]={a[i],s[i]-'0'-1};
    }

    sort(all(coll));
    vector<ll> prefix_sum(n,0);
    for(ll i=0;i<n;i++){
        prefix_sum[i]=coll[i][1]*-1;
        if(i-1>=0){
            prefix_sum[i]+=prefix_sum[i-1];
        }
    }

    ll ans=0;
    for(ll i=n-1;i>=0;i--){

        if(coll[i][1]==-1){
            continue;
        }
        
        ll lo=i+1,hi=n-1,r=i;

        while(hi>=lo){
            ll mid=(hi+lo)/2ll;
            if(coll[mid][0]-coll[i][0]<=2*t){
                r=max(r,mid);
                lo=mid+1;
            }else{
                hi=mid-1;
            }
        }
        ans=ans+(prefix_sum[r]-prefix_sum[i]);
        
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