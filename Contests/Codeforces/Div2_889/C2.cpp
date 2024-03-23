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
void print_ops(vector<vector<ll> > ops){
    cout<<ops.size()<<endl;
    for(auto op:ops){
        cout<<op[0]+1<<" "<<op[1]+1<<endl;   
    }

}
void solve(ll tc){ 
    ll n;
    cin>>n;

    vector<ll> a(n);
    for(ll i=0;i<n;i++){
        cin>>a[i];
    }

    ll cnt_pos=0,cnt_neg=0;
    ll pos_index=-1,neg_index=-1;
    ll max_pos_value=-1,least_neg_value=1e10;
    ll index_max_abs=-1,value_max_abs=-1;

    

    //once all the signs are same it will take n-1 steps
    //to make all the values with same sign see the count of positive and negative number

    //to limit the number of operations <=31 check the cnt of positive and negative number

    //try making the positve number greater than >=32 
    // assume it takes 5 operations in worst case
    //then all negative number will be turned to positive in 1 step
    //so this will required cnt_neg operations
    //assume cnt_neg=n-cnt_pos in worst case
    //so operations will be
    //=> 5+(n-cnt_pos)+(n-1)<=31
    //=> 2*n-cnt_pos+4<=31
    //=> 2*n-cnt_pos<=27
    //=> cnt_pos>=2*n-27
    //=> n<=20
    //=> so above holds when
    //=> cnt_pos>=13

    //same for negative element as well
    

    
    for(ll i=0;i<n;i++){
        if(a[i]>0){
            cnt_pos++;
            if(a[i]>max_pos_value){
                max_pos_value=a[i];
                pos_index=i;
            }
        }

        if(a[i]<0){
            cnt_neg++;
            if(a[i]<least_neg_value){
                least_neg_value=a[i];
                neg_index=i;
            }
        }

        if(abs(a[i])>value_max_abs){
            value_max_abs=abs(a[i]);
            index_max_abs=i;
        }
    }

    vector<vector<ll> > ops;

    if(cnt_pos>=13){

        while(a[pos_index] < 20){
            ops.pb({pos_index,pos_index});
            a[pos_index]=a[pos_index]+a[pos_index];
        }

        for(ll i=0;i<n;i++){
            if(a[i]<0){
                ops.pb({i,pos_index});
                a[i]=a[i]+a[pos_index];
            }
        }

        for(ll i=1;i<n;i++){
            if(a[i]<a[i-1]){
                ops.pb({i,i-1});
                a[i]=a[i]+a[i-1];
            }
        }

        print_ops(ops);
        return;

    }   


    if(cnt_neg>=13){


        while(a[neg_index] > -20){
            ops.pb({neg_index,neg_index});
            a[neg_index]=a[neg_index]+a[neg_index];
        }

        for(ll i=0;i<n;i++){
            if(a[i]>0){
                ops.pb({i,neg_index});
                a[i]=a[i]+a[neg_index];
            }
        }

        for(ll i=n-2;i>=0;i--){
            if(a[i]>a[i+1]){
                ops.pb({i,i+1});
                a[i]=a[i]+a[i+1];
            }
        }

        print_ops(ops);
        return;
    }

    // as both postive and negative are less than equal to 12 , operations will be 31 at max
    if(a[index_max_abs]<0){

        for(ll i=0;i<n;i++){
            if(a[i]>0){
                ops.pb({i,index_max_abs});
                a[i]=a[i]+a[index_max_abs];
            }
        }

        for(ll i=n-2;i>=0;i--){
            if(a[i]>a[i+1]){
                ops.pb({i,i+1});
                a[i]=a[i]+a[i+1];
            }
        }

        
    }else{

        for(ll i=0;i<n;i++){
            if(a[i]<0){
                ops.pb({i,index_max_abs});
                a[i]=a[i]+a[index_max_abs];
            }
        }

        for(ll i=1;i<n;i++){
            if(a[i-1]>a[i]){
                ops.pb({i,i-1});
                a[i]=a[i]+a[i-1];
            }
        }

    }

    print_ops(ops);

    




}
int main(){
    boost;

    //pre_cum();
    //prec(20);
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