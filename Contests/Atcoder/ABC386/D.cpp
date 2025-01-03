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
    ll n,m;
    cin>>n>>m;

    map<ll,vector<ll> > row_blacks,col_blacks,row_whites,col_whites;
    ll x,y;
    char ch;

    set<ll> rows_to_check,cols_to_check;

    while(m--){
        cin>>x>>y>>ch;

        rows_to_check.insert(x);
        cols_to_check.insert(y);

        if(ch=='B'){
            row_blacks[x].push_back(y);
            col_blacks[y].push_back(x);
        }else{
            row_whites[x].push_back(y);
            col_whites[y].push_back(x);
        }

    }

    ll hi=n;

    for(auto r:rows_to_check){
        ll max_black=-1,min_white=1e10;

        for(auto c:row_blacks[r]){
            max_black=max(max_black,c);
        }

        for(auto c:row_whites[r]){
            min_white=min(min_white,c);
        }

        if(max_black > min_white){
            cout<<"No"<<endl;
            return;
        }

        

        ll max_poss=min(n,max(max_black,min_white-1));
        ll min_poss=max_black;

       
        if(min_poss>hi){
            cout<<"No"<<endl;
            return;
        }

        hi=min(hi,max_poss);


    }

    hi=n;

    for(auto r:cols_to_check){
        ll max_black=-1,min_white=1e10;

        for(auto c:col_blacks[r]){
            max_black=max(max_black,c);
        }

        for(auto c:col_whites[r]){
            min_white=min(min_white,c);
        }

        if(max_black > min_white){
            cout<<"No"<<endl;
            return;
        }

        ll max_poss=min(n,max(max_black,min_white-1));
        ll min_poss=max_black;

     



        if(min_poss>hi){
            cout<<"No"<<endl;
            return;
        }

        hi=min(hi,max_poss);


    }

    cout<<endl;



    cout<<"Yes"<<endl;

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