#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	
	while(t--){
	    int n,k;
	    cin>>n>>k;
	    
	    string s;
	    cin>>s;
	    int ans=INT_MAX;
	    
	    for(int i=0;i<=n;i++){
	       
	        string tmp=s;
	        int rem=k;
	        
	        
	        for(int j=0;j<i;j++){
	            if(tmp[j]=='1' and rem>0){
	                rem--;
	                tmp[j]='0';
	            }
	        }
	        
	        for(int j=n-1;j>=i;j--){
	            if(tmp[j]=='0' and rem>0){
	                rem--;
	                tmp[j]='1';
	                
	            }
	        }
	        
	        int cnt=0,cnt_ones=0;
	        for(auto ch:tmp){
	            if(ch=='0'){
	                cnt=cnt+cnt_ones;
	            }else{
	                cnt_ones++;
	            }
	        }
	        
	        ans=min(ans,cnt);
	       
	    }
	    
	    cout<<ans<<endl;
	    
	}
	
	

}