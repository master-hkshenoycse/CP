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

    string s;
    cin>>s;

    vector<ll> cnt(26,0);
    for(ll i=0;i<n;i++){
        cnt[s[i]-'a']++;
    }   

    
    for(ll i=0;i<n;i++){
        ll mx_freq=0,mx_ind=-1;
        if(i==0){
            for(ll j=0;j<26;j++){
                if(mx_freq<cnt[j]){
                    mx_freq=cnt[j];
                    mx_ind=j;
                }
            }
        }else if(i==1){
            for(ll j=0;j<26;j++){
                if(mx_freq<cnt[j] and j!= s[i-1]-'a'){
                    mx_freq=cnt[j];
                    mx_ind=j;
                }
            }

            if(mx_ind==-1){
                for(ll j=0;j<26;j++){
                    if(mx_freq<cnt[j]){
                    mx_freq=cnt[j];
                    mx_ind=j;
                    }
                }
            }


        }else{
            for(ll j=0;j<26;j++){
                if(mx_freq<cnt[j] and j!= s[i-1]-'a' and j!=s[i-2]-'a'){
                    mx_freq=cnt[j];
                    mx_ind=j;
                }
            }

            if(mx_ind==-1){
                for(ll j=0;j<26;j++){
                    if(mx_freq<cnt[j] and j!= s[i-1]-'a'){
                        mx_freq=cnt[j];
                        mx_ind=j;
                    }
                }
            }

            if(mx_ind==-1){
                for(ll j=0;j<26;j++){
                    if(mx_freq<cnt[j]){
                        mx_freq=cnt[j];
                        mx_ind=j;
                    }
                }
            }


        }

        cnt[mx_ind]--;
        s[i]=char('a'+mx_ind);
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