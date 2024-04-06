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


void clear_stack(stack<int> &st){
        while(st.size()>0){
            st.pop();
        }
}
int minJumps(int N, vector<int> &arr) {
    // code here

    vector<int> dp(N+1,N+1),nx_gt(N,N+1),nx_ls(N,N+1),prev_gt(N,-1),prev_ls(N,-1);
    
    stack<int> st;
    for(int i=N-1;i>=0;i--){
        while(st.size()>0 and arr[st.top()]<arr[i]){
            st.pop();
        }
        if(st.size()>0){
            nx_gt[i]=st.top();
        }
        
        st.push(i);
    }
    
    clear_stack(st);
    
    for(int i=N-1;i>=0;i--){
        while(st.size()>0 and arr[st.top()]>arr[i]){
            st.pop();
        }
        if(st.size()>0){
            nx_ls[i]=st.top();
        }
        
        st.push(i);
    }
    
    clear_stack(st);
    
    for(int i=0;i<N;i++){
        while(st.size()>0 and arr[st.top()]<arr[i]){
            st.pop();
        }
        
        if(st.size()>0){
            prev_gt[i]=st.top();
        }
        st.push(i);
    }
    
    clear_stack(st);
    
    for(int i=0;i<N;i++){
        while(st.size()>0 and arr[st.top()]>arr[i]){
            st.pop();
        }
        
        if(st.size()>0){
            prev_ls[i]=st.top();
        }
        st.push(i);
    }
    
    for(int i=N-1;i>=0;i--){
        if(i==N-1){
            dp[i]=0;
            
            if(prev_gt[i]!=-1){
                dp[prev_gt[i]]=min(dp[prev_gt[i]],dp[i]+1);
            }
            
            if(prev_ls[i]!=-1){
                dp[prev_ls[i]]=min(dp[prev_ls[i]],dp[i]+1);
            }
            
            
        }else{
            dp[i]=min(dp[i],dp[i+1]+1);
            
            
            if(nx_gt[i]<N){
                dp[i]=min(dp[i],dp[nx_gt[i]]+1);
            }
            
            if(nx_ls[i]<N){
                dp[i]=min(dp[i],dp[nx_ls[i]]+1);
            }
                
            
            if(prev_gt[i]!=-1){
                dp[prev_gt[i]]=min(dp[prev_gt[i]],dp[i]+1);
            }
            
            if(prev_ls[i]!=-1){
                dp[prev_ls[i]]=min(dp[prev_ls[i]],dp[i]+1);
            }
                    
            
        }

    }
    
    
    return dp[0];
    
}

void solve(ll tc){ 
    ll n;
    cin>>n;

    vector<int> a(n);
    for(ll i=0;i<n;i++){
        cin>>a[i];
    }

    cout<<minJumps(n,a)<<endl;
   
    
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