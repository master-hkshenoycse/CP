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
    ll n,q;
    cin>>n>>q;

    string ans;
    ll ind=0;

    vector<ll> typ_q(q),ind_q(q);
    vector<string> str_q(q);

    for(ll i=0;i<q;i++){
        cin>>typ_q[i]>>ind_q[i];
        if(typ_q[i]==2){
            cin>>str_q[i];
            reverse(str_q[i].begin(),str_q[i].end());
        }
        //cout<<typ_q[i]<<" "<<ind_q[i]<<endl;
    }

    for(ll i=q-1;i>=0;i--){
        //cout<<ind<<" ";
        if(typ_q[i]==1){
            if(ind == ind_q[i]){
                ind=0;
            }
        }else if(typ_q[i]==2){
            if(ind == ind_q[i]){
                ans+=str_q[i];
            }
        }else{
            if(ind==0){
                ind = ind_q[i];
            }
        }
    }

    reverse(ans.begin(),ans.end());


    cout<<ans<<endl;


}   
int main(){
    boost;

    //pre_cum();
    //prec(10);
	//fre;


    ll t=1;
    ll tc=1;
    //cin>>t;

	while(t--){
		solve(tc);
        tc++;
    
	}

    return 0;
    
     
}