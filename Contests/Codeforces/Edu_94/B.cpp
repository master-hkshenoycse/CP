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
   ll p,f;
   cin>>p>>f;

   ll cnt_s,cnt_w;
   cin>>cnt_s>>cnt_w;


   ll s,w;
   cin>>s>>w;

   ll ans=0;
    //Let a be sword with player
    //Let b be axe with player
    //Let c be sword with follower
    //Let b be axe with follower

    //Maximize a+b+c+d
    //s.t a*s+b*w<=p
    //s.t c*s+d*w<=f
    //implies (a+c)+(b+d)<= p+f
    //s.t a+c<=cnt_s
    //s.t b+d<=cnt_w

   //iterate on number of swords player will take
   //greedily take the axe from remaining amount
   for(ll i=0;i<=cnt_s;i++){
    
    if(i*s > p){
        break;
    }

    ll rem=p-i*s;//remaining capacity of player
    ll swords_player=i;
    ll axe_player=min(cnt_w,rem/w);
    ll axe_left=cnt_w-axe_player;
    ll swords_left=cnt_s-i;

    ll swords_follower=0;
    ll axe_follower=0;

    //greedily take whatever is of lesser weight
    if(s>w){
        axe_follower=min(axe_left,f/w);
        //take the swords from remaining
        swords_follower=min(swords_left,(f-axe_follower*w)/s);
    }else{
        swords_follower=min(swords_left,f/s);
        //take the axe from remaining
        axe_follower=min(axe_left,(f-swords_follower*s)/w);
    }   

    ans=max(ans,swords_player+axe_player+swords_follower+axe_follower);



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
    cin>>t;

	while(t--){
		solve(tc);
        tc++;
    
	}

    return 0;
    
     
}