#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	
	while(t--){
	    int n;
	    cin>>n;
	    
	    string s;
	    cin>>s;
	    
	    int ops_01=0,ops_10=0;
	    
	    for(int i=0;i<n;i++){
	        int curr=s[i]-'0';
	        
	        if(i%2==0){
	            if((curr+ops_01)%2){
	                ops_01++;
	            }
	            
	            if((curr+ops_10)%2==0){
	                ops_10++;
	            }
	            
	        }else{
	            if((curr+ops_01)%2==0){
	                ops_01++;
	            }
	            
	            if((curr+ops_10)%2){
	                ops_10++;
	            }
	        }
	    }
	    
	    cout<<min(ops_01,ops_10)<<endl;
	}

}
