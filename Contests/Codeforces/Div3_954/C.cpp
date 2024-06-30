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
ll dx[4]={-1,1,0,0};
ll dy[4]={0,0,-1,1};
void solve(ll tc){

    ll n,m;
    cin>>n>>m;

    string s;
    cin>>s;

    vector<ll> ind_cnt(n,0);
    vector<ll> char_cnt(26,0);

    ll ind;
    for(ll i=0;i<m;i++){
        cin>>ind;
        ind_cnt[ind-1]++;
    }

    string tmp;
    cin>>tmp;

    for(auto ch:tmp){
        char_cnt[ch-'a']++;
    }

    for(ll i=0;i<n;i++){
        if(ind_cnt[i]>0){
            for(ll j=0;j<26;j++){
                if(char_cnt[j]>0){
                    ind_cnt[i]--;
                    s[i]=char('a'+j);
                    char_cnt[j]--;
                    break;
                }
            }

            for(ll j=25;j>=0;j--){
                ll sub=min(char_cnt[j],ind_cnt[i]);
                ind_cnt[i]-=sub;
                char_cnt[j]-=sub;
            }
        }
    }

    cout<<s<<endl;

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