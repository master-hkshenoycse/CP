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
bool check(vector<ll> &a){
    ll n=a.size();

    for(ll i=0;i<n;i++){
        ll prev=((i-1)%n+n)%n;
        ll nx=(i+1)%n;
        if(a[i]>a[nx] and a[i]>a[prev]){
            continue;
        }

        if(a[i]<a[nx] and a[i]<a[prev]){
            continue;
        }

        return 0;
    }

    return 1;
}
void solve(ll tc){
    ll n;
    cin>>n;

    vector<ll> a(n),b(n);
    for(ll i=0;i<n;i++){
        cin>>a[i];
        b[i]=a[i];
    }

    sort(all(b));

    ll j=0;
    for(ll i=0;i<n;i+=2){
        a[i]=b[j++];
    }
    for(ll i=1;i<n;i+=2){
        a[i]=b[j++];
    }




    if(check(a)){
        cout<<"YES"<<endl;
        for(auto e:a){
            cout<<e<<" ";
        }
        cout<<endl;
        return;
    }

    cout<<"NO"<<endl;

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