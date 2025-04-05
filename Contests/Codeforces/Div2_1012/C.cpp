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
ll dx[4]={0,0,1,1};
ll dy[4]={0,1,0,1};

bool check_occupy(ll x,ll y,set<vector<ll> >&vis){
    
    for(ll i=0;i<4;i++){
        if(vis.find({x+dx[i],y+dy[i]}) != vis.end()){
            return 0;
        }
    }

    return 1;
}

void do_ops_unoccupied(set<vector<ll> >&un_occupied,set<vector<ll> >&occupied,set<vector<ll> > &vis){
    
    
    auto it = *un_occupied.begin();

    ll d = it[0];
    ll x = it[1];
    ll y = it[2];
    
    cout<<x<<" "<<y<<endl;

    un_occupied.erase(it);
    vis.insert({x,y});
    occupied.insert({d+1,x+1,y});
    occupied.insert({d+1,x,y+1});
    occupied.insert({d+4,x+1,y+1});

    ll nx_x=x,nx_y=y;
    while(check_occupy(nx_x,nx_y,vis)==0){
        nx_x+=3;
    }
    un_occupied.insert({nx_x+nx_y,nx_x,nx_y});

    nx_x=x;
    while(check_occupy(nx_x,nx_y,vis)==0){
        nx_y+=3;
    }

    un_occupied.insert({nx_x+nx_y,nx_x,nx_y});
}

void do_ops_occupied(set<vector<ll> >&un_occupied,set<vector<ll> >&occupied,set<vector<ll> > &vis){
    auto it = *occupied.begin();

    ll d = it[0];
    ll x = it[1];
    ll y = it[2];
    
    cout<<x<<" "<<y<<endl;

    occupied.erase(it);
    vis.insert({x,y});
    
    x=((x-1)/3)*3+1;
    y=((y-1)/3)*3+1;

    ll nx_x=x,nx_y=y;
    while(check_occupy(nx_x,nx_y,vis)==0){
        nx_x+=3;
    }

    un_occupied.insert({nx_x+nx_y,nx_x,nx_y});

    nx_x=x;
    while(check_occupy(nx_x,nx_y,vis)==0){
        nx_y+=3;
    }

    un_occupied.insert({nx_x+nx_y,nx_x,nx_y});
}
void solve(ll tc){
    ll n;
    cin>>n;


    set< vector<ll> > un_occupied;
    set< vector<ll> > occupied;
    set<vector<ll> > vis;

    un_occupied.insert({2,1,1});
    ll e;

    for(ll i=0;i<n;i++){
        cin>>e;

        if(e ==1){


            if(occupied.size()>0 && un_occupied.size()>0){
                
                if( (*occupied.begin()) < (*un_occupied.begin())){
                    do_ops_occupied(un_occupied,occupied,vis);
                }else{
                    do_ops_unoccupied(un_occupied,occupied,vis);
                }


            }else if(occupied.size()==0){
                do_ops_unoccupied(un_occupied,occupied,vis);
            }



        }else{

            do_ops_unoccupied(un_occupied,occupied,vis);

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