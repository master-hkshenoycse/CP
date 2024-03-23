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

/*https://codeforces.com/contest/1932/submission/248093044*/
void solve(ll tc){ 

    ll n;
    cin>>n;

    char ch;
    cin>>ch;


    map<char,vector<string> >help;

    string s;

    ll trumps=0;
    

    for(ll i=1;i<=2*n;i++){

        cin>>s;
        
        help[s[1]].pb(s);

        if(s[1]==ch){
            trumps++;
        }
    }


    
    
    vector<pair<string,string> > sol;
    vector<string> rem;

    for(auto it:help){

        if(it.first==ch){
            continue;
        }

        ll sz=it.second.size();
        

        if(sz%2){
            rem.pb(it.second.back());
        }

        for(ll i=0;i+1<sz;i+=2){
            sol.pb({it.second[i],it.second[i+1]});
        }

    }

    if(rem.size()>trumps){
        cout<<"IMPOSSIBLE"<<endl;
        return;
    }else{
        while(rem.size()>0){
            sol.pb({rem.back(),help[ch].back()});
            rem.pop_back();
            help[ch].pop_back();
        }
    }


    ll sz=help[ch].size();
    for(ll i=0;i<sz;i+=2){
        sol.pb({help[ch][i],help[ch][i+1]}); 
    }
    
    for(auto &it:sol){

        string p1=it.first;
        string p2=it.second;

        if(p1[1]==p2[1]){
            if(p1>p2){
                swap(p1,p2);
            }
        }
           
        cout<<p1<<" "<<p2<<endl;
    }

    




    


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