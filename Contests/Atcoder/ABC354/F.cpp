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
ll tree[900005];
void upd(ll index,ll l,ll r,ll node,ll val){
    if(l>r){
        return;
    }

    if(l==r){
        tree[index]=val;
        return;
    }

    ll mid=(l+r)/2ll;
    if(node<=mid){
        upd(index*2,l,mid,node,val);
    }else{
        upd(index*2+1,mid+1,r,node,val);
    }

    tree[index]=max(tree[index*2],tree[index*2+1]);
}

ll query(ll index,ll l,ll r,ll st,ll en){
    if(l>r or r<st or l>en){
        return 0;
    }

    if(l>=st and r<=en){
        return tree[index];
    }

    ll mid=(l+r)/2ll;

    return max(query(index*2,l,mid,st,en),query(index*2+1,mid+1,r,st,en));
}

void solve(ll tc){

    ll n;
    cin>>n;

    vector<ll> a(n+1);
    map<ll,ll> help;
    for(ll i=1;i<=n;i++){
        cin>>a[i];
        help[a[i]]++;
    }

    ll c=0;
    for(auto &it:help){
        c++;
        it.ss=c;
    }


    for(ll i=1;i<=n;i++){
        a[i]=help[a[i]];
    }

    ll lis=0;
    vector<ll> dp_prefix(n+1,1),dp_suffix(n+1,1);

    for(ll i=1;i<=n;i++){
        ll value=query(1,1,c,1,a[i]-1);
        lis=max(lis,value+1);
        dp_prefix[i]=value+1;
        upd(1,1,c,a[i],dp_prefix[i]);
    }

    for(ll i=1;i<=c+2;i++){
        upd(1,1,c,i,0);
    }

    vector<ll> sol;
    for(ll i=n;i>=1;i--){
        ll value=query(1,1,c,a[i]+1,c);
        dp_suffix[i]=value+1;

        if(lis==dp_prefix[i]+dp_suffix[i]-1){
            sol.pb(i);
        }

        upd(1,1,c,a[i],dp_suffix[i]);
    }

    reverse(all(sol));
    cout<<sol.size()<<endl;
    for(auto s:sol){
        cout<<s<<" ";
    }
    cout<<endl;

    for(ll i=1;i<=c+2;i++){
        upd(1,1,c,i,0);
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