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
ll segtree[1000005];

void build(ll node,ll l,ll r,vector<ll> &v){
    if(l>r){
        return;
    }

    if(l==r){
        segtree[node]=v[l];
        return;
    }

    ll mid=(l+r)/2ll;
    build(node*2,l,mid,v);
    build(node*2+1,mid+1,r,v);
    segtree[node]=min(segtree[node*2],segtree[node*2+1]);
}

ll query(ll node,ll l,ll r,ll st,ll en,ll value){
    if(l>r or st>en or l>en or r<st){
        return 1e9;
    }

    if(l>=st and r<=en){
        if(segtree[node]>=value){
            return 1e9;
        }
        
        ll p=l,q=r;
        ll ret=1e9;
        while(p!=q){
            ll mid=(p+q)/2ll;

            if(segtree[node*2] < value){
                node=node*2;
                q=mid;
            }else{
                node=node*2+1;
                p=mid+1;
            }
        }

        return p;

        
    }

    ll mid=(l+r)/2ll;

    ll q=query(node*2,l,mid,st,en,value);
    if(query(node*2,l,mid,st,en,value)!=1e9){
        return q;
    }

    return query(node*2+1,mid+1,r,st,en,value);
}
void solve(ll tc){
    ll n,c;
    cin>>n>>c;

    vector<ll> a(n+1);
    vector<ll> suffix_largest(n+1);
    vector<ll> value_gt(n+1,0);
    vector<ll> prefix_sum(n+1);
    stack<ll> st;
    for(ll i=1;i<=n;i++){
        cin>>a[i];
        prefix_sum[i]=prefix_sum[i-1]+a[i]+c;
        while(st.size()>0 and a[i]>a[st.top()]){
            st.pop();
        }

        if(st.size()>0){
            value_gt[i]=st.top();
        }

        st.push(i);
    }

    build(1,1,n,prefix_sum);
    for(ll i=n;i>=1;i--){
        suffix_largest[i]=a[i];
        if(i+1<=n){
            suffix_largest[i]=max(suffix_largest[i],suffix_largest[i+1]);
        }
    }

    vector<ll> sol(n+1,n-1);

    ll pref=0;

    //when ith element is the least  index remainig.

    for(ll i=1;i<=n;i++){
        ll curr=pref+a[i]+c;
        if(curr>=suffix_largest[i]){
            sol[i]=min(sol[i],i-1);
        }else{
            sol[i]=min(sol[i],i);
        }
        pref=pref+a[i];
    }
    for(ll i=1;i<=n;i++){

        if(suffix_largest[i]>a[i]){
            continue;
        }

        ll l=value_gt[i]+1,r=i-1;
        sol[i]=min(sol[i],query(1,1,n,l,r,a[i])-1);

    }


    for(ll i=1;i<=n;i++){
        cout<<sol[i]<<" ";
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