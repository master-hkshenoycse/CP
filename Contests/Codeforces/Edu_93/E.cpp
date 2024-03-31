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

void solve(ll tc){ 
    ll n;
    cin>>n;
    
    ll ty,val;
    set<pair<ll,ll> > top_set,bot_set;
    set<ll> zero_top;
    

    ll sum_top=0,sum_tot=0,cnt_light=0;
    ll light_in_top=0;

    //maximum values will give maximum gains if performed after the lghting spell
    //so if cnt of lighting spell is x , then keep track of top x values
    //corner case if all the topmost values are lighting then one of them will not be contributing as the first one

    for(ll i=1;i<=n;i++){
        cin>>ty>>val;

        if(val<0){
            val=abs(val);

            
            cnt_light-=ty;
            sum_tot-=val;

            if(top_set.find({val,ty}) != top_set.end()){
                sum_top-=val;
                light_in_top-=ty;
                top_set.erase({val,ty});
            }else{
                bot_set.erase({val,ty});
            }

            if(ty==0){
                zero_top.erase(val);
            }

        }else{

            sum_tot+=val;
            cnt_light+=ty;

            if(top_set.size()>0 and make_pair(val,ty) > *top_set.begin()){
                top_set.insert({val,ty});
                sum_top+=val; 
                light_in_top+=ty;   
            }else{
                bot_set.insert({val,ty});
            }

            if(ty==0){
                zero_top.insert(val);
            }
        }

        



        while(top_set.size() < cnt_light){

            auto it=*(--bot_set.end());
            bot_set.erase(it);

            if(it.ss == 1){
                light_in_top++;
            }

            top_set.insert(it);
            sum_top+=it.ff;

        }

        //pick the lowest values from top set to bottom set
        while(top_set.size() >  cnt_light){
            auto it=*top_set.begin();
            top_set.erase(it);

            if(it.ss==1){
                light_in_top--;
            }

            bot_set.insert(it);
            sum_top-=it.ff;
            
        }

        //cout<<sum_top<<" "<<top_set.size()<<" "<<cnt_light<<" "<<sum_tot<<endl;

        ll ans=sum_tot+sum_top;

        //if all the best values are of lighting type
        if(light_in_top>0 and light_in_top==top_set.size()){
            ans=ans-(*top_set.begin()).ff;

            if(zero_top.size()>0){
                ans+=*(--zero_top.end());
            }
        }

        cout<<ans<<endl;
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