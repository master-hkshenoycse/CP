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
ll dp[35][2];
struct trie_node{
    trie_node *child[2];
    vector<ll> indexes;

    trie_node(){
        child[0]=NULL;
        child[1]=NULL;
        indexes.clear();
    }
};

void go(trie_node *root,ll p){
    
    if(root==NULL or p<0){
        return;
    }

    go(root->child[0],p-1);
    go(root->child[1],p-1);

    if(root->child[0]==NULL or root->child[1]==NULL){
        return;
    }

    //if current bit is swapped then left and right will be swapped, causing the change in inversions
    ll sz_l=root->child[0]->indexes.size();
    ll sz_r=root->child[1]->indexes.size();

    ll inv_count=0;//keeps track of current inversion count
    ll ptr=0;//keep track of index in sz_r less than current 

    for(ll i=0;i<sz_l;i++){
        while(ptr<sz_r and root->child[1]->indexes[ptr]<root->child[0]->indexes[i]){
            ptr++;
        }
        inv_count+=ptr;
    }

    dp[p][0]+=inv_count;//if not swapped inversion count wont chnage
    dp[p][1]+=(sz_l*sz_r-inv_count);

}
void insert_element(trie_node *root,ll e,ll ind){
    
    for(ll i=29;i>=0;i--){
        if(e & (1ll<<i)){
            if(root->child[1]==NULL){
                root->child[1]=new trie_node();
            }
            root=root->child[1];
            root->indexes.pb(ind);
        }else{
            if(root->child[0]==NULL){
                root->child[0]=new trie_node();
            }
            root=root->child[0];
            root->indexes.pb(ind);
        }
    }
}
void solve(ll tc){
    ll n;
    cin>>n;

    trie_node *root=new trie_node();

    ll e;
    for(ll i=1;i<=n;i++){
        cin>>e;
        insert_element(root,e,i);
    }

    go(root,29);

    ll ans=0,cnt=0;
    for(ll i=29;i>=0;i--){
        cnt+=min(dp[i][1],dp[i][0]);
        if(dp[i][1]<dp[i][0]){
            ans=ans+(1ll<<i);
        }
    }

    cout<<cnt<<" "<<ans<<endl;


}
int main(){
    boost;

    //pre_cum();
    //prec(10);
	//fre;


    ll t=1;
    ll tc=1;
    //cin>>t;

	while(t--){
		solve(tc);
        tc++;
    
	}

    return 0;
    
     
}