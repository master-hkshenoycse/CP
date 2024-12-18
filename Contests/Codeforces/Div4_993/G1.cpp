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
vector<ll> facts[200005];
void pre_cum(){
    for(ll i=1;i<=200000;i++){
        for(ll j=i;j<=200000;j+=i){
            facts[j].pb(i);
        }
    }
}
void solve(ll tc){

    ll n,m,q;
    cin>>n>>m>>q;
    //sc(n);
    //sc(m);
    //sc(q);

    vector<ll> a(n),b(m);

    ll s_a=0,s_b=0;

    for(ll i=0;i<n;i++){
        cin>>a[i];
        //sc(a[i]);
        s_a+=a[i];
    }

    for(ll i=0;i<m;i++){
        cin>>b[i];
        //sc(b[i]);
        s_b+=b[i];
    }


    map<ll,ll> help_row,help_col;

    for(ll i=0;i<n;i++){
        if(abs(s_a-a[i])<=200000)help_row[s_a-a[i]]++;

    }

    for(ll i=0;i<m;i++){
        if(abs(s_b-b[i])<=200000)help_col[s_b-b[i]]++;
    }

    ll x;
    map<ll,ll> sol;

    while(q--){
        cin>>x;
        //sc(x);

        if(sol.find(x) != sol.end()){
            if(sol[x]==1){
                cout<<"YES"<<"\n";
            }else{
                cout<<"NO"<<"\n";
            }
            continue;
        }
        
        ll sn=1;
        if(x<0){
            sn=-1;
        }

        x=abs(x);
        ll f=0;

        if(x==0){
            if(help_row.find(0)!=help_row.end() or help_col.find(0) !=help_col.end()){
                f=1;
            }
        }else{

            for(auto i:facts[x]){
                if(x%i==0){
                    
                    ll u=i,v=x/i;
                    vector<pair<ll,ll> > poss;
                    

                    if(sn==1){
                        poss.pb({u,v});
                        poss.pb({v,u});
                        poss.pb({-u,-v});
                        poss.pb({-v,-u});
                    }else{
                        poss.pb({-u,v});
                        poss.pb({u,-v});
                        poss.pb({-v,u});
                        poss.pb({v,-u});
                    }


                    for(auto p:poss){
                        if(help_row.find(p.ff)!= help_row.end() and help_col.find(p.ss)!=help_col.end()){
                            f=1;
                            break;
                        }
                    }


                    

                    
                }
            }

        }

        if(f){
            //printf("YES\n");
            cout<<"YES"<<"\n";
        }else{
            //printf("NO\n");
            cout<<"NO"<<"\n";
        }

        sol[x*sn]=f;

        


    }





}
int main(){
    boost;

    pre_cum();
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