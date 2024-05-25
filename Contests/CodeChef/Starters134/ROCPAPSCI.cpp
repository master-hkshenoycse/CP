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
	    
	    int i=0,ans=0;
	    
	    
	    while(i<n){
	        int j=i,c=0;
	        while(j<n and s[i]==s[j]){
	            c++;
	            j++;
	        }
	        ans=ans+(c+1)/2;
	        i=j;
	    }
	    
	    cout<<ans<<endl;
	}

}
