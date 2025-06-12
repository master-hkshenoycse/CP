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
struct trie_node{
    trie_node *child[2];
    ll max_ind=-1;

    trie_node(){
        child[0]=NULL;
        child[1]=NULL;
        max_ind=-1;
    }
};
void insert(trie_node *root,ll val,ll index){
    for(ll i=30;i>=0;i--){
        ll req=0;
        if(val & (1ll<<i)){
            req=1;
        }

        if(root->child[req]==NULL){
            root->child[req]=new trie_node();
        }

        root=root->child[req];
        root->max_ind=index;
    }
}


ll search_max(trie_node *root,ll val,ll k){
    ll already_big=0,ret=-1;

    for(ll i=30;i>=0;i--){
        ll curr_bit = ((k & (1ll<<i))>0);
        ll val_bit  = ((val & (1ll<<i))>0);

        if(curr_bit){
            if(already_big){
                if(root->child[0] != NULL)
            }else{
                
                if(root->child[1-val_bit]==NULL){
                    return -1;
                }         

                root=root->child[1-val_bit];
                ret = root->max_ind;
            }
        }else{
            if(already_big){
                if(root->child)
            }else{
                ll 
            }
        }
        
    }
    return ret;

}
void solve(ll tc){
    ll n,k;
    cin>>n>>k;

    

    vector<ll> a(n);
    for(ll i=0;i<n;i++){
        cin>>a[i];
    }


    ll ans=-1;
    trie_node *root = new trie_node();

    for(ll i=0;i<n;i++){
        insert(root,a[i],i);
        int ret=search_max(root,a[i],k);
        if(ret>=0){
            ans=max(ans,i-ret+1);
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
