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
    ll n;
    cin>>n;
    vector<ll> v(n+1),p(n+1);
    
    multiset<ll> top_set,bot_set;

    for(ll i=1;i<=n;i++){
        cin>>v[i];
        bot_set.insert(v[i]);
    }    

    for(ll i=1;i<=n;i++){
        cin>>p[i];
    }

    
    ll ans=0;
    ll mushroom_cnt=0;


    for(ll i=1;i<=n;i++){
        
        

        while(top_set.size()<i and bot_set.size()>0){
            top_set.insert(*(--bot_set.end()));
            bot_set.erase(--bot_set.end());
        }

        if(top_set.size()==i){
            ll min_val=*top_set.begin();
            if(min_val*i>ans){
                ans=min_val*i;
                mushroom_cnt=i;
            }
        }

        if(bot_set.find(v[p[i]])!=bot_set.end()){
            bot_set.erase(bot_set.find(v[p[i]]));
        }else{
            top_set.erase(top_set.find(v[p[i]]));
        }
    }

    cout<<ans<<" "<<mushroom_cnt<<endl;


     






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