#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	
	while(t--){
	    int n,x;
	    cin>>n>>x;
	    
	    vector<int> a(n),b(n),req(n);
	    for(int i=0;i<n;i++){
	        cin>>a[i];
	    }
	    
	    for(int i=0;i<n;i++){
	        cin>>b[i];
	        req[i]=max(0,b[i]-a[i]+1);
	    }
	    
	    sort(req.begin(),req.end());
	    int wins=0;
	    
	    for(int i=0;i<n;i++){
	        if(x>=req[i]){
	            wins++;
	            x-=req[i];
	        }
	    }
	    
	    if(wins>=(n+1)/2){
	        cout<<"YES"<<endl;
	    }else{
	        cout<<"NO"<<endl;
	    }
	    
	
	
	}

}
