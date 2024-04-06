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
/*

Since sequence b is non-decreasing and sequence c is non-increasing, 
mimimize max(c1,bn). is the question

if a(i)>a(i−1) then b(i)=b(i−1)+a(i)−a(i−1) and c(i)=c(i−1)
if a(i)<a(i−1) then b(i)=b(i−1) and c(i)=c(i−1)+a(i)−a(i−1)
Let this sum be K=summation(2 to n) max(0,a(i)-a(i-1))
Let c(1)=x => b(1)=x-c(1)
b(1)=a(1)−x+K.
=>to minimize max(x,a(1)−x+K)
=>x =(a(1)+K)/2

so each query changes the adjacent value
take care of 

*/
ll a[200005];
ll val[200005];
ll get_sol(ll k){
    ll x=(a[1]+k)/2ll;
    return max(x,a[1]-x+k);
}
void solve(ll tc){ 
    ll n;
    cin>>n;

    ll k=0;
    for(ll i=1;i<=n;i++){
        cin>>a[i];
        if(i>1){
            val[i]=a[i]-a[i-1];
        }
        if(val[i]>0){
            k+=val[i];
        }

    }    


    cout<<get_sol(k)<<endl;

    

    ll q;
    cin>>q;

    ll l,r,x;
    while(q--){
        cin>>l>>r>>x;



        
        

        
        if(l-1>=1){
            if(val[l]>0)k-=val[l];
            val[l]+=x;
            if(val[l]>0)k+=val[l];    
        }else{
            a[l]+=x;
        }

        if(r+1<=n){
            if(val[r+1]>0)k-=val[r+1];
            val[r+1]-=x;
            if(val[r+1]>0)k+=val[r+1];
        }

        
        
        
        cout<<get_sol(k)<<endl;
    }
       



   
    
}   
int main(){
    boost;

    //pre_cum();
    //prec(20);
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