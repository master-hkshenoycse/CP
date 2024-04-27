#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	
	while(t--){
	    
	    int n,k;
	    cin>>n>>k;
	    
	    vector<int> a(n);
	    for(int i=0;i<n;i++){
	        cin>>a[i];
	        a[i]%=k;
	    }
	    
	    
	   
	    
	    sort(a.begin(),a.end());
	    int ans=a[n-1]-a[0];
	    
	    for(int i=0;i+1<n;i++){
	        ans=min(ans,k+a[i]-a[i+1]);
	    }
	    
	    cout<<ans<<endl;
	    
	    
	    
	}

}
