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

    string s,t;
    cin>>s>>t;

    ll c_a=0,c_b=0,c_c=0;

    vector<ll> s_a_ind,t_a_ind,s_c_ind,t_c_ind;

    string tmp_s,tmp_t;

    for(ll i=0;i<n;i++){
        if(s[i]=='a'){
            c_a++;
            s_a_ind.pb(i);
            tmp_s+=s[i];

        }else if(s[i]=='b'){
            c_b++;
        }else{
            c_c++;
            s_c_ind.pb(i);
            tmp_s+=s[i];

        }

        if(t[i]=='a'){
            c_a--;
            t_a_ind.pb(i);
            tmp_t+=t[i];
        }else if(t[i]=='b'){
            c_b--;
        }else{
            c_c--;
            t_c_ind.pb(i);
            tmp_t+=t[i];
        }   

    }

    if(c_a!=0 || c_b!=0 || c_c!=0){
        cout<<"NO"<<endl;
        return;
    }
    

    for(ll i=0;i<s_a_ind.size();i++){
        if(s_a_ind[i] > t_a_ind[i]){
            cout<<"NO"<<endl;
            return;
        }
    }

    for(ll i=0;i<s_c_ind.size();i++){
        if(s_c_ind[i] < t_c_ind[i]){
            cout<<"NO"<<endl;
            return;
        }
    }

    if(tmp_s != tmp_t){
        cout<<"NO"<<endl;
        return;
    }

    cout<<"YES"<<endl;

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