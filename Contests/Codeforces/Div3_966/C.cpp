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

    vector<ll> a(n);
    for(ll i=0;i<n;i++){
        cin>>a[i];
    }

    ll q;
    cin>>q;

    while(q--){
        string s;
        cin>>s;

        if(s.size() != n){
            cout<<"NO"<<endl;
            continue;
        }

        map<char,ll> char_to_int;
        map<ll,char> int_to_char;

        ll poss=1;

        for(ll i=0;i<n;i++){
            ll curr_int=a[i];
            char curr_ch=s[i];

            if(char_to_int.find(curr_ch) != char_to_int.end()){
                if(char_to_int[curr_ch] != curr_int){
                    poss=0;
                    break;
                }
            }

            if(int_to_char.find(curr_int) != int_to_char.end()){
                if(int_to_char[curr_int] != curr_ch){
                    poss=0;
                    break;
                }
            }

            char_to_int[curr_ch]=curr_int;
            int_to_char[curr_int]=curr_ch;


        }


        if(poss){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
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
    cin>>t;

	while(t--){
		solve(tc);
        tc++;
    
	}

    return 0;
    
     
}