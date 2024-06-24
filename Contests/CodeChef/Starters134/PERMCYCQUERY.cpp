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
ll mod;
arr<ll,2> a[200005],orig[200005];
ll pref[200005];
ll suff[200005];
ll contri[200005];
ll shift_left_contri[200005];
ll shift_right_contri[2000005];
ll get_contri(ll index){
    return (pref[index-1]*suff[index+1])%mod;
}
void solve(ll tc){
    ll n,q;
    cin>>n>>q>>mod;

    for(ll i=1;i<=n;i++){
        cin>>a[i][0];
        a[i][1]=i;
        orig[i]=a[i];
    }

    //contribution of ith smallest element is N!/i.
    sort(a+1,a+n+1);
    pref[0]=1;
    suff[n+1]=1;
    
    for(ll i=1;i<=n;i++){
        pref[i]=(pref[i-1]*i)%mod;
    }

    for(ll i=n;i>=1;i--){
        suff[i]=(suff[i+1]*i)%mod;
    }

    ll total_value=0;

    for(ll i=1;i<=n;i++){
        contri[i]=get_contri(i);
        total_value=(total_value+contri[i]*a[i][0])%mod;
    }
    

    for(ll i=1;i<=n;i++){
        if(i==1){
            shift_left_contri[i]=0;
        }else{
            shift_left_contri[i]=(shift_left_contri[i-1]+(contri[i-1]-contri[i])*a[i][0])%mod;
            shift_left_contri[i]=(shift_left_contri[i]+mod)%mod;
        }

        if(i==n){
            shift_right_contri[i]=shift_right_contri[i-1];
        }else{
            shift_right_contri[i]=(shift_right_contri[i-1]+(contri[i+1]-contri[i])*a[i][0])%mod;
            shift_right_contri[i]=(shift_right_contri[i]+mod)%mod;
        }
    }

    ll ind,x;
    while(q--){
        cin>>ind>>x;

        ll orig_value=orig[ind][0];
        ll index_orig=lower_bound(a+1,a+n+1,arr{orig_value,ind})-a;
        ll index_new=upper_bound(a+1,a+n+1,arr{x,ind})-a;
        if(index_new>1){
            index_new--;
        }
        
        ll sol=total_value;
        //cout<<index_orig<<" "<<index_new<<endl;

        //cout<<index_orig<<" "<<index_new<<endl;
        //only subarry between index_orignal and index_new will get shifted by one place to left or right. 
        if(index_orig==index_new){
            sol=(sol+contri[index_orig]*(x-orig_value))%mod;
        }else if(index_orig < index_new){
            ll change=(shift_left_contri[index_new]-shift_left_contri[index_orig]+mod)%mod;
            change=(change-get_contri(index_orig)*orig_value)%mod;
            change=(change+get_contri(index_new)*x)%mod;
            change=(change+mod)%mod;
            sol=(sol+change)%mod;
            
        }else{
            ll change=(shift_right_contri[index_orig-1]-shift_right_contri[index_new-1]);
            change=(change+get_contri(index_new)*x)%mod;
            change=(change-get_contri(index_orig)*orig_value)%mod;
            change=(change+mod)%mod;
            sol=(sol+change)%mod;

        }

        cout<<sol<<endl;
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