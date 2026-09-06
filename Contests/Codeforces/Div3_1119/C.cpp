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
    for(ll i=0;i<n;i++)
        cin>>a[i];
    

    ll ls_one=-1,prev_1_=-1;
    ll len=0,st=-1,en=-1;
    for(ll  i=0;i<n;i++){
        if(a[i]==1 || a[i]==-1){
            if(ls_one!=-1){
                if(len<i-ls_one+1){
                    len=i-ls_one+1;
                    st=ls_one;
                    en=i;
                }    
            }else if(prev_1_!=-1){
                if(len<i-prev_1_+1){
                    len=i-prev_1_+1;
                    st=prev_1_;
                    en=i;
                }
            }

            if(a[i]==1)
                ls_one=i;
            if(a[i]==-1 && prev_1_ ==-1)
                prev_1_=i;
            
        }
    }

    if(st!=-1){


        for(ll i=st+1;i<=en-1;i++){
            a[i]=0;
        }

        a[st]=1;
        a[en]=1;

        for(ll i=0;i<st;i++)
            if(a[i]==-1)
                a[i]=1;
            
        for(ll i=en+1;i<n;i++)
            if(a[i]==-1)
                a[i]=1;
    }else{

        for(ll i=0;i<n;i++)
            if(a[i]==-1)
                a[i]=1;
        
    }

    for(ll i=0;i<n;i++)
        cout<<a[i]<<" ";
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