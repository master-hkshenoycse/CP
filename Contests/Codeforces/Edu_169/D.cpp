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

bool check_common(string &s,string &t){

    for(auto s_ch:s){
        for(auto t_ch:t){
            if(s_ch==t_ch){
                return 1;
            }
        }
    }

    return 0;
}
void solve(ll tc){
    ll n,q;
    cin>>n>>q;

    map<string,vector<ll> > by_types;
    vector<string> types(n+1);
    string s;
    for(ll i=1;i<=n;i++){
        cin>>types[i];
        by_types[types[i]].push_back(i);
    }

    vector<string> types_available;
    for(auto it:by_types){
        types_available.pb(it.first);
    }


    ll x,y;
    while(q--){
        cin>>x>>y;
        string type_x=types[x];
        string type_y=types[y];

        if(check_common(type_x,type_y)){
            cout<<abs(x-y)<<endl;
        }else{

            ll ans=1e18;
            vector<ll>::iterator it;
            for(auto inter:types_available){
                if(check_common(inter,type_x) and check_common(inter,type_y)){
                    
                    it=lower_bound(all(by_types[inter]),x);
                    if(it != by_types[inter].end()){
                        ans=min(ans,abs(*it-x)+abs(*it-y));
                    }

                    if(it != by_types[inter].begin()){
                        it--;
                        ans=min(ans,abs(*it-x)+abs(*it-y));
                    }

                    it=lower_bound(all(by_types[inter]),y);
                    
                    if(it != by_types[inter].end()){
                        ans=min(ans,abs(*it-x)+abs(*it-y));
                    }

                    if(it != by_types[inter].begin()){
                        it--;
                        ans=min(ans,abs(*it-x)+abs(*it-y));
                    }


                    


                }
            }

            if(ans==1e18){
                ans=-1;
            }

            cout<<ans<<endl;
        }

        

        
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