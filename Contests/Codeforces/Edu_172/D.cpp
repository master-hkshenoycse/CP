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

    vector<vector<ll> > p;
    vector<ll> l(n),r(n);
    map<pair<ll,ll>,ll> help;
    
    for(ll i=0;i<n;i++){
        cin>>l[i]>>r[i];
        help[{l[i],r[i]}]++;
        p.pb({l[i],-r[i],i});
    }

    sort(all(p));


    multiset<ll> m;
    vector<ll> r_lim(n),l_lim(n);
    for(ll i=0;i<n;i++){
       ll ind=p[i][2];
       p[i][1]*=-1;
       r_lim[ind]=p[i][1];
       if(m.lower_bound(p[i][1]) != m.end()){
            r_lim[ind]=*m.lower_bound(p[i][1]);
       } 
       m.insert(p[i][1]);
    }


    while(m.size()>0){
        m.erase(m.begin());
    }

    for(ll i=0;i<n;i++){
        swap(p[i][0],p[i][1]);
        p[i][1]*=-1;

    }
    sort(all(p));

    multiset<ll>::iterator it;
    for(ll i=n-1;i>=0;i--){
        ll ind=p[i][2];
        p[i][1]*=-1;
 
        l_lim[ind]=p[i][1];
        it=m.upper_bound(p[i][1]);

        if(m.size()>0 and it!=m.begin()){
            it--;
            l_lim[ind]=*it;
        }

        m.insert(p[i][1]);
    }


    vector<ll> sol(n);
    for(ll i=0;i<n;i++){
        ll ind=p[i][2];
        sol[ind]=(r_lim[ind]-l_lim[ind])-(r[ind]-l[ind]);
        if(help[{l[ind],r[ind]}]>1){
            sol[ind]=0;
        }
    }

    for(ll i=0;i<n;i++){
       cout<<sol[i]<<endl;
    }

    

    


    



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