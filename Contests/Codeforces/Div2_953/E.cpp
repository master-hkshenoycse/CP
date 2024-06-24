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
string get_optimal(string &s,string &t){
    ll n=s.size();

    string t_=t;

    for(ll i=0;i<n;i++){
        if(i+2<n and i+1<n and s[i]=='0' and s[i+2]=='0'){
            t_[i+1]='1';
        }
    }

    //first do all operation of type 1 then type 2 is optimal
    //keep prefix of all ones

    string s_=s;

    for(ll i=0;i<n;i++){
        if(i+2<n and i+1<n and t_[i]=='1' and t_[i+2]=='1'){
            s_[i+1]='1';
        }
    }

    return s_;
}
void solve(ll tc){
    ll n;
    cin>>n;

    string s,t;
    cin>>s>>t;

    
    string s_=get_optimal(s,t);

    vector<ll> prefix_sum(n+2,0);
    for(ll i=1;i<=n;i++){
        prefix_sum[i]=prefix_sum[i-1]+(s_[i-1]=='1');
    }

    ll q;
    cin>>q;

    ll l,r;
    while(q--){
        cin>>l>>r;
        if(r-l+1<=6){
            string tmp_s=s.substr(l-1,r-l+1);
            string tmp_t=t.substr(l-1,r-l+1);

            string opt=get_optimal(tmp_s,tmp_t);
            ll ans=0;
            for(auto ch:opt){
                ans+=(ch=='1');
            }
            cout<<ans<<endl;
        }else{
            //exclude  first and last 2 elements from precomputation. 
            ll ans=(prefix_sum[r-2]-prefix_sum[l+1]);
            ans+=(s[l-1]=='1');
            ans+=(s[r-1]=='1');

            //condition for getting l+1 =1
            if(s[l]=='1' or (t[l-1]=='1' and t[l+1]=='1') or (t[l-1]=='1' and s[l]=='0' and s[l+2]=='0') ){
                ans++;
            }

            if(s[r-2]=='1' or (t[r-1]=='1' and t[r-3]=='1') or (t[r-1]=='1' and s[r-4]=='0' and s[r-2]=='0')){
                ans++;
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