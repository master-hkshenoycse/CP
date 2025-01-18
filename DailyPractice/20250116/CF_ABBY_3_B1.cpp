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
    ll n,x;
    cin>>n>>x;

    vector<ll> in_deg(n+1,0);
    vector<ll> nx(n+1,-1);
    vector<ll> rank_in_seg(n+1,-1);
    vector<ll> seg_value(n+1,0);
    vector<ll> seg_sizes;

    ll in_front;
    for(ll i=1;i<=n;i++){
        cin>>in_front;
        if(in_front != 0){
            in_deg[i]++;
            nx[in_front]=i;
        }
    }

    ll c=0;
    for(ll i=1;i<=n;i++){
        if(in_deg[i]==0 and rank_in_seg[i]==-1){
            c++;
            ll rank=0;
            ll curr=i;
            while(curr!=-1){
                rank++;
                rank_in_seg[curr]=rank;
                seg_value[curr]=c;
                curr=nx[curr];
            }
            seg_sizes.push_back(rank);
        }
    }

    set<ll> poss;
    poss.insert(0);

    for(ll i=0;i<c;i++){
        if(i+1==seg_value[x]){
            continue;
        }

        set<ll> tmp;
        for(auto c:poss){
            tmp.insert(c+seg_sizes[i]);
        }

        for(auto c:tmp){
            poss.insert(c);
        }

    }


    for(auto p:poss){
        cout<<p+rank_in_seg[x]<<endl;
    }


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