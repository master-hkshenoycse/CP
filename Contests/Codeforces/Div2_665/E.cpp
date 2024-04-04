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
ll bit[1000005];
void upd(ll ind,ll v){
    while(ind<=1000000){
        bit[ind]+=v;
        ind+=(ind & (-ind));
    }
}

ll query(ll ind){
    ll s=0;
    while(ind>0){
        s=s+bit[ind];
        ind-=(ind  & (-ind));
    }
    return s;

}
void solve(ll tc){ 
   ll ans=1;
   ll n,m;
   cin>>n>>m;

   ll lim=1e6;
   vector<ll> X(m+1),Y(n+1),LX(n+1),RX(n+1),LY(m+1),RY(m+1);
   vector<vector<ll> > L(1e6+5),R(1e6+5),Q(1e6+5);
    //given in question that segments intersect on atleast on of the sides of square.
   for(ll i=1;i<=n;i++){
     cin>>Y[i]>>LX[i]>>RX[i];

     if(LX[i]==0 and RX[i]==lim){//add 1 square as it alrwady intersects a square
        ans++;
     }

     L[LX[i]].push_back(i);//store the starting of segment for update
     R[RX[i]+1].push_back(i);//store the end of segment for update
   }

   for(ll i=1;i<=m;i++){
    cin>>X[i]>>LY[i]>>RY[i];

    if(LY[i]==0 and RY[i]==lim){//add 1 square as it alrwady intersects a square
        ans++;
    }

    Q[X[i]].push_back(i);
   }

   for(ll i=0;i<=lim;i++){

        for(auto e:L[i]){
            upd(Y[e],1);//activate the segment 
        }

        for(auto e:R[i]){
            upd(Y[e],-1);//deactivate the segment
        }

        //finding interseaction of current cordinates vertical lines with active horizontal lines

        for(auto e:Q[i]){
            ans=ans+query(RY[e]);

            if(LY[e]-1>=0){
                ans=ans-query(LY[e]-1);
            }
        }



   }

   cout<<ans<<endl;

    
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