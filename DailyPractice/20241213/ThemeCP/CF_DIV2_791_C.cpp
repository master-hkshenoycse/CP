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
void upd(ll ind,ll n,ll v,vector<ll> &bit){
    while(ind<=n){
        bit[ind]+=v;
        ind+=(ind & (-ind));
    }
}

ll query(ll ind,vector<ll> &bit){
    ll s=0;
    while(ind>0){
        s=s+bit[ind];
        ind-=(ind & (-ind));
    }
    return s;
}
void solve(ll tc){
    ll n,q;
    cin>>n>>q;
    vector<ll> bit_row(n+5,0),bit_col(n+5,0);
    map<ll,ll> row_rook,col_rook;

    ll ty,x1,y1,x2,y2;
    while(q--){
        cin>>ty;
        if(ty==1){
            cin>>x1>>y1;

            row_rook[x1]++;
            col_rook[y1]++;

            if(row_rook[x1]==1){
                upd(x1,n,1,bit_row);
            }

            if(col_rook[y1]==1){
                upd(y1,n,1,bit_col);
            }

        }else if(ty==2){
            cin>>x1>>y1;

            row_rook[x1]--;
            col_rook[y1]--;

            if(row_rook[x1]==0){
                upd(x1,n,-1,bit_row);
            }

            if(col_rook[y1]==0){
                upd(y1,n,-1,bit_col);
            }


        }else{

            cin>>x1>>y1>>x2>>y2;

            ll row_sum=query(x2,bit_row)-query(x1-1,bit_row);
            ll col_sum=query(y2,bit_col)-query(y1-1,bit_col);

            if(row_sum==x2-x1+1 or col_sum==y2-y1+1){
                cout<<"Yes"<<endl;
            }else{
                cout<<"No"<<endl;
            }
        }
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