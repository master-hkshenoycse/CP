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
vector<int> get_lps(string &s){
    int n = s.size();
    vector <int> lps(n+1,0);
    int len=0,i=1;
    
    
    while(i<n){
        if(s[len]==s[i]){
            lps[i]=len+1;
            len++;
            i++;
        }else{
            if(len)len=lps[len-1];
            else{
                lps[i]=0;
                i++;
            }
        }
    }
    return lps;
        
}

bool check(string &s,ll len_prefix,ll count_req){
    string pattern=s.substr(0,len_prefix);

    vector<int> lps=get_lps(pattern);
    vector<int> occ;

    ll i=0,j=0,n=s.size(),m=len_prefix;

    while(i<n){
        if(s[i]==pattern[j]){
            i++;
            j++;
        }else{
            if(j!=0)j=lps[j-1];
            else i++;
        }


        if(j==m){
            occ.pb(i-j);
            j=lps[j-1];
        }

    }




    ll cnt=0;
    ll prev=-1e9;

    for(auto o:occ){
        if(o-prev>=len_prefix){
            cnt++;
            prev=o;
        }
    }


    return cnt>=count_req;
}
void solve(ll tc){
    ll n,l,r;
    cin>>n>>l>>r;

    string s;
    cin>>s;

    ll lo=1,hi=n,ans=0;

    while(hi>=lo){
        ll mid=(hi+lo)/2ll;
        if(check(s,mid,l)){
            ans=max(ans,mid);
            lo=mid+1;
        }else{
            hi=mid-1;
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