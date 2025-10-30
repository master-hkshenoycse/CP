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
ll get_freq(vector<ll> &freq,ll l,ll r){
    return upper_bound(all(freq),r)-lower_bound(all(freq),l);
}
void solve(ll tc){
    ll n,q;
    cin>>n>>q;

    vector<ll> a(n+1);
    map<ll,ll> hsh;
    vector<vector<ll> >freq(n+1);  
    for(ll i=1;i<=n;i++){
        cin>>a[i];

        if(hsh.find(a[i]) == hsh.end()){
            ll sz=hsh.size();
            hsh[a[i]]=sz+1;
        }

        freq[hsh[a[i]]].push_back(i);
    }

    while(q--){
        ll l,r;
        cin>>l>>r;
        ll len=r-l+1;
        vector<ll> ret;
        for(ll i=0;i<50;i++){
            ll idx=rand()%len;
            ll val=a[l+idx];
            ll f=get_freq(freq[hsh[val]],l,r);
            if(f>len/3){
                if(ret.size()==0 || (ret.back() != val && ret.front()!=val))
                    ret.push_back(val);
            }
        }

        if(ret.size()==0){
            ret.push_back(-1);
        }

        if(ret.size()>1 && ret[0]>ret[1]){
            swap(ret[0],ret[1]);
        }

        for(auto r:ret){
            cout<<r<<" ";
        }


        cout<<"\n";

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