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
ll mod=1e9+7;
ll modpow(ll a,ll n){
    ll res=1;
    while(n>0){
        if(n%2){
            res=(res * a)%mod;
        }
        n/=2;
        a=(a*a)%mod;
    }
    return res;
}
arr<ll,2> get_pow_2(ll num){
    ll res=0;
    while(num%2==0){
        res++;
        num/=2;
    }
    return {num,res};
}
void solve(ll tc){
    ll n;
    cin>>n;
    
    vector<ll> a(n+1);
    for(ll i=1;i<=n;i++){
        cin>>a[i];
    }    

    vector<arr<ll,2> > st;
    ll sum=0;

    for(ll i=1;i<=n;i++){
        arr<ll,2> entry=get_pow_2(a[i]);
        ll r=entry[1];

        while(st.size()>0 and (r>=30 or st.back()[0]<=(entry[0]<< r))){
            r+=st.back()[1];
            sum+=st.back()[0];
            st.pop_back();   
        }

        if(r==0){
            sum+=entry[0];
        }else{
            st.push_back({entry[0],r});
        }

        ll res=sum%mod;

        
        for(auto it:st){
            res=res+(modpow(2,it[1])*it[0])%mod;
            res%=mod;
        }

        cout<<res<<" ";
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