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
#define fre freopen("substitution_cipher_validation_input.txt","r",stdin),freopen("substitution_cipher_validation_output.txt","w",stdout)
#define arr array 
using namespace std;
ll mod=998244353;
void solve(ll tc){
    string s;
    ll k;

    cin>>s>>k;
    ll n=s.size();


    vector<ll> dp(n+1,0),curr(n+1,-1);
    vector<arr<ll,2> > ind_change;

    for(ll i=1;i<=n;i++){
        if(s[i-1]!='?'){
            curr[i]=(s[i-1]-'0');
        }
    }


    dp[0]=1;

    for(ll i=1;i<=n;i++){
        ll x=0;

        if(curr[i]==-1){
            x=1;
        }else{
            x=curr[i];
        }

        if(x>0){
            dp[i]=(dp[i]+dp[i-1])%mod;
        } 

        if(i>1){
            ll y=curr[i-1];

            
            
            if(y*10+x<=26 and y>0){
                dp[i]=(dp[i]+dp[i-2])%mod;
            }
        }


        if(curr[i]==-1){

            //is change possible 1/2
            if(i<n and curr[i+1]<=6){
                ind_change.pb({i,2});
            }else{

                if(i==n){
                    if(ind_change.back()[0]==n-1){
                        ind_change.pop_back();
                    }
                    
                    if(i>1 and curr[i-1]==2){
                        ind_change.pb({i,6});
                    }else{
                        ind_change.pb({i,9});
                    }
                }else{

                    if(i==1){
                        ind_change.pb({i,9});
                    }else{
                        if(curr[i-1]==2){
                            ind_change.pb({i,6});
                        }else{
                            ind_change.pb({i,9});
                        }
                    }

                }                

            }

            curr[i]=1;

        }


    }

   
    //reverse(all(ind_change));

    ll sz=ind_change.size();
    
 
    
    k--;
    
    
    for(ll i=sz-1;i>=0;i--){
        ll r=k%ind_change[i][1];
        k/=ind_change[i][1];
        ll idx=ind_change[i][0];
        curr[idx]=ind_change[i][1]-r;
    }

    string sol;
    for(ll i=1;i<=n;i++){
        sol+=char('0'+curr[i]);
    }

    
    cout<<"Case #"<<tc<<": "<<sol<<" "<<dp[n]<<endl;

}
int main(){
    boost;

    //pre_cum();
    //prec(10);
	fre;


    ll t=1;
    ll tc=1;
    cin>>t;

	while(t--){
		solve(tc);
        tc++;
    
	}

    return 0;
    
     
}