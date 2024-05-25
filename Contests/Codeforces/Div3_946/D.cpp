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

    string s;
    cin>>s;

    vector<ll> ind_n,ind_s,ind_e,ind_w;

    for(ll i=0;i<n;i++){
        if(s[i]=='N'){
            ind_n.pb(i);
        }else if(s[i]=='S'){
            ind_s.pb(i);
        }else if(s[i]=='E'){
            ind_e.pb(i);
        }else{
            ind_w.pb(i);
        }
    }


    ll sz_north=ind_n.size();
    ll sz_east=ind_e.size();
    ll sz_west=ind_w.size();
    ll sz_south=ind_s.size();

    if((sz_east-sz_west)%2 or (sz_north-sz_south)%2){
        cout<<"NO"<<endl;
        return;
    }

    ll mov_rotor_east=0,mov_rotor_west=0,mov_heli_east=0,mov_heli_west=0;
    ll mov_rotor_north=0,mov_rotor_south=0,mov_heli_north=0,mov_heli_south=0;

    for(ll i=0;i<=sz_east;i++){
        ll rotor_east=i;
        ll rotor_west=rotor_east-(sz_east-sz_west)/2;

        if(rotor_west>=0 and rotor_west <= sz_west){
            mov_rotor_east=rotor_east;
            mov_rotor_west=rotor_west;
            mov_heli_east=sz_east-mov_rotor_east;
            mov_heli_west=sz_west-mov_rotor_west;
            break;
        }
    }

    for(ll i=0;i<=sz_north;i++){
        ll heli_north=i;
        ll heli_south=heli_north-(sz_north-sz_south)/2;

        if(heli_south>=0 and heli_south <= sz_south){
            mov_heli_north=heli_north;
            mov_heli_south=heli_south;
            mov_rotor_north=sz_north-mov_heli_north;
            mov_rotor_south=sz_south-mov_heli_south;
            break;
        }
    }

    if(mov_rotor_east+mov_rotor_west+mov_rotor_north+mov_rotor_south > 0 and mov_heli_east+mov_heli_west+mov_heli_north+mov_heli_south > 0) {
        string sol=s;
        //cout<<"YES"<<endl;
        for(ll i=0;i<sz_east;i++){
            if(i<mov_rotor_east){
                sol[ind_e[i]]='R';    
            }else{
                sol[ind_e[i]]='H';
            }
        }

        for(ll i=0;i<sz_north;i++){
            if(i<mov_rotor_north){
                sol[ind_n[i]]='R';    
            }else{
                sol[ind_n[i]]='H';
            }
        }


        for(ll i=0;i<sz_west;i++){
            if(i<mov_rotor_west){
                sol[ind_w[i]]='R';    
            }else{
                sol[ind_w[i]]='H';
            }
        }

        for(ll i=0;i<sz_south;i++){
            if(i<mov_rotor_south){
                sol[ind_s[i]]='R';    
            }else{
                sol[ind_s[i]]='H';
            }
        }

        cout<<sol<<endl;

        return;
    }


    ll f=0;
    for(ll i=0;i<=sz_east;i++){
        ll rotor_east=i;
        ll rotor_west=rotor_east-(sz_east-sz_west)/2;

        if(rotor_west>=0 and rotor_west <= sz_west  ){
            mov_rotor_east=rotor_east;
            mov_rotor_west=rotor_west;
            mov_heli_east=sz_east-mov_rotor_east;
            mov_heli_west=sz_west-mov_rotor_west;

            if(mov_rotor_east+mov_rotor_west>0 and mov_heli_east+mov_heli_west>0){
                f=1;
                break;
            }
            
        }
    }

    for(ll i=0;i<=sz_north;i++){
        ll heli_north=i;
        ll heli_south=heli_north-(sz_north-sz_south)/2;

        if(heli_south>=0 and heli_south <= sz_south){
            mov_heli_north=heli_north;
            mov_heli_south=heli_south;
            mov_rotor_north=sz_north-mov_heli_north;
            mov_rotor_south=sz_south-mov_heli_south;
            break;
        }
    }

    if(f){
        
        string sol=s;
        //cout<<"YES"<<endl;
        for(ll i=0;i<sz_east;i++){
            if(i<mov_rotor_east){
                sol[ind_e[i]]='R';    
            }else{
                sol[ind_e[i]]='H';
            }
        }

        for(ll i=0;i<sz_north;i++){
            if(i<mov_rotor_north){
                sol[ind_n[i]]='R';    
            }else{
                sol[ind_n[i]]='H';
            }
        }


        for(ll i=0;i<sz_west;i++){
            if(i<mov_rotor_west){
                sol[ind_w[i]]='R';    
            }else{
                sol[ind_w[i]]='H';
            }
        }

        for(ll i=0;i<sz_south;i++){
            if(i<mov_rotor_south){
                sol[ind_s[i]]='R';    
            }else{
                sol[ind_s[i]]='H';
            }
        }

        cout<<sol<<endl;

        return;
    }

    for(ll i=0;i<=sz_east;i++){
        ll rotor_east=i;
        ll rotor_west=rotor_east-(sz_east-sz_west)/2;

        if(rotor_west>=0 and rotor_west <= sz_west){
            mov_rotor_east=rotor_east;
            mov_rotor_west=rotor_west;
            mov_heli_east=sz_east-mov_rotor_east;
            mov_heli_west=sz_west-mov_rotor_west;
            break;
        
            
        }
    }

    for(ll i=0;i<=sz_north;i++){
        ll heli_north=i;
        ll heli_south=heli_north-(sz_north-sz_south)/2;

        if(heli_south>=0 and heli_south <= sz_south){
            mov_heli_north=heli_north;
            mov_heli_south=heli_south;
            mov_rotor_north=sz_north-mov_heli_north;
            mov_rotor_south=sz_south-mov_heli_south;

            if((mov_heli_north+mov_heli_south)>0 and (mov_rotor_north+mov_rotor_south)>0){
                f=1;
                break;
            }
            
        }
    }

    if(f){
        
        string sol=s;
        //cout<<"YES"<<endl;
        for(ll i=0;i<sz_east;i++){
            if(i<mov_rotor_east){
                sol[ind_e[i]]='R';    
            }else{
                sol[ind_e[i]]='H';
            }
        }

        for(ll i=0;i<sz_north;i++){
            if(i<mov_rotor_north){
                sol[ind_n[i]]='R';    
            }else{
                sol[ind_n[i]]='H';
            }
        }


        for(ll i=0;i<sz_west;i++){
            if(i<mov_rotor_west){
                sol[ind_w[i]]='R';    
            }else{
                sol[ind_w[i]]='H';
            }
        }

        for(ll i=0;i<sz_south;i++){
            if(i<mov_rotor_south){
                sol[ind_s[i]]='R';    
            }else{
                sol[ind_s[i]]='H';
            }
        }

        cout<<sol<<endl;

        return;
    }

    cout<<"NO"<<endl;



    
    
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