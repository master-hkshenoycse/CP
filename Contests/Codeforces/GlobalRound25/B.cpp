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
ll calculate_wins(vector<ll> &a,ll n,ll ind){
    
    ll prev_winner_ind=1;
    ll cnt=0;

    for(ll i=2;i<=n;i++){
        if(a[prev_winner_ind]>a[i]){
            
        }else{
            prev_winner_ind=i;
        }

        if(prev_winner_ind==ind){
            cnt++;
        }
    }

    return cnt;


}
void solve(ll tc){ 
    ll n,k;
    cin>>n>>k;

    vector<ll> a(n+1);

    ll ind_max=1;
    ll first_gt=-1;
    for(ll i=1;i<=n;i++){
        cin>>a[i];

        if(a[ind_max]<a[i] and i<k){
            ind_max=i;
        }

        
    }

    for(ll i=1;i<=n;i++){
        if(first_gt==-1 and a[i]>=a[k]){
            first_gt=i;
        }
    }


    ll ans=calculate_wins(a,n,k);


    swap(a[1],a[k]);
    ans=max(ans,calculate_wins(a,n,1));
    swap(a[1],a[k]);
    
    swap(a[k],a[ind_max]);
    ans=max(ans,calculate_wins(a,n,ind_max));
    swap(a[k],a[ind_max]);
    

    swap(a[k],a[first_gt]);
    ans=max(ans,calculate_wins(a,n,first_gt));
    swap(a[k],a[first_gt]);
    
    cout<<ans<<endl;
    



    

     
}   
int main(){
    boost;

    //pre_cum();
    //prec(20);
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