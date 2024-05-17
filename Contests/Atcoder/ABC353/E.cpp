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
    trie_node *child[26];
    ll cnt=0;

    trie_node(){
        for(ll i=0;i<26;i++){
            child[i]=NULL;
        }
        cnt=0;
    }
};
void insert(trie_node *root,string &s){
    ll n=s.size();

    for(ll i=0;i<n;i++){
        if(root->child[s[i]-'a']==NULL){
            root->child[s[i]-'a']=new trie_node();
        }
        root=root->child[s[i]-'a'];
        root->cnt++;//keeps track of howmany prefix are there 
    }
}

void upd_ans(trie_node *root,string &s,ll &ans){
    ll n=s.size();

    for(ll i=0;i<n;i++){
        if(root->child[s[i]-'a']==NULL){
            return;
        }

        root=root->child[s[i]-'a'];
        ans=ans+root->cnt;//contibution of ith index to ans;
    }
}
void solve(ll tc){
    ll n;
    cin>>n;


    vector<string> a(n);
    for(ll i=0;i<n;i++){
        cin>>a[i];
    }

    trie_node *root=new trie_node();
    ll ans=0;

    for(ll i=n-1;i>=0;i--){
        upd_ans(root,a[i],ans);
        insert(root,a[i]);
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
    //cin>>t;

	while(t--){
		solve(tc);
        tc++;
    
	}

    return 0;
    
     
}