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
    ll n,m,sx,sy;
    cin>>n>>m>>sx>>sy;

    vector<vector<ll> > c(n,vector<ll> (2));
    map<ll,vector<arr<ll,3> > > events_x;
    map<ll,vector<arr<ll,3> > > events_y; 

    for(ll i=0;i<n;i++){
        cin>>c[i][0]>>c[i][1];
        events_x[c[i][0]].push_back({c[i][1],2,i});
        events_y[c[i][1]].push_back({c[i][0],2,i});
    }


    char ch;
    ll mag;

    while(m--){
        cin>>ch>>mag;

        if(ch=='U'){
            events_x[sx].push_back({sy,1,-1});
            events_x[sx].push_back({sy+mag,-1,-1});
            sy+=mag;
        }else if(ch=='D'){
            events_x[sx].push_back({sy,-1,-1});
            events_x[sx].push_back({sy-mag,1,-1});
            sy-=mag;
        }else if(ch=='L'){
            events_y[sy].push_back({sx,-1,-1});
            events_y[sy].push_back({sx-mag,1,-1});
            sx-=mag;
        }else if(ch=='R'){
            events_y[sy].push_back({sx,1,-1});
            events_y[sy].push_back({sx+mag,-1,-1});
            sx+=mag;
        }
    }

    set<ll> houses;
    map<ll,vector<arr<ll,3> > > :: iterator it;

    for(it=events_x.begin();it!=events_x.end();it++){
        sort(it->ss.begin(),it->ss.end());
        ll cs=0;

        for(auto ev:it->ss){
            if(ev[1]==1){
                cs++;
            }
        }

        for(auto ev:it->ss){
            if(ev[1]==2){
                if(cs>0){
                    houses.insert(ev[2]);
                }
            }
        }

        for(auto ev:it->ss){
            if(ev[1]==-1){
                cs--;
            }
        }


    }

    for(it=events_y.begin();it!=events_y.end();it++){
        sort(it->ss.begin(),it->ss.end());
        ll cs=0;

        for(auto ev:it->ss){
            if(ev[1]==1){
                cs++;
            }
        }

        for(auto ev:it->ss){
            if(ev[1]==2){
                if(cs>0){
                    houses.insert(ev[2]);
                }
            }
        }

        for(auto ev:it->ss){
            if(ev[1]==-1){
                cs--;
            }
        }

    }

    cout<<sx<<" "<<sy<<" "<<houses.size()<<endl;
    

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