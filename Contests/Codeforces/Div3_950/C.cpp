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
    vector<ll> b(n);
    
    for(ll i=0;i<n;i++){
        cin>>a[i];
    }

    map<ll,vector<ll> > help;

    for(ll i=0;i<n;i++){
        cin>>b[i];
    }

    for(ll i=0;i<n;i++){
        if(a[i]==b[i]){
            help[b[i]].push_back(i);
        }
    }

    for(ll i=0;i<n;i++){
        if(a[i] != b[i]){
            help[b[i]].push_back(i);
        }
    }

    ll m;
    cin>>m;

    vector<ll> c(m);
    
    for(ll i=0;i<m;i++){
        cin>>c[i];
    }

    ll replace_done=0;

    for(ll i=m-1;i>=0;i--){
        if(help.find(c[i]) == help.end()){
            if(replace_done==0){
                cout<<"NO"<<endl;
                return;
            }   
        }else{
            if(help[c[i]].size()>0){
                replace_done=1;
                a[help[c[i]].back()]=c[i];
                help[c[i]].pop_back();
            }
        }
    }

    for(ll i=0;i<n;i++){
        if(a[i] != b[i]){
            cout<<"NO"<<endl;
            return;
        }
    }

    cout<<"YES"<<endl;

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