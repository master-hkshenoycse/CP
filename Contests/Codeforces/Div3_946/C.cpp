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

ll get_same_cnt(map<arr<ll,2> , vector<ll> > &help){

    ll ans=0;

    for(auto it:help){
        vector<ll> tmp=it.ss;
        sort(all(tmp));
        ll sz=tmp.size();
        ll cnt=0;
        ll i=0;  
        while(i<sz){
            ll c=0,j=i;
            while(j<sz and tmp[i]==tmp[j]){
                c++;
                j++;
            }
             cnt=cnt+c*(sz-c);
            i=j;
        }   
        

        ans=ans+cnt/2;
    }

    return ans;
}
void solve(ll tc){

    map<arr<ll,3>,ll> all_three_same;
    ll n;
    cin>>n;

    vector<ll> a(n+1);
    for(ll i=1;i<=n;i++){
        cin>>a[i];
    }

 


    map<arr<ll,2>,vector<ll> > first_two_same;
    map<arr<ll,2>,vector<ll> > last_two_same;
    map<arr<ll,2>,vector<ll> > first_last_same;
    ll cnt_two_same=0;
    for(ll i=1;i<=n-2;i++){
        first_two_same[{a[i],a[i+1]}].push_back(a[i+2]);
        last_two_same[{a[i+1],a[i+2]}].push_back(a[i]);
        first_last_same[{a[i],a[i+2]}].push_back(a[i+1]);
    }

    

    cnt_two_same=get_same_cnt(first_two_same)+get_same_cnt(last_two_same)+get_same_cnt(first_last_same);

    

    cout<<cnt_two_same<<endl;

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