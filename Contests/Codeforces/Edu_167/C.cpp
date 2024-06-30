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
    ll cnt_np=0,cnt_pn=0,cnt_nn=0,cnt_pp=0;
    ll n;
    cin>>n;

    ll sc_x=0,sc_y=0;

    vector<ll> a(n),b(n);
    
    for(ll i=0;i<n;i++){
        cin>>a[i];
    }

    for(ll i=0;i<n;i++){
        cin>>b[i];
    }

    for(ll i=0;i<n;i++){
        if(a[i]==-1 and b[i]==-1){
            cnt_nn++;
        }

        if(a[i]==-1 and b[i]==0){
            continue;
        }

        if(a[i]==-1 and b[i]==1){
            sc_y++;
        }

        if(a[i]==0 and b[i]==-1){
            continue;
        }

        if(a[i]==0 and b[i]==0){
            continue;
        }

        if(a[i]==0 and b[i]==1){
            sc_y++;
        }

        if(a[i]==1 and b[i]==-1){
            sc_x++;
        }

        if(a[i]==1 and b[i]==0){
            sc_x++;
        }

        if(a[i]==1 and b[i]==1){
            cnt_pp++;
        }

        
    }

    ll lo=-1e9,hi=1e9,ans=-1e9;

    while(hi>=lo){
        ll mid=(hi+lo)/2ll;
        ll f=0;

        for(ll i=0;i<=cnt_pp;i++){
            ll t_x=sc_x+i;
            ll t_y=sc_y+(cnt_pp-i);

            ll req_x=max(0ll,mid-t_x);
            ll req_y=max(0ll,mid-t_y);

            ll ex_x=max(0ll,t_x-mid);
            ll ex_y=max(0ll,t_y-mid);

        
            if(req_x==0 and req_y==0){

                if(ex_x+ex_y>=cnt_nn){
                    f=1;
                }

            }

            if(f==1){
                break;
            }
        }

        

        if(f){
            ans=max(ans,mid);
            lo=mid+1;
        }else{
            hi=mid-1;
        }
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