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

    vector<vector<ll> > a(n+1,vector<ll> (2));
    for(ll i=1;i<=n;i++){
        cin>>a[i][0]>>a[i][1];
    }   

    if(n==1){
        cout<<1<<endl;
        return;
    }

    vector<ll> p_max_x(n+1,0),p_min_x(n+1,0),s_max_x(n+1,0),s_min_x(n+1,0);
    vector<ll> p_max_y(n+1,0),p_min_y(n+1,0),s_max_y(n+1,0),s_min_y(n+1,0);

    for(ll i=1;i<=n;i++){
        p_max_x[i]=a[i][0];
        p_min_x[i]=a[i][0];
        p_max_y[i]=a[i][1];
        p_min_y[i]=a[i][1];
        if(i>1){
            p_max_x[i]=max(p_max_x[i-1],p_max_x[i]);
            p_min_x[i]=min(p_min_x[i-1],p_min_x[i]);
            p_max_y[i]=max(p_max_y[i-1],p_max_y[i]);
            p_min_y[i]=min(p_min_y[i-1],p_min_y[i]);
        }
    }

    for(ll i=n;i>=1;i--){
        s_max_x[i]=a[i][0];
        s_min_x[i]=a[i][0];
        s_max_y[i]=a[i][1];
        s_min_y[i]=a[i][1];
        if(i<n){
            s_max_x[i]=max(s_max_x[i+1],s_max_x[i]);
            s_min_x[i]=min(s_min_x[i+1],s_min_x[i]);
            s_max_y[i]=max(s_max_y[i+1],s_max_y[i]);
            s_min_y[i]=min(s_min_y[i+1],s_min_y[i]);
        }
    }

    ll ans=(p_max_x[n]-p_min_x[n]+1)*(p_max_y[n]-p_min_y[n]+1);

    for(ll i=1;i<=n;i++){
        ll ma_x,mi_x,ma_y,mi_y;

        if(i==1){
            ma_x=s_max_x[i+1];
            mi_x=s_min_x[i+1];
            ma_y=s_max_y[i+1];
            mi_y=s_min_y[i+1];
        }else if(i==n){
            ma_x=p_max_x[i-1];
            mi_x=p_min_x[i-1];
            ma_y=p_max_y[i-1];
            mi_y=p_min_y[i-1];
        }else{
            ma_x = max(p_max_x[i-1],s_max_x[i+1]);
            mi_x = min(p_min_x[i-1],s_min_x[i+1]);
            ma_y = max(p_max_y[i-1],s_max_y[i+1]);
            mi_y = min(p_min_y[i-1],s_min_y[i+1]);
        }
        
        ll l = ma_x-mi_x+1;
        ll h = ma_y-mi_y+1;
       
        if(l*h>=n){
            ans=min(ans,l*h);
        }else{
            ans=min(ans,l*(h+1));
            ans=min(ans,(l+1)*h);
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
