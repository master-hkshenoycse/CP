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
	    set<int> x;
	    
	    for(int i=0;i<n;i++){
	        cin>>a[i];
	        x.insert(a[i]);
	    }
	    
        if(x.size()==1){
            cout<<"YES"<<endl;
        }else if(x.size()==2 and *(x.begin())==0){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
	    
	}
	

}
