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

const ll NEG = -(1LL << 60);

ll get_cost(ll x, ll y) {
    return x == y ? 2 : 1;
}

void solve(ll tc) {

    ll n;
    cin >> n;

    vector<ll> a(n), b(n);

    for(ll i=0;i<n;i++)
        cin >> a[i];

    for(ll i=0;i<n;i++)
        cin >> b[i];


    ll dp[3][3][2];
    ll ndp[3][3][2];

    for(ll x=0;x<3;x++)
        for(ll y=0;y<3;y++)
            for(ll z=0;z<2;z++)
                dp[x][y][z]=NEG;


    dp[0][0][0] = 0;

    if(a[0] == b[0])
        dp[1][1][1] = 2;
    else
        dp[1][1][1] = 1;

    for(ll i=1;i<n;i++) {

        for(ll x=0;x<3;x++)
            for(ll y=0;y<3;y++)
                for(ll z=0;z<2;z++)
                    ndp[x][y][z]=NEG;


        for(ll da=0;da<3;da++) {
            for(ll db=0;db<3;db++) {
                for(ll same=0;same<2;same++) {

                    if(dp[da][db][same] == NEG)
                        continue;

                    for(ll mask=0;mask<8;mask++) {

                        ll e1 = mask & 1;
                        ll e2 = (mask >> 1) & 1;
                        ll e3 = (mask >> 2) & 1;

                        // New degrees of old vertices
                        ll nda = da + e1;
                        ll ndb = db + e2;

                        if(nda > 2 || ndb > 2)
                            continue;

                        // New degrees of current vertices
                        ll na = e2 + e3;
                        ll nb = e1 + e3;


                        ll par[4];

                        for(ll j=0;j<4;j++)
                            par[j]=j;

                        auto find = [&](ll x) {
                            while(par[x] != x) {
                                par[x]=par[par[x]];
                                x=par[x];
                            }
                            return x;
                        };

                        auto unite = [&](ll x,ll y) {

                            x=find(x);
                            y=find(y);

                            if(x==y)
                                return false;

                            par[y]=x;
                            return true;
                        };


                        if(same)
                            unite(0,1);

                        bool cycle=false;

                        // a[i-1] -- b[i]
                        if(e1) {
                            if(!unite(0,3))
                                cycle=true;
                        }

                        // b[i-1] -- a[i]
                        if(e2) {
                            if(!unite(1,2))
                                cycle=true;
                        }

                        // a[i] -- b[i]
                        if(e3) {
                            if(!unite(2,3))
                                cycle=true;
                        }

                        // Never create a cycle.
                        if(cycle)
                            continue;


                        if(nda == 0 || ndb == 0)
                            continue;

                        if(i==1 && nda!=1)
                            continue;


                        bool bad=false;

                        for(ll root=0;root<4;root++) {

                            if(find(root)!=root)
                                continue;

                            bool old=false;
                            bool nw=false;

                            for(ll v=0;v<4;v++) {

                                if(find(v)!=root)
                                    continue;

                                if(v==0 || v==1)
                                    old=true;

                                if(v==2 || v==3)
                                    nw=true;
                            }

                            if(old && !nw) {
                                bad=true;
                                break;
                            }
                        }

                        if(bad)
                            continue;



                        ll nsame = (find(2)==find(3));

                        ll add=0;

                        if(e1)
                            add += get_cost(a[i-1],b[i]);

                        if(e2)
                            add += get_cost(b[i-1],a[i]);

                        if(e3)
                            add += get_cost(a[i],b[i]);

                        ndp[na][nb][nsame] =
                            max(ndp[na][nb][nsame],
                                dp[da][db][same] + add);
                    }
                }
            }
        }

        for(ll x=0;x<3;x++)
            for(ll y=0;y<3;y++)
                for(ll z=0;z<2;z++)
                    dp[x][y][z]=ndp[x][y][z];
    }

    ll thegrilla = NEG;

    for(ll da=1;da<=2;da++) {
        for(ll db=1;db<=2;db++) {

            thegrilla =
                max(thegrilla, dp[da][db][1]);
        }
    }

    cout << thegrilla << endl;
}

int main() {

    boost;

    ll t=1;
    ll tc=1;

    cin >> t;

    while(t--) {
        solve(tc);
        tc++;
    }

    return 0;
}