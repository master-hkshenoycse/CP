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
    
    ll n,k;
    cin>>n>>k;

    set<ll> violated_set;
    ll brought_cnt=0;

    vector<arr<ll,2> > a;
    ll p;

    for(ll i=1;i<=n;i++){
        cin>>p;
        a.push_back({p,i});
    }

    for(ll i=1;i<=n;i++){
        cin>>p;
        a.push_back({p,i});
    }

    sort(all(a));
   

    ll ans=0;
    ll sz=a.size();
    ll i=sz-1;

    while(i>=0){
       
        ll p=a[i][0];
        ll j=i;
        while(j>=0 and a[j][0]==p){
            ll index=a[j][1];
            if(violated_set.find(index) == violated_set.end()){
                violated_set.insert(index);
                brought_cnt++;
            }else{
                violated_set.erase(index);
            }
            j--;
        }
        
        

        //cout<<brought_cnt<<" "<<p<<" "<<violated_set.size()<<endl;

        if(violated_set.size()<=k){
            ans=max(ans,brought_cnt*p);
        }

        i=j;

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
    cin>>t;

	while(t--){
		solve(tc);
        tc++;
    
	}

    return 0;
    
     
}