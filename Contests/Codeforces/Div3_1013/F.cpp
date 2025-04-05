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
ll mod=998244353;
ll get_lo(ll x,ll y,ll m,ll d){
    ll lo=1,hi=m,ret=y;

    while(hi>=lo){
        ll mid=(hi+lo)/2ll;
        if((y-mid)*(y-mid)+x*x<=d*d){
            ret=min(ret,mid);
            hi=mid-1;
        }else{
            lo=mid+1;
        }
    }

    return ret;
}

ll get_hi(ll x,ll y,ll m,ll d){
    ll lo=1,hi=m,ret=y;

    while(hi>=lo){
        ll mid=(hi+lo)/2ll;
        if((y-mid)*(y-mid)+x*x<=d*d){
            ret=max(ret,mid);
            lo=mid+1;
        }else{
            hi=mid-1;
        }
    }

    return ret;
}
void solve(ll tc){
    ll n,m,d;
    cin>>n>>m>>d;

    vector<vector<ll> > a(n+1,vector<ll> (m+1));

    vector<ll> c_dp_1(m+1,0),c_dp_2(m+1,0),dp_1(m+1,0),dp_2(m+1,0);
    for(ll i=1;i<=n;i++){
        string s;
        cin>>s;
        for(ll j=1;j<=m;j++){
            if(s[j-1]=='X'){
                a[i][j]=1;
            }else{
                a[i][j]=0;
            }
        }
    }

    for(ll i=1;i<=m;i++){
        dp_1[i]=a[n][i];
        c_dp_1[i]=(c_dp_1[i-1]+dp_1[i])%mod;
    }

    for(ll i=1;i<=m;i++){
        if(a[n][i]==1){
            ll lo=get_lo(0,i,m,d);
            ll hi=get_hi(0,i,m,d);


            dp_2[i]=(dp_2[i]+(c_dp_1[i-1]-c_dp_1[lo-1]))%mod;
            dp_2[i]=(dp_2[i]+(c_dp_1[hi]-c_dp_1[i]))%mod;
            dp_2[i]=(dp_2[i]+mod)%mod;
        }

        c_dp_2[i]=(c_dp_2[i-1]+dp_2[i])%mod;
    }

    

    for(ll i=n-1;i>=1;i--){
        
        vector<ll> tmp_1(m+1,0),tmp_2(m+1,0);

        for(ll j=1;j<=m;j++){
            if(a[i][j]==1){
                //for 1st move;
                ll lo=get_lo(1,j,m,d);
                ll hi=get_hi(1,j,m,d);

                //cout<<j<<" "<<lo<<" "<<hi<<endl;
                tmp_1[j]=(tmp_1[j]+(c_dp_1[hi]-c_dp_1[lo-1]))%mod;
                tmp_1[j]=(tmp_1[j]+mod)%mod;


                tmp_1[j]=(tmp_1[j]+(c_dp_2[hi]-c_dp_2[lo-1]))%mod;
                tmp_1[j]=(tmp_1[j]+mod)%mod;


            }
        }

        for(ll j=1;j<=m;j++){
            dp_1[j]=tmp_1[j];
            c_dp_1[j]=(c_dp_1[j-1]+dp_1[j])%mod;
        }

        for(ll j=1;j<=m;j++){
            if(a[i][j]==1){
                //for 2 move;

                ll lo=get_lo(0,j,m,d);
                ll hi=get_hi(0,j,m,d);

 
                tmp_2[j]=(tmp_2[j]+(c_dp_1[j-1]-c_dp_1[lo-1]))%mod;
                tmp_2[j]=(tmp_2[j]+mod)%mod; 
                
                tmp_2[j]=(tmp_2[j]+(c_dp_1[hi]-c_dp_1[j]))%mod;
                tmp_2[j]=(tmp_2[j]+mod)%mod;

            }
        }

        for(ll j=1;j<=m;j++){
            dp_2[j]=tmp_2[j];
            c_dp_2[j]=(c_dp_2[j-1]+dp_2[j])%mod;
        }

        
        
    }

    ll ans=0;

    for(ll i=1;i<=m;i++){
        ans=(ans+dp_1[i])%mod;
        ans=(ans+dp_2[i])%mod;
    }

    cout<<(ans+mod)%mod<<endl;
    

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