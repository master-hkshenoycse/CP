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

    vector<ll> a(n+1),left_ops(n+1),right_ops(n+1);
    ll s=0;
    for(ll i=1;i<=n;i++){
        cin>>a[i];
        s+=a[i];
    }

    if(s != 0){
        cout<<"No"<<endl;
        return;
    }

    right_ops[1]=a[1];

    for(ll i=2;i<=n;i++){

        left_ops[i]=right_ops[i-1];
        right_ops[i]=(a[i]+left_ops[i]);

    }

    for(ll i=1;i<=n;i++){
        if(right_ops[i]<0){
            cout<<"No"<<endl;
            return;
        }
    }

    
    ll f=0;
    for(ll i=n;i>=1;i--){
        if(right_ops[i]>0){
            f=1;
        }else{
            if(f==1){
                cout<<"No"<<endl;
                return;
            }
        }
    }

    cout<<"Yes"<<endl;






    

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