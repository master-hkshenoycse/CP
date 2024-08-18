#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	
	int t;
	cin>>t;
	
	while(t--){
	    int n,m;
	    cin>>n>>m;
	    
	    if(n>=m+1){
	        cout<<2*m+1<<endl;
	    }else{
	        cout<<-1<<endl;
	    }
	}

}
