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

const ll INF = (1LL << 60);

ll get_cnt(ll a,ll b,ll c){

    if(a==b && b==c)
        return INF;

    if(a>b || a>c || b>c)
        return 1;

    return 2*min((b-a),(c-b))+3;
}

bool is_poss(vector<array<ll,3> > &a,ll k,ll mid){

    ll n=a.size();
    ll cnt=0;

    for(ll i=0;i<n;i++){

        ll x=a[i][0];
        ll y=a[i][1];
        ll z=a[i][2];

        ll sum=x+y+z;

        if(sum>=mid)
            continue;

        ll cost=get_cnt(x,y,z);

        if(cost==INF)
            return false;

        cnt=cnt+mid-sum+cost-1;

        if(cnt>k)
            return false;
    }

    return true;
}

void solve(ll tc){

    ll n,k;
    cin>>n>>k;

    ll lo=INF;

    vector<array<ll,3> > a(n);

    for(ll i=0;i<n;i++){

        cin>>a[i][0]>>a[i][1]>>a[i][2];

        ll sum=a[i][0]+a[i][1]+a[i][2];

        lo=min(lo,sum);
    }

    ll hi=lo+k;

    while(lo<hi){

        ll mid=lo+(hi-lo+1)/2ll;

        if(is_poss(a,k,mid)){
            lo=mid;
        }
        else{
            hi=mid-1;
        }
    }

    cout<<lo<<endl;
}

int main(){

    boost;

    ll t=1;
    ll tc=1;

    cin>>t;

    while(t--){

        solve(tc);
        tc++;

    }

    return 0;
}