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
	    
	    int i=0,segs_1=0,segs_0=0,c1=0,c0=0;
	    
	    while(i<n){
	        
	        int j=i;
	        
	        while(j<n and s[i]==s[j]){
	             c1+=(s[i]=='1');
	             c0+=(s[i]=='0');
	             j++;
	        }
	        
            if(s[i]=='0'){
                segs_0++;
            }else{
                segs_1++;
            }
            
            i=j;	        
	    }
	    
	    //cout<<segs_0<<" "<<segs_1<<endl;
	    
	    if(n==1){
	        if(s[0]=='1')cout<<0<<endl;
	        else cout<<1<<endl;
	        continue;
	    }
	    
	    cout<<max(0,segs_0-segs_1+1)<<endl;
	    
	    
	}
	

}
