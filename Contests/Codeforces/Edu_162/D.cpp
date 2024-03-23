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
/*https://codeforces.com/contest/1923/submission/249249479*/
/*Binary search on subarray and a subarray can b combined if theere are atleast two distinct elements in it*/
void solve(ll tc){ 
    ll n;
    cin>>n;

    vector<ll> csum(n+1,0),a(n+1),sol(n+1,n+1);

    for(ll i=1;i<=n;i++){
        cin>>a[i];
        csum[i]=csum[i-1]+a[i];
    }

    vector<ll> prev_diff(n+1,-1),nx_diff(n+1,n+1);
    for(ll i=1;i<=n;i++){
        if(i>1){
            if(a[i]==a[i-1]){
                prev_diff[i]=prev_diff[i-1];
            }else{
                prev_diff[i]=i-1;
            }
        }
    }

    for(ll i=n;i>=1;i--){
        if(i<n){
            if(a[i]==a[i+1]){
                nx_diff[i]=nx_diff[i+1];
            }else{
                nx_diff[i]=i+1;
            }
        }
    }

    for(ll i=1;i<=n;i++){

        if(i==1){
            continue;
        }

        ll hi=i-1,lo=1,ans=0;

        while(hi>=lo){
            ll mid=(hi+lo)/2ll;
            ll is_valid=0;


            if(i-mid==1){
                is_valid=1;
            }else{
                if(prev_diff[i-1]>=mid){
                    is_valid=1;
                }
            }

            if(is_valid && (csum[i-1]-csum[mid-1])>a[i]){
                ans=max(ans,mid);
                lo=mid+1;
            }else{
                hi=mid-1;
            }
        }

        if(a[i]<a[i-1]){
            sol[i]=1;
        }

        if(ans>0 and i-ans<sol[i]){
            sol[i]=i-ans;
        }

    }

    for(ll i=n;i>=1;i--){

        if(i==n){
            continue;
        }

        ll hi=n,lo=i+1,ans=n+1;

        while(hi>=lo){
            ll mid=(hi+lo)/2ll;
            ll is_valid=0;
            if(mid-i==1){
                is_valid=1;
            }else{
                if(nx_diff[i+1]<=mid){
                    is_valid=1;
                }
            }

            if(is_valid && (csum[mid]-csum[i])>a[i]){
                ans=min(ans,mid);
                hi=mid-1;
            }else{
                lo=mid+1;
            }
        }

        if(a[i]<a[i+1]){
            sol[i]=1;
        }
        if(ans<=n and ans-i<sol[i]){
            sol[i]=ans-i;
        }

    }

    for(ll i=1;i<=n;i++){
        if(sol[i]==n+1){
            sol[i]=-1;
        }
        cout<<sol[i]<<" ";
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