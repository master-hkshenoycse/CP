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
bool possible(string &a,string &b){
    ll n=a.size();
    ll c00=0,c01=0,c10=0,c11=0;

    for(ll i=0;i<n;i++){
        if(i%2==0){
            if(a[i]=='0'){
                c00++;
            }else{
                c01++;
            }
        }else{
            if(a[i]=='0'){
                c10++;
            }else{
                c11++;
            }
        }
    }


    for(ll i=0;i<n;i++){
        if(i%2==0){
            if(b[i]=='0'){
                c00--;
            }else{
                c01--;
            }
        }else{
            if(b[i]=='0'){
                c10--;
            }else{
                c11--;
            }
        }
    }

    
    return (c00==0 && c01==0 && c10==0 && c11==0);
}
void solve(ll tc){
    ll n;
    string a,b;
    cin>>n>>a>>b;

    if(!possible(a,b)){
        cout<<-1<<endl;
        return;
    } 

    vector<ll> pos_a[2],pos_b[2];
    for(ll i=0;i<n;i++){
        if(a[i]=='1')pos_a[i%2].push_back(i);
        if(b[i]=='1')pos_b[i%2].push_back(i);
    }

    ll ops=0;

    for(ll i=0;i<2;i++){
        ll sz=pos_a[i].size();
        for(ll j=0;j<sz;j++){
            ops+=abs(pos_a[i][j]-pos_b[i][j]);
        }
    }

    cout<<ops/2<<endl;

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