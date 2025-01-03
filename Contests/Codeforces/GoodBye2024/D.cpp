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
ll mod= 998244353;
ll modpow(ll a,ll n){
    ll res=1;
    while(n>0){
        if(n%2){
            res=(res * a)%mod;
        }
        n/=2;
        a=(a * a)%mod;
    }
    return res;
}
void solve(ll tc){
    ll n,q;
    cin>>n>>q;

    vector<arr<ll,2> > a(n),b(n);

    for(ll i=0;i<n;i++){
        cin>>a[i][0];
        a[i][1]=i;
    }

    for(ll i=0;i<n;i++){
        cin>>b[i][0];
        b[i][1]=i;
    }

    sort(all(a));
    sort(all(b));
    ll ret=1;

    vector<ll> pos_a(n),pos_b(n);
    for(ll i=0;i<n;i++){
        ret=ret * min(a[i][0], b[i][0]);
        ret%=mod;
        pos_a[a[i][1]]=i;
        pos_b[b[i][1]]=i;
    }

    cout<<ret<<" ";
    ll ty,ind;

    while(q--){
        cin>>ty>>ind;
        ind--;


        if(ty==1){
            ll curr_pos=pos_a[ind];
            
            ll lo=curr_pos,hi=n-1,target=lo;

            while(hi>=lo){
                ll mid=(hi+lo)/2ll;
                
                if(a[mid][0]==a[curr_pos][0]){
                    target=max(target,mid);
                    lo=mid+1;
                }else{
                    hi=mid-1;
                }
            }

            ll contri;
            contri=min(a[target][0],b[target][0]);
            ret=(ret * modpow(contri,mod-2))%mod;

            contri=min(a[target][0]+1,b[target][0]);
            ret=(ret * contri)%mod;

            swap(a[target],a[curr_pos]);
            a[target][0]++;

            pos_a[a[target][1]]=target;
            pos_a[a[curr_pos][1]]=curr_pos;


            


        }else{
            ll curr_pos=pos_b[ind];

            ll lo=curr_pos,hi=n-1,target=lo;

            while(hi>=lo){
                ll mid=(hi+lo)/2ll;
                
                if(b[mid][0]==b[curr_pos][0]){
                    target=max(target,mid);
                    lo=mid+1;
                }else{
                    hi=mid-1;
                }
            }

            ll contri;
            contri=min(a[target][0],b[target][0]);
            ret=(ret * modpow(contri,mod-2))%mod;

            contri=min(a[target][0],b[target][0]+1);
            ret=(ret * contri)%mod;

            swap(b[target],b[curr_pos]);
            b[target][0]++;

            pos_b[b[target][1]]=target;
            pos_b[b[curr_pos][1]]=curr_pos;


            
        }

        cout<<ret<<" ";



    }

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