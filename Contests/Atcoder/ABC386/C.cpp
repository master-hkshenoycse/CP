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
    ll k;
    cin>>k;

    string s,t;
    cin>>s>>t;
    ll n=s.size(),m=t.size();

    if(n==m){
       

        ll cnt=0;
        for(ll i=0;i<n;i++){
            cnt+=(s[i] != t[i]);
        }

        if(cnt<=1){
            cout<<"Yes"<<endl;
        }else{
            cout<<"No"<<endl;
        }



        return;
    }
    
    if(m == n-1){
        

        ll pref=0,suff=0;
        while(pref<m and s[pref]==t[pref]){
            pref++;
        }

        while(suff<m and s[n-suff-1]==t[m-suff-1]){
            suff++;
        }

        if(pref+suff>=m){
            cout<<"Yes"<<endl;
        }else{
            cout<<"No"<<endl;
        }

        return;
    }
    
    
    if(m == n+1){
        
        ll pref=0,suff=0;
        while(pref<m and s[pref]==t[pref]){
            pref++;
        }

        while(suff<m and s[n-suff-1]==t[m-suff-1]){
            suff++;
        }

        if(pref+suff>=m-1){
            cout<<"Yes"<<endl;
        }else{
            cout<<"No"<<endl;
        }


        return;
    }

    cout<<"No"<<endl;


}
int main(){
    boost;

    //pre_cum();
    //prec(10);
	//fre;


    ll t=1;
    ll tc=1;
    //cin>>t;

	while(t--){
		solve(tc);
        tc++;
    
	}

    return 0;
    
     
}