#include <bits/stdc++.h>
#define boost ios_base::sync_with_stdio(0)

using namespace std;

int get_0_segs(string &s){
    int ret=0,i=0,n=s.size();
    while(i<n){
        int j=i;
        while(j<n and s[i]==s[j]){
            j++;
        }
        
        if(s[i]=='0'){
            ret++;
        }
        
        i=j;
    }
    
    return ret;
    
}
int main() {
	// your code goes here
	boost;
	int t;
	cin>>t;
	
	while(t--){
	    int n,q;
	    cin>>n>>q;
	    

	    vector<int> a(n);
	    int curr_and;
	    
	    for(int i=0;i<n;i++){
	        cin>>a[i];
	       
	        if(i==0){
	            curr_and=a[i];
	        }else{
	            curr_and=(curr_and & a[i]);
	        }
	    }
	    


	    vector<string> bit_rep;
	    vector<vector<int> > similar_bits(20);
	    vector<int> segs(20);
	    
	    for(int i=0;i<20;i++){
	        string curr;
	        for(int j=0;j<n;j++){
	            if(a[j] & (1<<i)){
	                curr+='1';
	            }else{
	                curr+='0';
	            }
	        }
	        
	        bit_rep.push_back(curr);
	    }
	    
	    
	    
	    for(int i=0;i<20;i++){
	        segs[i]=get_0_segs(bit_rep[i]);
	        for(int j=i-1;j>=0;j--){
	            if(bit_rep[i]==bit_rep[j]){
	                similar_bits[i].push_back(j);
	            }
	        }
	    }
	   
	    while(q--){
	        int k,x;
	        cin>>k>>x;
	        
	        int ans=curr_and;
	        
	        for(int i=20;i>=0;i--){
	            if((x & (1<<i)) and segs[i]<=k){
	                int curr=(1<<i);
	                for(auto e:similar_bits[i]){
	                    if(x & (1<<e)){
	                        curr=curr+(1<<e);
	                    }
	                }
	                
	                for(int j=20;j>=0;j--){
	                    if(curr_and & (1<<j)){
	                        if((x & (1<<j))==0){
	                            curr=(curr  | (1<<j));
	                        }
	                    }
	                }
	                
	                ans=max(ans,curr);
	            }
	        }
	        
	        cout<<ans<<endl;
	            
	    }
	}
}
