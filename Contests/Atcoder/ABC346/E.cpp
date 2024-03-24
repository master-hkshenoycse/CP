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
    ll h,w,m;
    cin>>h>>w>>m;

    vector<ll> row_ops(m+5,0),col_ops(m+5,0);
    map<ll,pair<ll,ll> > row_color,col_color;

    ll t,a,x;
    for(ll i=1;i<=m;i++){
        cin>>t>>a>>x;

        if(t==1){
            row_color[a]={x,i};
            
        }else{
            col_color[a]={x,i};
            
        }
    }

    for(ll i=1;i<=h;i++){
        if(row_color.find(i) != row_color.end()){
            row_ops[row_color[i].ss]++;
        }
    }

    for(ll i=1;i<=w;i++){
        if(col_color.find(i) != col_color.end()){
            col_ops[col_color[i].ss]++;
        }
    }

    for(ll i=m;i>=1;i--){
        row_ops[i]+=row_ops[i+1];
        col_ops[i]+=col_ops[i+1];
    }
    map<ll,ll> sol;


    for(ll i=1;i<=h;i++){
        if(row_color.find(i) == row_color.end()){
            continue;
        }

        ll col=row_color[i].ff;
        ll op_no=row_color[i].ss;
        sol[col]+=(w-col_ops[op_no+1]);
    }

    for(ll i=1;i<=w;i++){
        if(col_color.find(i) == col_color.end()){
            continue;
        }

        ll col=col_color[i].ff;
        ll op_no=col_color[i].ss;

        sol[col]+=(h-row_ops[op_no+1]);
    }

    vector<arr<ll,2> > ans;
    ll tot=0;
    for(auto it:sol){
        if(it.ss>0 and it.ff>0){
            
            tot+=it.ss;
            
            ans.pb({it.ff,it.ss});
        }
    }

    sol[0]=h*w-tot;
    if(sol[0]>0){
        ans.pb({0,sol[0]});
    }
    sort(all(ans));
    cout<<ans.size()<<endl;
    for(auto s:ans){
        cout<<s[0]<<" "<<s[1]<<endl;
    }

}
int main(){
    boost;

    //pre_cum();
    //prec(20);
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