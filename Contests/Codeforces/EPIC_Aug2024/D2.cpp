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

bool check(ll v,set<ll> &sons,vector<ll> &subtree_sz,vector<ll> &pos,vector<ll> &perm){
    if(sons.size()==0){
        return 1;
    }

    ll least_pos=*sons.begin();
    ll last_pos=*(--sons.end());
    

    //each children should 
    if(least_pos < pos[v]){
        return 0;
    }

    if(last_pos+subtree_sz[perm[last_pos]]>pos[v]+subtree_sz[v]){
        return 0;
    }

    return 1;
    
    
}
void solve(ll tc){
    ll n,q;
    cin>>n>>q;

    vector<ll> pos(n+1),perm(n+1),father(n+1),subtree_sz(n+1,1);
    vector< set<ll> > sons(n+1);

    for(ll i=2;i<=n;i++){
        cin>>father[i];
    }

    for(ll i=n;i>=2;i--){
        subtree_sz[father[i]]+=subtree_sz[i];
    }


    for(ll i=1;i<=n;i++){
        cin>>perm[i];
        pos[perm[i]]=i;
        sons[father[perm[i]]].insert(i);
    }
    
    ll cnt=0;
    for(ll i=1;i<=n;i++){
        cnt=cnt+check(i,sons[i],subtree_sz,pos,perm);
    }

    ll x,y;
    while(q--){
        cin>>x>>y;
        ll val_x=perm[x];
        ll val_y=perm[y];

        set<ll> changed;
        changed.insert(val_x);
        changed.insert(val_y);
        changed.insert(father[val_x]);
        changed.insert(father[val_y]);

        for(auto c:changed){
            cnt=cnt-check(c,sons[c],subtree_sz,pos,perm);
        }

        sons[father[val_x]].erase(x);
        sons[father[val_y]].erase(y);   

        sons[father[val_x]].insert(y);
        sons[father[val_y]].insert(x);




        swap(perm[x],perm[y]);
        swap(pos[val_x],pos[val_y]);

        for(auto c:changed){
            cnt=cnt+check(c,sons[c],subtree_sz,pos,perm);
        }

        if(cnt==n){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
        
    }

    

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