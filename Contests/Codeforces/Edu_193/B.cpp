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
bool isp(ll n){
    for(ll i=2;i*i<=n;i++){
        if(n%i==0)
            return false;
    }

    return true;
}
void solve(ll tc){
    
    ll n;
    cin>>n;

    vector<ll> a(n);
    for(ll i=0;i<n;i++)
        cin>>a[i];
    

    ll cnt=0;
    ll i=0;

    vector<pair<ll,ll> > dis;
    while(i<n){
        ll j=i,cnt=0;
        while(j<n && a[i]==a[j]){
            j++;
            cnt++;
        }
        dis.pb({a[i],cnt});
        i=j;
    }


    ll ans=dis.size();
    //cout<<"og "<<ans<<endl;
    ll ret=ans;
    
    for(ll i=0;i+1<dis.size();i++){
        if(dis[i].ss>1){
            if(i+2>=dis.size()){
                ret=max(ret,ans+1);
            }

            if(dis[i+1].ss>1){
                ret=max(ret,ans+2);
            }

            if(i+2<dis.size() && dis[i+1].ss==1 && (dis[i+2].ff != dis[i].ff)){
                ret=max(ret,ans+1);
            }
        }
    }
    


    
    for(ll i=dis.size()-1;i-1>=0;i--){
        if(dis[i].ss>1){
            if(i-2<0){
                ret=max(ret,ans+1);
            }

            if(dis[i-1].ss>1){
                ret=max(ret,ans+2);
            }

            if(i-2>=0 && dis[i-1].ss==1 && (dis[i-2].ff != dis[i].ff)){
                ret=max(ret,ans+1);
            }
        }
    }
    


    cout<<ret<<endl;

    
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