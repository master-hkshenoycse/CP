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
    
    ll n,m,v;
    cin>>n>>m>>v;
    vector<ll> a(n+1),csum(n+1,0);
    vector<ll> pref_pieces(n+1,0),suff_pieces(n+2,0);


    ll cnt=0,cs=0,i=0;
    for(ll i=1;i<=n;i++){
        cin>>a[i];
        cs=cs+a[i];
        csum[i]=csum[i-1]+a[i];
        if(cs>=v){
            cnt++;
            cs=0;
        }
        pref_pieces[i]=cnt;
    }

    if(cnt<m){
        cout<<-1<<endl;
        return;
    }

    cs=0,cnt=0;
    for(ll i=n;i>=1;i--){
        cs=cs+a[i];
        if(cs>=v){
            cnt++;
            cs=0;
        }

        suff_pieces[i]=cnt;
    }

    ll ans=0;
    for(ll i=1;i<=n;i++){
        ll req=m-pref_pieces[i-1];
        ll lo=i,hi=n,r=i-1;

        while(hi>=lo){
            ll mid=(hi+lo)/2ll;
            if(suff_pieces[mid+1] >= req){
                r=max(r,mid);
                lo=mid+1;
            }else{
                hi=mid-1;
            }
        }

        ans=max(ans,csum[r]-csum[i-1]);
    }

    for(ll i=n;i>=1;i--){
        if(suff_pieces[i]>=m){
            ans=max(ans,csum[i-1]);
        }
    }

    for(ll i=1;i<=n;i++){
        if(pref_pieces[i]>=m){
            ans=max(ans,csum[n]-csum[i]);
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
    cin>>t;

	while(t--){
		solve(tc);
        tc++;
    
	}

    return 0;
    
     
}