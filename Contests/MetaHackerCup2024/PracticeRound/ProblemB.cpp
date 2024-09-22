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
#define fre freopen("line_by_line_input.txt","r",stdin),freopen("ProblemB_output.txt","w",stdout)
#define arr array 
using namespace std;

void solve(ll tc){
    ll n,p;
    cin>>n>>p;

    dd req_probablity=1.00;
    dd corr_proba=p*1.00/100.00;

    for(ll i=1;i<=n-1;i++){
        req_probablity=(req_probablity*corr_proba);
    }
    //req_probablity=(req_probablity*(1-corr_proba));

    dd lo=0,hi=1.00,ans=1.00;

    for(ll i=0;i<=500;i++){
        dd mid=(hi+lo)/2.00;

        dd curr_proba=1.00;
        for(ll j=1;j<=n;j++){
            curr_proba=(curr_proba*mid);
        }

        if(curr_proba>=req_probablity){
            ans=min(ans,mid);
            hi=mid;
        }else{
            lo=mid;
        }
    }
    cout<<"Case #"<<tc<<": "<<(ans*100-p*1.00)<<endl;

}
int main(){
    boost;

    //pre_cum();
    prec(20);
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