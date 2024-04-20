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

ll get_sol(set<ll> &c,multiset<ll> &diffs){
    if(c.size()<=2){
        return 0;
    }

    ll ans=(*(--c.end()))-(*(c.begin()));

    ans=ans-*(--diffs.end());

    return ans;
}
void solve(ll tc){
    ll n,q;
    cin>>n>>q;


    //Observations:
    //Always optimal to divide the piles in sorted order
    //the operatiosn required to get piles in 1 place is equal to differnce between highest and lowest cordinate in pile
    //also from brute force solution the optimal anser for n piles will be (x[n-1]-x[0])-(x[i+1]-x[i]);
    //basicllay subtracting the highest differnce between adjacent pair of all n cordinates
    //keeping track of this can give solution in o(nlogn) 

    set<ll> c;
    multiset<ll> diffs;

    ll e;
    for(ll i=1;i<=n;i++){
        cin>>e;
        c.insert(e);
    }

    ll prev=-1;
    for(auto it:c){
        if(prev!=-1){
            diffs.insert(it-prev);
        }
        prev=it;
    }


    
    cout<<get_sol(c,diffs)<<endl;
    set<ll> :: iterator it;

    ll t,x;
    while(q--){
        cin>>t>>x;

        if(t==0){
            it=c.upper_bound(x);

            ll nx_cord=-1;
            if(it != c.end()){
                nx_cord=*it;
                //cout<<nx_cord<<" "<<x<<endl;

                

                //remove the adjacent differnce between n
                diffs.erase(diffs.find(nx_cord-x));
            }

            it=c.lower_bound(x);

            if(it != c.begin()){
                it--;
                diffs.erase(diffs.find(x-*it));

                if(nx_cord != -1){
                    diffs.insert(nx_cord-*it);
                }

            }

            c.erase(x);

        }else{

            it=c.upper_bound(x);

            ll nx_cord=-1,prev_cord=-1;

            if(it != c.end()){
                nx_cord=*it;
            }

            if(it != c.begin()){
                it--;
                prev_cord=*it;
            }

            if(nx_cord != -1 and prev_cord!= -1){
                diffs.erase(diffs.find(nx_cord-prev_cord));
            }

            if(nx_cord != -1){
                diffs.insert(nx_cord-x);
            }

            if(prev_cord != -1){
                diffs.insert(x-prev_cord);
            }

            c.insert(x);
        }

        cout<<get_sol(c,diffs)<<endl;
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