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

    string s;
    cin>>s;

    vector<ll> ending_zero,ending_one;
    vector<ll> sol;

    ll curr_ind=0;

    for(auto ch:s){
        if(ch=='0'){
            if(ending_one.size()==0){
                curr_ind++;
                sol.pb(curr_ind);
                ending_zero.pb(curr_ind);
            }else{
                sol.push_back(ending_one.back());
                ending_one.pop_back();
                ending_zero.push_back(sol.back());
            }
        }else{
            if(ending_zero.size()==0){
                curr_ind++;
                sol.pb(curr_ind);
                ending_one.pb(curr_ind);
            }else{
                sol.push_back(ending_zero.back());
                ending_zero.pop_back();
                ending_one.push_back(sol.back());
            }
        }
    }

    cout<<curr_ind<<endl;
    for(auto s:sol){
        cout<<s<<" ";
    }
    cout<<endl;
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