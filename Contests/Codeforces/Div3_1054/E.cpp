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

ll atleast_len_atleast_dis(vector<ll> &a,ll n,ll len,ll dis){
    map<ll,ll> help;
    ll uniq=0;
    ll j=1,ret=0;
    for(ll i=1;i<=n;i++){
        if(help[a[i]]==0){
            uniq++;
        }

        help[a[i]]++;

        while(j<=i && uniq>=dis){
            help[a[j]]--;
            if(help[a[j]]==0){
                uniq--;
            }
            j++;
        }


        if(uniq==dis-1){
            
            ret=ret+min({j-1,max(0ll,i-len+1)});

        }
        

    }


    return ret;
}
void solve(ll tc){
    ll n,l,r,k;
    cin>>n>>k>>l>>r;

    vector<ll> a(n+1);  

    for(ll i=1;i<=n;i++){
        cin>>a[i];
    }   

    ll len_at_l_k=atleast_len_atleast_dis(a,n,l,k)-atleast_len_atleast_dis(a,n,l,k+1);
    ll len_at_r_k=atleast_len_atleast_dis(a,n,r+1,k)-atleast_len_atleast_dis(a,n,r+1,k+1);

    cout<<len_at_l_k-len_at_r_k<<endl;


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