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
    ll n,k;
    cin>>n>>k;

    //as every k length substring has same balance k/2, this impolies string at index i and i+k are same.
    //It is a necessary condition that there should not be two distinct characters in index%k indexes.
    //

    string s;
    cin>>s;

    vector<ll> cnt_0(k,0),cnt_1(k,0);

    for(ll i=0;i<n;i++){

        if(s[i]=='0'){
            cnt_0[i%k]++;
        }else if(s[i]=='1'){
            cnt_1[i%k]++;
        }
    }

    for(ll i=0;i<k;i++){
        //cout<<i<<" "<<cnt_0[i]<<" "<<cnt_1[i]<<endl;
        if(cnt_0[i]>0 and cnt_1[i]>0){
            cout<<"NO"<<endl;
            return;
        }
    }


    ll sum_1=0,sum_0=0;
    for(ll i=0;i<k;i++){
        if(cnt_1[i]>0){
            sum_1++;
        }else if(cnt_0[i]>0){
            sum_0++;
        }
    }

    //only then both can be make equal with ? marks
    if(sum_0<=k/2 and sum_1<=k/2){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
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