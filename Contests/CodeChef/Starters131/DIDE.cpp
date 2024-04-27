#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	
	while(t--){
	    int n,k;
	    cin>>n>>k;
	    
	    int s=0,e;
	    vector<int> gain(n);
	    
	    for(int i=0;i<n;i++){
	        cin>>e;
	        s=s+e;
	        gain[i]=(7-e)-e;
	    }
	    
	    sort(gain.begin(),gain.end());
	    reverse(gain.begin(),gain.end());
	    
	    for(int i=0;i<k;i++){
	        s=s+max(0,gain[i]);
	    }
	    
	    cout<<s<<endl;
	}

}
