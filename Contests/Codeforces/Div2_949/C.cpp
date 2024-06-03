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
ll get_lca(ll x,ll y){
    
    while(x!=y){
        if(x>y){
            x/=2;
        }else{
            y/=2;
        }
    }

    return x;
}

vector<ll> get_path(ll x,ll y){
    vector<ll> sol;

    ll lc=get_lca(x,y);
    

    vector<ll> x_lc,lc_y;
    
    
    

    while(x != lc){
        x_lc.pb(x);
        x/=2;
    }
    
    
    x_lc.pb(lc);

    while(y!=lc){
        lc_y.pb(y);
        y/=2;
    }


    

    reverse(all(lc_y));

    vector<ll> path;
    for(auto e:x_lc){
        path.pb(e);
    }

    for(auto e:lc_y){
        path.pb(e);
    }
    
    if(path.size()>0){
        path.erase(path.begin());
    }



    return path;


}
bool check(vector<ll> &a){
    ll n=a.size()-1;

    for(ll i=1;i+1<=n;i++){
        if(a[i]==a[i+1]/2 or a[i+1]==a[i]/2){
            continue;

        }else{

            return 0;
        }
    }

    return 1;
}
void solve(ll tc){
    ll n;
    cin>>n;

    vector<ll> a(n+1);
    

    ll cnt_neg_1=0;
    for(ll i=1;i<=n;i++){
        cin>>a[i];
        cnt_neg_1+=(a[i]==-1);
    }

    if(cnt_neg_1==n){
        for(ll i=1;i<=n;i++){
            if(i%2){
                cout<<1<<" ";
            }else{
                cout<<2<<" ";
            }
        }

        cout<<endl;
        return;
    }

    ll i=1;
    while(i<=n){
        if(a[i]==-1){
            ll c=0,j=i;
            while(j<=n and a[i]==a[j]){
                c++;
                j++;
            }

            

            if(i==1){
                ll ch=0;
                for(ll k=j-1;k>=1;k--){
                    if(ch==0){
                        a[k]=a[k+1]*2;
                    }else{
                        a[k]=a[k+1]/2;
                    }
                    ch=1-ch;
                }

            }else if(j>n){
                ll ch=0;

                for(ll k=i;k<=n;k++){
                    if(ch==0){
                        a[k]=a[k-1]*2;
                    }else{
                        a[k]=a[k-1]/2;
                    }
                    ch=1-ch;
                }

            }else{

                ll len=c+1;
                vector<ll> path=get_path(a[i-1],a[j]);
                ll path_size=path.size();
                /*cout<<i<<" "<<len<<" "<<path_size<<endl;
                for(auto p:path){
                    cout<<p<<" ";
                }
                cout<<endl;*/

                if((path_size%2) != (len%2)){//cant get equal to jth element
                    cout<<-1<<endl;
                    return;
                }

                

                if(path_size > len){// not enough blanks to do operation
                    cout<<-1<<endl;
                    return;
                }

                ll ch=0,curr=0;
                for(ll k=i;k<j;k++){
                    if(curr<path.size()){
                        a[k]=path[curr];
                        curr++;
                    }else{
                        if(ch==0){
                            a[k]=a[k-1]*2;
                        }else{
                            a[k]=a[k-1]/2;
                        }
                        ch=1-ch;
                    }
                }

            }

            i=j;

        }else{
            i++;
        }
    }

    

    if(check(a)==0){
        cout<<-1<<endl;
        return;
    }

    for(ll i=1;i<=n;i++){
        cout<<a[i]<<" ";
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