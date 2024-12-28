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

    map<ll,vector<ll> > help;
    vector<ll> a(n);
    vector<ll> p(n,-1),q(n,-1);
    set<ll> av_p,av_q;

    for(ll i=0;i<n;i++){
        cin>>a[i];
        av_p.insert(i+1);
        av_q.insert(i+1);
        help[a[i]].pb(i);
    }

    
    if(help[1].size()>1){
        cout<<"NO"<<endl;
        return;
    }


    for(ll i=1;i<=n;i++){
        if(help[i].size()>2){
            cout<<"NO"<<endl;
            return;
        }

        if(help[i].size()==0){
            continue;
        }

        

        p[*help[i].begin()]=i;
        av_p.erase(i);

        help[i].erase(help[i].begin());

        if(help[i].size()>0){
            q[*help[i].begin()]=i;
            av_q.erase(i);
            help[i].erase(help[i].begin());
        }
    }

    set<ll>::iterator it;
    for(ll i=0;i<n;i++){
        if(p[i]!=-1){
            it=av_q.upper_bound(p[i]);
            if(it != av_q.begin() and av_q.size()>0){
                it--;
                q[i]=*it;
                av_q.erase(q[i]);
            }else{
                cout<<"NO"<<endl;
                return;
            }
        }else{

            it=av_p.upper_bound(q[i]);
            if(it != av_p.begin() and av_p.size()>0){
                it--;
                p[i]=*it;
                av_p.erase(p[i]);
            }else{
                cout<<"NO"<<endl;
                return;
            }



        }
    }

    cout<<"YES"<<endl;
    for(ll i=0;i<n;i++){
        cout<<p[i]<<" ";
    }
    cout<<endl;
    for(ll i=0;i<n;i++){
        cout<<q[i]<<" ";
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