#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	
	while(t--){
	    int n;
	    cin>>n;
	    
	    vector<int> a(n);
	    for(int i=0;i<n;i++){
	        cin>>a[i];
	    }
        
        int possible=1;	    
	    if(a[0] != a[n-1]){
	        possible=0;
	    }
	    
	    for(int i=1;i<n-1;i++){
	        if(a[i]<a[0]){
	            possible=0;
	        }
	    }
	    
	    if(possible==0){
	        cout<<"NO"<<endl;
	    }else{
	        cout<<"YES"<<endl;
	    }
	}

}
