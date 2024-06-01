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

    vector<ll> a(n+m+2),b(n+m+2),suffix_a(n+m+4,0),suffix_b(n+m+4,0),cum_choose(n+m+2,0),cum_strength(n+m+2,0);

    for(ll i=1;i<=n+m+1;i++){
        cin>>a[i];
    }

    for(ll i=1;i<=n+m+1;i++){
        cin>>b[i];
    }

    for(ll i=1;i<=n+m+1;i++){
        cum_choose[i]=cum_choose[i-1];
        cum_strength[i]=cum_strength[i-1];
        if(a[i]>b[i]){
            cum_choose[i]++;
        }
        cum_strength[i]+=max(a[i],b[i]);
    }

    for(ll i=n+m+1;i>=1;i--){
        suffix_a[i]=suffix_a[i+1]+a[i];
    }

    for(ll i=n+m+1;i>=1;i--){
        suffix_b[i]=suffix_b[i+1]+b[i];
    }



    for(ll i=1;i<=n+m+1;i++){


        ll lo=0,hi=n+m+1,req=0;

        while(hi>=lo){
            ll mid=(hi+lo)/2ll;
            ll cnt_a=cum_choose[mid];

            if(mid>=i){
                cnt_a-=(a[i]>b[i]);
            }


            ll cnt_b=mid-cnt_a;

            if(mid>=i){
                cnt_b=(mid-1)-cnt_a;
            }


            if(cnt_a<=n and cnt_b<=m){
                req=max(req,mid);
                lo=mid+1;
            }else{
                hi=mid-1;
            }
        }

        //cout<<i<<" "<<req<<" ";

        ll sol=cum_strength[req];
        if(req>=i){
            sol-=max(a[i],b[i]);
        }

        ll choose_a=cum_choose[req];
        if(req>=i){
            choose_a-=(a[i]>b[i]);
        }

    
        ll choose_b=req-choose_a;
        if(req>=i){
            choose_b=(req-1)-choose_a;
        }

        ll rem_a=n-choose_a;
        ll rem_b=m-choose_b;

        if(rem_a>0){
            sol+=suffix_a[req+1];
            if(i>req){
                sol-=a[i];
            }
        }   

        //cout<<rem_a<<" "<<rem_b<<endl;
        if(rem_b>0){
            sol+=suffix_b[req+1];
            if(i>req){
                sol-=b[i];
            }
        }

        cout<<sol<<" ";

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