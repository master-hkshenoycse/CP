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
    ll n,m;
    cin>>n>>m;

    vector<ll> a(n+1),b(m+1);

    vector<ll> csum_a(n+1,0),csum_b(m+1,0);
    for(ll i=1;i<=n;i++){
        cin>>a[i];
    }

    for(ll i=1;i<=m;i++){
        cin>>b[i];
    }

    sort(a.begin()+1,a.end());
    sort(b.begin()+1,b.end());
    
    for(ll i=1;i<=n;i++){
        csum_a[i]=csum_a[i-1]+a[i];
    }

    for(ll i=1;i<=m;i++){
        csum_b[i]=csum_b[i-1]+b[i];
    }

    ll k_max=min(n,m);

    vector<ll> sol_poss(k_max+1,0);

    for(ll xa=0;xa*2<=n;xa++){
        for(ll xb=0;xb*2<=m;xb++){
            ll a_used=xa*2+xb;
            ll b_used=xb*2+xa;
            if(a_used<=n and b_used<=m){
                ll a_values=(csum_a[n]-csum_a[n-xa])-csum_a[xa];
                ll b_values=(csum_b[m]-csum_b[m-xb])-csum_b[xb];
                sol_poss[xa+xb]=max(sol_poss[xa+xb],a_values+b_values);

            }
        }
    }

    vector<ll> sol;
    for(ll i=1;i<=k_max;i++){
        if(sol_poss[i]>0){
            sol.push_back(sol_poss[i]);
        }
    }
    cout<<sol.size()<<endl;
    for(auto s:sol){
        cout<<s<<" ";
    }
    cout<<endl;
    

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