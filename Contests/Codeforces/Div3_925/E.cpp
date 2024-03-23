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
ll get_trail(ll e){
    ll cnt=0;
    while(e%10==0){
        e/=10;
        cnt++;
    }
    return cnt;
}

ll cnt_dig(ll e){
    ll cnt=0;
    while(e>0){
        cnt++;
        e/=10;
    }
    return cnt;
}

void solve(ll tc){ 

    ll n,m;
    cin>>n>>m;

    ll e;
    multiset<ll> a;
    ll s=0;
    for(ll i=1;i<=n;i++){
        cin>>e;
        a.insert(get_trail(e));
        s+=cnt_dig(e);
    }

    ll curr_move=0;
    ll sz=a.size();
    while(sz>0){

        
        if(curr_move==0){
            auto i1=(--a.end());
            s=s-(*i1);
            
            a.erase(i1);
            a.insert(0);
        }else{

            if(sz==1){
                break;
            }
            sz--;
            a.erase(--a.end());
        }
        curr_move=1-curr_move;
    }



    if(s>=m+1){
        cout<<"Sasha"<<endl;
    }else{
        cout<<"Anna"<<endl;
    }



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