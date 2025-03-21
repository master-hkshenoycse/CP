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

//sequence shoudl be of form 12\1+3.
void solve(ll tc){
    ll n;

    
    string s;
    cin>>s;

    n=s.size();

    ll i=0;
    while(i<n/2 && s[i] == s[n-i-1]){
        i++;
    }
    n-=2*i;
    s=s.substr(i,n);
    

    ll ans=n;

    for(ll rev=0;rev<2;rev++){
        ll lo=0,hi=n;


        while(hi>=lo){

            ll mid=(hi+lo)/2ll;
            vector<ll> cnt(26,0);

            for(ll i=0;i<mid;i++){
                cnt[s[i]-'a']++;
            }

            ll f=1;
            for(ll i=0;i<min(n/2,n-mid);i++){
                ll ch=s[n-i-1]-'a';
                if(i<mid){
                    if(cnt[ch] == 0){
                        f=0;
                        break;
                    }else{
                        cnt[ch]--;
                    }
                }else{
                    if(s[i] - 'a'!= ch){
                        f=0;
                        break;
                    }
                }
            }

            for(ll i=0;i<26;i++){
                if(cnt[i] % 2){
                    f=0;
                    break;
                }
            }

            if(f){
                ans=min(ans,mid);
                hi=mid-1;
            }else{
                lo=mid+1;
            }
        }


        reverse(s.begin(),s.end());

    }

    cout<<ans<<endl;


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
