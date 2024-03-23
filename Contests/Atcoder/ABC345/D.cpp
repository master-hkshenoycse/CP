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
ll a[25],b[25];
ll vis[25][25];
ll ans=0;
ll n,h,w;
void solve(ll unused,ll x,ll y){

    //find the next used tile
    while(vis[x][y]){
        y++;

        if(y==w){
            x++;
            y=0;
        }

        if(x==h){
            ans=1;
            break;
        }
    }


    
    //cout<<x<<" "<<y<<endl;
    
    if(x>=h){
        ans=1;
        return;
    }

    for(ll i=0;i<n;i++){

        //if the tile is not yet used
        if(unused & (1ll<<i)){


            ll tile_h=a[i];
            ll tile_w=b[i];
            

            //check if the rectangle starting from (x,y) to (x+tile_h-1,y+tile_w-1) is empty 
            if(x+tile_h-1<h and y+tile_w-1<w){
                bool poss=1;
                for(ll p=x;p<=x+tile_h-1;p++){
                    for(ll q=y;q<=y+tile_w-1;q++){
                        if(vis[p][q]>0){
                            poss=0;
                            break;
                        }
                    }
                    if(poss==0){
                        break;
                    }
                }

                if(poss){
                    for(ll p=x;p<=x+tile_h-1;p++){
                        for(ll q=y;q<=y+tile_w-1;q++){
                            vis[p][q]=1;
                        }
                    }

                    solve(unused ^ (1ll<<i),x,y);

                    for(ll p=x;p<=x+tile_h-1;p++){
                        for(ll q=y;q<=y+tile_w-1;q++){
                            vis[p][q]=0;
                        }
                    }

                }
            }

            //rotate the tile
            swap(tile_h,tile_w);

            //check if the rectangle starting from (x,y) to (x+tile_h-1,y+tile_w-1) is empty 
            if(x+tile_h-1<h and y+tile_w-1<w){
                bool poss=1;
                for(ll p=x;p<=x+tile_h-1;p++){
                    for(ll q=y;q<=y+tile_w-1;q++){
                        if(vis[p][q]>0){
                            poss=0;
                            break;
                        }
                    }
                    if(poss==0){
                        break;
                    }
                }

                if(poss){
                    for(ll p=x;p<=x+tile_h-1;p++){
                        for(ll q=y;q<=y+tile_w-1;q++){
                            vis[p][q]=1;
                        }
                    }

                    solve(unused ^ (1ll<<i),x,y);

                    for(ll p=x;p<=x+tile_h-1;p++){
                        for(ll q=y;q<=y+tile_w-1;q++){
                            vis[p][q]=0;
                        }
                    }

                }
            }


        }
    }
}
void solve(ll tc){ 

    cin>>n>>h>>w;




    for(ll i=0;i<n;i++){
        cin>>a[i]>>b[i];
    }


    ll area_sum=0;

    for(ll i=0;i<n;i++){
        area_sum+=a[i]*b[i];
    }


    solve((1ll<<n)-1,0,0);
    if(ans){
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
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