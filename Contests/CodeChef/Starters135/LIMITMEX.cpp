#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
	// your code goes here
    ll t;
    cin>>t;
    
    while(t--){
        ll n;
        cin>>n;
        
        vector<ll> a(n);
        for(ll i=0;i<n;i++){
            cin>>a[i];
        }
        
        
        //for a subarray function value is (max value in subarray)-(number of distinct values)+1.
        ll total_subarry=(n*n+n)/2ll;
        
        
        ll ans=total_subarry;//adding +1 for each suabrray
        
        //finding contribution of each;
        vector<ll> l(n,-1),r(n,n);
        
        //l stores the largest index less than i st >A[i];
        //r stores smallest index >i st >=A[i];
        
        stack<ll> st;
        map<ll,vector<ll> > help;
        for(ll i=0;i<n;i++){
            help[a[i]].push_back(i);
            
            while(st.size()>0 and a[st.top()]<=a[i]){
                st.pop();
            }
            
            if(st.size()>0){
                l[i]=st.top();
            }
            
            st.push(i);
        
        }
        
        while(st.size()>0){
            st.pop();
        }
        
        for(ll i=n-1;i>=0;i--){
            
            while(st.size()>0 and a[st.top()]<a[i]){
                st.pop();
            }
            
            
            if(st.size()>0){
                r[i]=st.top();
            }
            
            st.push(i);
        }
        
        //adding contributions for distinct element
        //adding all subbarray where element e will occur.
        for(auto it:help){
            int sz=it.second.size();
            ll contri=(n*n+n)/2ll;
            //subtracting all subarray where element e will not at all occcur.
            for(int i=0;i<sz;i++){
                ll len=0;
                if(i==0){
                    len=it.second[i];
                }else{
                    len=it.second[i]-it.second[i-1]-1;
                }
                contri-=(len*len+len)/2ll;
            }
            
            ll len=n-1-it.second.back();
            contri-=(len*len+len)/2ll;
            //cout<<it.first<<" "<<contri<<endl;
            ans=ans-contri;
        }
        
        //adding contribution of maximum
        for(ll i=0;i<n;i++){
            
            ll cnt_subarray=(i-l[i])*(r[i]-i);//cnt of subarray where element index i is maximum
           // cout<<a[i]<<" "<<l[i]<<" "<<r[i]<<" "<<cnt_subarray<<endl;
            ans=ans+cnt_subarray*a[i];
        }
        
        cout<<ans<<endl;
        
    
    }
}
