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
struct node{
    node *prev,*next;
    ll data;

    node(ll d){
        data=d;
        prev=NULL;
        next=NULL;
    }
};

void solve(ll tc){ 
    node *st=new node(-1);
    node *en=new node(-1);
    
    st->next=en;
    en->prev=st;


    map<ll,node*> value_location;

    node *ls=st;

    ll n,e;
    cin>>n;

    for(ll i=1;i<=n;i++){
        cin>>e;
        node *curr=new node(e);

        node *tmp=ls->next;
        ls->next=curr;
        curr->prev=ls;
        
        curr->next=tmp;
        tmp->prev=curr;

        value_location[e]=curr;
        
        ls=curr;
    }

    ll q;
    cin>>q;

    ll ty,x,y;

    while(q--){
        cin>>ty;
        if(ty==1){
            cin>>x>>y;
            //insert y immidiatley after x

            node *node_x=value_location[x];
            node *tmp=node_x->next;
            
            node *curr=new node(y);

            node_x->next=curr;
            curr->prev=node_x;

            curr->next=tmp;
            tmp->prev=curr;


            value_location[y]=curr;
            


        }else{

            ll x;
            cin>>x;
            node *curr=value_location[x];

            node *p=curr->prev;
            node *nx=curr->next;

            p->next=nx;
            nx->prev=p;


            delete curr;
            value_location.erase(x);

        }
    }

    node *start=st->next;
    while(start != en){
        cout<<(start->data)<<" ";
        start=start->next;
    }



 



}
int main(){
    boost;

    //pre_cum();
    //prec(20);
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