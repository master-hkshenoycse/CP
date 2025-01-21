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

    sort(all(a));    
    set<ll> freq_2,freq_3,freq_1;
    set<ll> x;
    ll i=0;
    while(i<n){
        ll j=i,c=0;

        while(j<n and a[i]==a[j]){
            j++;
            c++;
        }   

        
    

        if(c==4){
            cout<<a[i]<<" "<<a[i]<<" "<<a[i]<<" "<<a[i]<<endl;
            return;
        }


        
        if(freq_2.size()>0 and c==2){
            ll x=(*freq_2.begin());
            ll y=a[i];
            cout<<x<<" "<<x<<" "<<y<<" "<<y<<endl;
            return;
        }

        if(freq_3.size()>0 and (*(--freq_3.end()))*3 > a[i] ){
            ll x=*(--freq_3.end());
            cout<<x<<" "<<x<<" "<<x<<" "<<a[i]<<endl;
            return;
        }

        if(freq_3.size()>0 and )


        if(freq_2.size()>0){
            ll x=*(--freq_2.end());
            freq_2.erase(x);

            ll y=-1;
            if(freq_2.size()>0){
                y=max(y,*(--freq_2.end()));
            }


            if(freq_1.size()>0){
                y=max(y,*(--freq_1.end()));
            }

            if(freq_3.size()>0){
                y=max(y,*(--freq_3.end()));
            }

            if(y!=-1 and 2*x+y>a[i]){
                cout<<x<<" "<<x<<" "<<y<<" "<<a[i]<<endl;
                return;
            }

            freq_2.insert(x);

        }

        if(c>=2 and x.size()>1){
            cout<<a[i]<<" "<<a[i]<<" "<<(*x.begin())<<" "<<(*(--x.end()))<<endl;
            return;
        }
        


        if(c==2)freq_2.insert(a[i]);
        if(c==3)freq_3.insert(a[i]);
        if(c==1)freq_1.insert(a[i]);
        x.insert(a[i]);


        i=j;

        

    }




    cout<<-1<<endl;


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