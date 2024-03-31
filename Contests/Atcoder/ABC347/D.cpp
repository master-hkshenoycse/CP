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
ll get_set_bit(ll n){
    ll c=0;
    for(ll i=59;i>=0;i--){
        if(n & (1ll<<i)){
            c++;
        }
    }
    return c;
}
void solve(ll tc){ 

    ll a,b,c;
    cin>>a>>b>>c;

    ll cnt_a=a;
    ll cnt_b=b;
    ll cnt_c=get_set_bit(c);

    //if set bits in xor is less than total set bits and remaining bits are even in number

    

    if(cnt_c<=cnt_a+cnt_b and (cnt_a+cnt_b-cnt_c)%2==0){

        //iterating over how many bits will be set only in a.,corresponding number will be set in b.
        for(ll j=0;j<=cnt_c;j++){

            
            ll set_a=j;
            ll set_b=cnt_c-j;
            ll val_a=0,val_b=0;


            for(ll i=59;i>=0;i--){
                if(c & (1ll<<i)){
                    if(set_a>0){
                        val_a+=(1ll<<i);
                        set_a--;
                    }else{  
                        val_b+=(1ll<<i);
                    }
                }
            }

            for(ll i=59;i>=0;i--){
                if(c&(1ll<<i)){
                    continue;
                }

                if(get_set_bit(val_a)<cnt_a or get_set_bit(val_b)<cnt_b){
                    val_a+=(1ll<<i);
                    val_b+=(1ll<<i);
                }

            }

            if(get_set_bit(val_a)==cnt_a and get_set_bit(val_b)==cnt_b){
                cout<<val_a<<" "<<val_b<<endl;
                return;
            }


        }
    }

    cout<<-1<<endl;

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