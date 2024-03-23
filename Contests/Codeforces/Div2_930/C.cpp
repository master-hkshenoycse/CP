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


    ll a=0,b=0,c=1,d=1;

    ll curr_max=0;
    char ch;
    for(ll i=1;i<n;i++){
        cout<<"? "<<curr_max<<" "<<curr_max<<" "<<i<<" "<<i<<endl;

        cin>>ch;
        
        if(ch=='<'){
            curr_max=i;
        }
    }


    //smallest number whose 'OR' with (n-1) is largest;
    ll curr_largest_or=0;

    
    for(ll i=1;i<n;i++){
        cout<<"? "<<curr_max<<" "<<i<<" "<<curr_max<<" "<<curr_largest_or<<endl;


        cin>>ch;

        if(ch=='>'){
            curr_largest_or=i;
        }else if(ch=='='){
            cout<<"? "<<curr_largest_or<<" "<<curr_largest_or<<" "<<i<<" "<<i<<endl;
            cin>>ch;

            if(ch=='>'){
                curr_largest_or=i;
            }
        }
    }

    cout<<"! "<<curr_max<<" "<<curr_largest_or<<endl;


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