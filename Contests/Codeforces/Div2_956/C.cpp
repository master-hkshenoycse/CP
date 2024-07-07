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
vector<ll> get_sol(vector<ll> &choice,vector<vector<ll> >&a,ll n,ll tot){

    ll curr=0;
    ll req=(tot+2)/3;
    for(ll i=1;i<=n;i++){
        curr=a[choice[0]][i];
        if(a[choice[0]][i]>=req){

            ll lo=i+1;
            ll hi=n-1;
            ll r=n;

            while(hi>=lo){
                ll mid=(hi+lo)/2ll;
                if(a[choice[1]][mid]-a[choice[1]][i]>=req){
                    r=min(r,mid);
                    hi=mid-1;
                }else{
                    lo=mid+1;
                }
            }

            if(r<n and a[choice[2]][n]-a[choice[2]][r]>=req){

                vector<ll> ret(6);
                
                if(choice[0]==0){
                    ret[0]=1;
                    ret[1]=i;
                }else if(choice[0]==1){
                    ret[2]=1;
                    ret[3]=i;
                }else{
                    ret[4]=1;
                    ret[5]=i;
                }

                if(choice[1]==0){
                    ret[0]=i+1;
                    ret[1]=r;
                }else if(choice[1]==1){
                    ret[2]=i+1;
                    ret[3]=r;
                }else{
                    ret[4]=i+1;
                    ret[5]=r;
                }


                if(choice[2]==0){
                    ret[0]=r+1;
                    ret[1]=n;
                }else if(choice[2]==1){
                    ret[2]=r+1;
                    ret[3]=n;                    
                }else{
                    ret[4]=r+1;
                    ret[5]=n;
                }
                


                return ret;




            }



        }

    }

    return {-1};
}
void solve(ll tc){
    ll n;
    cin>>n;
    vector<vector<ll> > a(3,vector<ll> (n+1,0));

    ll tot=0;
    
    for(ll i=1;i<=n;i++){
        cin>>a[0][i];
        tot+=a[0][i];
        a[0][i]+=a[0][i-1];
    }

    for(ll i=1;i<=n;i++){
        cin>>a[1][i];
        a[1][i]+=a[1][i-1];
    }

    for(ll i=1;i<=n;i++){
        cin>>a[2][i];
        a[2][i]+=a[2][i-1];
    }

    vector<ll> choice(3);
    choice[0]=0;
    choice[1]=1;
    choice[2]=2;

    do{
        vector<ll> v=get_sol(choice,a,n,tot);
        if(v.size()==6){
            cout<<v[0]<<" "<<v[1]<<" "<<v[2]<<" "<<v[3]<<" "<<v[4]<<" "<<v[5]<<endl; 
            return;
        }
    }while(next_permutation(all(choice)));


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