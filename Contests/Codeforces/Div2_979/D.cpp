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
ll tree_max[800005];
ll tree_min[800005];

void build(ll node,ll l,ll r,vector<ll> &a){
    if(l>r){
        return;
    }

    if(l==r){
        tree_max[node]=a[l];
        tree_min[node]=a[l];
        return;
    }

    ll mid=(l+r)/2ll;
    build(node*2,l,mid,a);
    build(node*2+1,mid+1,r,a);

    tree_max[node]=max(tree_max[node*2],tree_max[node*2+1]);
    tree_min[node]=min(tree_min[node*2],tree_min[node*2+1]);

}
arr<ll,2>  query(ll node,ll st,ll en,ll l,ll r){
    if(st>en or en<l or st>r){
        return {(ll)1e9,(ll)-1e9};
    }

    if(st>=l and en<=r){
        return {tree_min[node],tree_max[node]};
    }

    ll mid=(st+en)/2ll;
    auto ret_l=query(node*2,st,mid,l,r);
    auto ret_r=query(node*2+1,mid+1,en,l,r);

    return {min(ret_l[0],ret_r[0]),max(ret_l[1],ret_r[1])};
}
ll check(ll l,ll r,ll n){
    auto it=query(1,0,n-1,l,r);
    return it[0]!=l or it[1]!=r;
}
void solve(ll tc){
    ll n,q;
    cin>>n>>q;

    vector<ll> a(n);
    for(ll i=0;i<n;i++){
        cin>>a[i];
        a[i]--;
    }

    build(1,0,n-1,a);

    

    string s;
    cin>>s;

    set<arr<ll,2> > intervals;
    set<arr<ll,2> > :: iterator interval_it;
    ll prev=-1;
    ll d=0;
    
    for(ll i=0;i+1<n;i++){
        if(s[i]=='L' and s[i+1]=='R'){
            intervals.insert({prev+1,i});
            prev=i;
        }
    }
    intervals.insert({prev+1,n-1});
    for(auto it:intervals){
        d+=check(it[0],it[1],n);
    }


    ll ind;

    while(q--){
        cin>>ind;
        ind--;

        interval_it=intervals.upper_bound({ind,1000000000});
        interval_it--;

        ll st=(*interval_it)[0];
        ll en=(*interval_it)[1];

        if(s[ind]=='L'){
           
            if(s[ind-1]=='R' and s[ind+1]=='R'){
                //merge the interval
                interval_it++;
                ll nx_st=(*interval_it)[0];
                ll nx_en=(*interval_it)[1];

                d-=check(st,en,n);
                d-=check(nx_st,nx_en,n);
                intervals.erase({st,en});
                intervals.erase({nx_st,nx_en});


                d+=check(st,nx_en,n);
                intervals.insert({st,nx_en});


            }else if(s[ind-1]=='R' and s[ind+1]=='L'){
                //do nothing
            }else if(s[ind-1]=='L' and s[ind+1]=='R'){
                //extend the next interval
                interval_it++;
                ll nx_st=(*interval_it)[0];
                ll nx_en=(*interval_it)[1];

                d-=check(st,en,n);
                d-=check(nx_st,nx_en,n);
                intervals.erase({st,en});
                intervals.erase({nx_st,nx_en});

                d+=check(st,en-1,n);
                d+=check(nx_st-1,nx_en,n);
                intervals.insert({st,en-1});
                intervals.insert({nx_st-1,nx_en});

            }else if(s[ind-1]=='L' and s[ind+1]=='L'){
                //split the interval
                d-=check(st,en,n);
                intervals.erase({st,en});
                intervals.insert({st,ind-1});
                intervals.insert({ind,en});
                d+=check(st,ind-1,n);
                d+=check(ind,en,n);
            }   

            s[ind]='R';

        }else{

            if(s[ind-1]=='L' and s[ind+1]=='L'){
                //merge the intervals
                interval_it--;
                ll prev_st=(*interval_it)[0];
                ll prev_en=(*interval_it)[1];

                //remove old intervals
                d-=check(st,en,n);
                d-=check(prev_st,prev_en,n);
                intervals.erase({st,en});
                intervals.erase({prev_st,prev_en});
                

                //insert the merged interval
                d+=check(prev_st,en,n);   
                intervals.insert({prev_st,en});

            }else if(s[ind-1]=='R' and s[ind+1]=='L'){
                //nothing needs to be done
            }else if(s[ind-1] == 'R' and s[ind+1]=='R'){
                //split the interval
                d-=check(st,en,n);
                intervals.erase({st,en});

                intervals.insert({st,ind});
                intervals.insert({ind+1,en});
                d+=check(st,ind,n);
                d+=check(ind+1,en,n);
            }else if(s[ind-1]=='L' and s[ind+1]=='R'){
                //extend the previous interval
                interval_it--;
                ll prev_st=(*interval_it)[0];
                ll prev_en=(*interval_it)[1];

                d-=check(st,en,n);
                d-=check(prev_st,prev_en,n);
                intervals.erase({st,en});
                intervals.erase({prev_st,prev_en});


                d+=check(prev_st,prev_en+1,n);
                d+=check(st+1,en,n);
                intervals.insert({prev_st,prev_en+1});
                intervals.insert({st+1,en});
            }

            s[ind]='L';

        }


        if(d==0){
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