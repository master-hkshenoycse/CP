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

    vector<ll> deg(n+1,0);

    ll x,y;
    for(ll i=1;i<n;i++){
        cin>>x>>y;
        deg[x]++;
        deg[y]++;
    }

    string s;
    cin>>s;

    ll leaf_0=0,leaf_1=0;
    ll leaf_q=0,non_leaf_q=0;

    for(ll i=2;i<=n;i++){
        if(s[i-1]=='?'){
            if(deg[i]==1){
                leaf_q++;
            }else{
                non_leaf_q++;
            }
        }else{
            if(deg[i]==1){
                if(s[i-1]=='0'){
                    leaf_0++;
                }else{
                    leaf_1++;
                }
            }
        }
    }

    //leaf nodes with number different than root will contribute to answer
    if(s[0]=='0'){
        cout<<leaf_1+(leaf_q+1)/2<<endl;
    }else if(s[0]=='1'){
        cout<<leaf_0+(leaf_q+1)/2<<endl;
    }else{

        if(leaf_0 == leaf_1){
            if(non_leaf_q % 2){
                leaf_q++;//as both leaf count are equal, first coloring the root is disadvantage.
            }

            cout<<leaf_0+leaf_q/2<<endl;
        }else{
            cout<<max(leaf_0,leaf_1)+leaf_q/2<<endl;// 1 move lost in coloring root appropriatley.
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