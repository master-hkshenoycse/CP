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

    vector<ll> a(n);
    vector<arr<ll,2> > odd_pos,eve_pos;
    
    for(ll i=0;i<n;i++){
        cin>>a[i];
        if(i%2==0){
            eve_pos.pb({a[i],i});
        }else{
            odd_pos.pb({a[i],i});
        }
    }

    vector<ll> sol(n);
    //check whether to maximize even posiiton or odd postiton
    //by checking n belongs to which group

    sort(all(eve_pos));
    sort(all(odd_pos));
    if(odd_pos.back()[0] > eve_pos.back()[0]){
        swap(odd_pos,eve_pos);
    }

    //the group not having n will be odd, and other will be eve
    reverse(all(odd_pos));
    for(ll i=0;i<n/2;i++){
        sol[odd_pos[i][1]]=i+1;//ensures all odd index will be atmost n;
    }




    //ensures all even index will be atleast n+1;
    reverse(all(eve_pos));
    for(ll i=0;i<n/2;i++){
        sol[eve_pos[i][1]]=n/2+i+1;
    }

    for(ll i=0;i<n;i++){
        cout<<sol[i]<<" ";
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