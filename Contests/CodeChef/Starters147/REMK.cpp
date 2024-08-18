#include <bits/stdc++.h>
using namespace std;
int get_cnt(vector<int> &a,int st,int en){
    vector<int> ::iterator it1,it2;
    it1=upper_bound(a.begin(),a.end(),st);
    if(it1==a.end()){
        return 0;
    }
    
    it2=lower_bound(a.begin(),a.end(),en);
    
    if(it2==a.begin()){
        return 0;
    }
    
    it2--;
    
    return it2-it1+1;
}
int main() {
	// your code goes here
	int t;
	cin>>t;
	
	while(t--){
	    int e,n,k;
	    cin>>n>>k;
	    
	    int ans=0;
	    vector<int> adj[51];
	    
	    for(int i=0;i<n;i++){
	        cin>>e;
	        adj[e].push_back(i);
	    }
	    
	    
	    for(int i=1;i<=50;i++){
	        for(int j=1;j<=50;j++){
	            
	            if(adj[i].size()==0 or adj[j].size()==0){
	                continue;
	            }
	            
	            int st_ind=adj[i][0];
	            int ind_end=adj[j].back();
	            
	            if(ind_end-st_ind+1<k){
	                continue;
	            }
	            
	            int curr_sum=i+j;
	            int rem=k-2;
	            
	            for(int p=50;p>=1;p--){
	                
	                int cnt_poss=get_cnt(adj[p],st_ind,ind_end);
	                int poss=min(cnt_poss,rem);
	                curr_sum+=p*poss*2;
	                rem-=poss;
	                
	            }
	            
	            //cout<<i<<" "<<j<<" "<<curr_sum<<endl;
	            
	            ans=max(ans,curr_sum);
	        }
	  
	    }
	    cout<<ans<<endl;
	}

}
