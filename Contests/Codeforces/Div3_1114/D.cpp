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
    ll n;
    cin>>n;
    
    vector<pair<ll,ll> >a(n);
    for(ll i=0;i<n;i++){
        cin>>a[i].ff;
        a[i].ss=i;
    }

    sort(a.begin(),a.end());

    ll prev_val=0,prev_cnt=0,prev_sum=0,ls_val=0;
    vector<ll> sol(n,-1);
    ll i=0;
    while(i<n){
        ll cnt=0,j=i;
        while(j<n && a[j].ff==a[i].ff){
            cnt++;
            j++;
        }

        ll req=a[i].ff-prev_sum;
        
        if(i==0 && req>0){
            cout<<-1<<endl;
            return;
        }
        
        if(req>0){
            if(req%prev_cnt){
                cout<<-1<<endl;
                return;
            }

            ll value=req/prev_cnt;
            
            if(value<=prev_val){
                cout<<-1<<endl;
                return;
            }

            prev_val=value;
            prev_sum+=value*prev_cnt;

            for(ll k=i-1;k>=0;k--){
                if(a[k].ff!=a[i-1].ff)
                    break;
                sol[a[k].ss]=prev_val;
            }
        }

        prev_cnt=cnt;
        i=j;
    }

    for(ll i=0;i<n;i++){
        if(sol[i]==-1)
            sol[i]=prev_val+1;
    }


    for(ll i=0;i<n;i++)
        cout<<sol[i]<<" ";
    cout<<endl;
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