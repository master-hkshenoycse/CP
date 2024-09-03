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

    vector<vector<ll> > odd_pos(26,vector<ll> (n+1,0));
    vector<vector<ll> > even_pos(26,vector<ll> (n+1,0));


    string s;
    cin>>s;


    for(ll i=1;i<=n;i++){
        ll ch=s[i-1]-'a';

        for(ll j=0;j<26;j++){
            odd_pos[j][i]+=odd_pos[j][i-1];
            even_pos[j][i]+=even_pos[j][i-1];

            if(i%2==0){
                even_pos[j][i]+=(j==ch);
            }else{
                odd_pos[j][i]+=(j==ch);
            }

        }
    }

    ll ans=n;

    for(ll i=0;i<26;i++){
        for(ll j=0;j<26;j++){
            ll in_place=0;

            if(n%2==0){
                in_place=odd_pos[i][n]+even_pos[j][n];
                ans=min(ans,n-in_place);
            }



            if(n%2){
                //remove kth index
                for(ll k=1;k<=n;k++){
                    in_place=even_pos[i][k-1]+odd_pos[j][k-1]+(odd_pos[i][n]-odd_pos[i][k])+(even_pos[j][n]-even_pos[j][k]);
                    ans=min(ans,n-in_place);
                }
            }

        }
    }

    cout<<ans<<endl;    
    
    
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