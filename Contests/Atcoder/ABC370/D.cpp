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
    ll h,w,q;
    cin>>h>>w>>q;

    set<ll> walls_row[h+1],walls_col[w+1];

    for(ll i=1;i<=h;i++){
        for(ll j=1;j<=w;j++){
            walls_row[i].insert(j);
            walls_col[j].insert(i); 
        }
    }

    set<ll>::iterator it;
    ll x,y;
    ll ans=h*w;

    while(q--){
        cin>>x>>y;

        if(walls_row[x].size()>0){
            it=walls_row[x].find(y);
            if(it != walls_row[x].end()){
                walls_row[x].erase(y);
                walls_col[y].erase(x);
                ans--;
                continue;
            }
        }
        

        if(walls_row[x].size()>0){

            //find the next to right;
            it=walls_row[x].upper_bound(y);
            if(it != walls_row[x].end()){
                ll y_=*it;
                walls_row[x].erase(y_);
                walls_col[y_].erase(x);
                ans--;
            }

        }

        if(walls_row[x].size()>0){

            //find the previous to left
            it=walls_row[x].lower_bound(y);
            if(it!=walls_row[x].begin()){
                it--;
                ll y_=*it;
                walls_row[x].erase(y_);
                walls_col[y_].erase(x);
                ans--;   
            }

        }


        if(walls_col[y].size()>0){

             //find the wall next row in same column
            it=walls_col[y].lower_bound(x);
            if(it!=walls_col[y].end()){
                ans--;
                ll x_=*it;
                walls_col[y].erase(x_);
                walls_row[x_].erase(y);
            }


        }

        if(walls_col[y].size()>0){
            //find the wall in previous column
            it=walls_col[y].lower_bound(x);
            if(it!=walls_col[y].begin()){
                it--;
                ans--;
                ll x_=*it;
                walls_col[y].erase(x_);
                walls_row[x_].erase(y);
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
    //cin>>t;

	while(t--){
		solve(tc);
        tc++;
    
	}

    return 0;
    
     
}