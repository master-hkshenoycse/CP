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
    ll n,k;
    cin>>n>>k;

    vector<ll> a(n);
    for(ll i=0;i<n;i++){
        cin>>a[i];
    }

    ll ans=0;

    for(ll i=0;i<n;i++){

        vector<ll> prev,ahead;

        for(ll j=0;j<i;j++){
            prev.push_back(a[j]);
        }

        for(ll j=i+1;j<n;j++){
            ahead.push_back(a[j]);
        }

        sort(all(ahead));
        sort(all(prev));
        reverse(all(ahead));
        reverse(all(prev));

        ll tot=0;

        if(i==0){
            for(ll j=0;j<k;j++){
                tot+=ahead[j];
            }
            ans=max(ans,tot+a[i]);
        }else if(i==n-1){
            for(ll j=0;j<k;j++){
                tot+=prev[j];
            }
            ans=max(ans,tot+a[i]);
        }else{


            if(k==1){
                continue;
            }

            ll rem=k;

            ll p_ind=0,a_ind=0;
            
            rem--;
            tot+=prev[p_ind];
            p_ind++;

            rem--;
            tot+=ahead[a_ind];
            a_ind++;


            while(rem>0){
                if(p_ind==prev.size()){
                    tot+=ahead[a_ind];
                    a_ind++;
                }else if(a_ind==ahead.size()){
                    tot+=prev[p_ind];
                    p_ind++;
                }else{  

                    if(prev[p_ind] > ahead[a_ind]){
                        tot+=prev[p_ind];
                        p_ind++;
                    }else{
                        tot+=ahead[a_ind];
                        a_ind++;
                    }
                }

                rem--;
            }

            ans=max(ans,tot+a[i]);

            
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