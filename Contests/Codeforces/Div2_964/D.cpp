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

    vector<ll> a(n+1);
    vector<ll> is_last_pos(n+1,0);
    set<ll> is_present;

    for(ll i=1;i<=n;i++){
        cin>>a[i];
    }

    for(ll i=n;i>=1;i--){
        if(is_present.count(a[i])==0){
            is_last_pos[i]=1;
            is_present.insert(a[i]);
        }
    }

    vector<ll> res;
    set<ll> taken,available;
    vector<vector<ll> > indexes_(n+1);
    ll take_big=1;
    ll last_taken=0;


    for(ll i=1;i<=n;i++){

        //element already taken ignore;
        if(taken.count(a[i])>0){
            continue;
        }

        //insert the element in the available set, i.e to be picked in future.
        available.insert(a[i]);
        indexes_[a[i]].push_back(i);
        
        if(is_last_pos[i]==0){
            continue;//this element will occur in iteration afterwards as well, so expand the available set as big as possible.
        }

        //as i is the last position of the value a[i] iterating till a[i] is not picked.  
        while(taken.count(a[i])==0){
            int ele;


            //remove those element whose previous occurence was befothe last element in subsequence so far.
            if(take_big){

                ele=*available.rbegin();
                while(indexes_[ele].back() < last_taken){
                    available.erase(ele);
                    ele=*available.rbegin();
                }

            }else{

                ele=*available.begin();
                while(indexes_[ele].back() <last_taken){
                    available.erase(ele);
                    ele=*available.begin();
                }

            }

            

            res.push_back(ele);
            last_taken=*upper_bound(all(indexes_[ele]),last_taken);
            taken.insert(ele);
            available.erase(ele);
            take_big=1-take_big;
        }

    }

    cout<<res.size()<<endl;
    for(auto e:res){
        cout<<e<<" ";
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