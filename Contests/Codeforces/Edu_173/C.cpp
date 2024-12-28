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
vector<ll> get_range(vector<ll> &a){
    if(a.size()==0){
        return {0,0,0,0,0,0};
    }

    ll min_poss=1e18;
    ll max_poss=-1e18;
    ll cs_min=0;
    ll cs_max=0;
    ll cs=0;

    ll ls_min=0,ls_max=0;
    ll fs_min=0,fs_max=0;
    ll tot=0;

    for(auto e:a){
        cs=cs+e;
        min_poss=min(min_poss,cs-cs_max);
        max_poss=max(max_poss,cs-cs_min);   
        ls_min=cs-cs_max;
        ls_max=cs-cs_min; 
        tot+=e;


        cs_max=max(cs_max,cs);
        cs_min=min(cs_min,cs);
    }

    
    cs=0;
    cs_min=0;
    cs_max=0;
    reverse(all(a));

    for(auto e:a){
        cs=cs+e;
        cs_min=min(cs_min,cs);
        cs_max=max(cs_max,cs);
    }
    


    

    return {min_poss,max_poss,ls_min,ls_max,tot-cs_max,tot-cs_min};
}
void solve(ll tc){
    ll n;
    cin>>n;

    vector<ll> a(n);
    ll s=0;
    ll index_not_1=-1;
    for(ll i=0;i<n;i++){
        cin>>a[i];
        s+=a[i];
        if(abs(a[i])!=1){
            index_not_1=i;
        }
    }

    set<ll> sol;
    sol.insert(0);
    sol.insert(s);

    if(index_not_1 == -1){
        vector<ll> p_lim=get_range(a);
        for(ll i=p_lim[0];i<=p_lim[1];i++){
            sol.insert(i);
        }

    }else{

        vector<ll> p,q;
        for(ll i=0;i<n;i++){

            if(i<index_not_1){
                p.pb(a[i]);
            }

            if(i>index_not_1){
                q.pb(a[i]);
            }

        }


        vector<ll> p_lim=get_range(p);
        vector<ll> q_lim=get_range(q);
        

        for(ll i=p_lim[0];i<=p_lim[1];i++){
            sol.insert(i);
        }

        for(ll i=q_lim[0];i<=q_lim[1];i++){
            sol.insert(i);
        }

        sol.insert(a[index_not_1]);
        
        ll lo=p_lim[2]+q_lim[4];
        ll hi=p_lim[3]+q_lim[5];

        for(ll i=lo;i<=hi;i++){
            sol.insert(a[index_not_1]+i);
        }

        for(ll i=p_lim[2];i<=p_lim[3];i++){
            sol.insert(i+a[index_not_1]);
        }

        for(ll i=q_lim[4];i<=q_lim[5];i++){
            sol.insert(i+a[index_not_1]);
        }
    }

    cout<<sol.size()<<endl;
    for(auto s:sol){
        cout<<s<<" ";
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