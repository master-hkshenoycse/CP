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
ll get_intersection(vector<ll> a,vector<ll> b){
    ll ans=1;

    for(ll i=0;i<3;i++){
        ll min_1=a[i];
        ll min_2=b[i];
        ll max_1=a[i]+7;
        ll max_2=b[i]+7;

        ans=ans*max(0ll,(min(max_1,max_2)-max(min_1,min_2)));
    }

    return ans;
}

ll get_intersection(vector<ll> a,vector<ll> b,vector<ll> c){
    ll ans=1;

    for(ll i=0;i<3;i++){
        ll min_1=a[i];
        ll min_2=b[i];
        ll min_3=c[i];
        ll max_1=a[i]+7;
        ll max_2=b[i]+7;
        ll max_3=c[i]+7;


        ans=ans*max(0ll,(min(max_1,min(max_2,max_3)))-max(min_1,max(min_2,min_3)));
    }

    return ans;
}
void solve(ll tc){ 

    ll v1,v2,v3;
    cin>>v1>>v2>>v3;

    if(v1+2*v2+3*v3 != 343*3ll){
        cout<<"No"<<endl;
        return;
    }

    ll tot=343*3;
    
    
    for(ll a=-7;a<=7;a++){
        for(ll b=-7;b<=7;b++){
            for(ll c=-7;c<=7;c++){
                for(ll d=-7;d<=7;d++){
                    for(ll e=-7;e<=7;e++){
                        for(ll f=-7;f<=7;f++){

                            ll exactly_three=get_intersection({0,0,0},{a,b,c},{d,e,f});

                            if(exactly_three != v3){
                                continue;
                            }

                            ll exactly_two=get_intersection({0,0,0},{a,b,c})+get_intersection({0,0,0},{d,e,f})+get_intersection({a,b,c},{d,e,f})-3*exactly_three;
                            
                            if(exactly_two != v2){
                                continue;
                            }


                            ll exactly_one=tot-2*exactly_two-3*exactly_three;

                            if(exactly_one==v1 and exactly_two==v2 and exactly_three==v3){
                                cout<<"Yes"<<endl;
                                cout<<0<<" "<<0<<" "<<0<<" "<<a<<" "<<b<<" "<<c<<" "<<d<<" "<<e<<" "<<f<<endl; 
                                return;
                            }
                        }
                    }
                }

            }
        }
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