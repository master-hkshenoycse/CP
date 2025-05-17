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
vector<ll> get_value(ll start_value,ll x1,ll y1,ll n,ll value){
    
    if(n==0){
        return {x1,y1};
    }


    ll len_part = (1ll<<(n-1));
    ll cnt_part = len_part * len_part;

    if(value <= start_value+cnt_part-1){
        return get_value(start_value,x1,y1,n-1,value);
    }else if(value <= start_value+2*cnt_part-1){
        return get_value(start_value+cnt_part,x1+len_part,y1+len_part,n-1,value);
    }else if(value <= start_value+3*cnt_part-1){
        return get_value(start_value+2*cnt_part,x1+len_part,y1,n-1,value);
    }else{
        return get_value(start_value+3*cnt_part,x1,y1+len_part,n-1,value);
    }
    
    return {-1,-1};

}

ll get_cord(ll x,ll y,ll p,ll q,ll val,ll n){
   
    if(x==p && y==q){
        return val;
    }

    ll len_part = (1ll<<(n-1));
    ll cnt_part = len_part * len_part;
    

    if(x<=p+len_part-1 && y<=q+len_part-1){
        return get_cord(x,y,p,q,val,n-1);
    }else if(x>=p+len_part && y>=q+len_part){
        return get_cord(x,y,p+len_part,q+len_part,val+cnt_part,n-1);
    }else if(x>=p+len_part && y<=q+len_part-1){
        return get_cord(x,y,p+len_part,q,val+2*cnt_part,n-1);
    }else{
        return get_cord(x,y,p,q+len_part,val+3*cnt_part,n-1);
    }
}
void solve(ll tc){
    ll n;
    cin>>n;

    ll q;
    cin>>q;

    string s;

    ll x,y;
    while(q--){
        cin>>s;

        if(s == "->"){
            cin>>x>>y;
            cout<<get_cord(x,y,1,1,1,n)<<endl;
        }else{
            cin>>x;

            auto sol = get_value(1,1,1,n,x);
            cout<<sol[0]<<" "<<sol[1]<<endl;
        }
    }
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
