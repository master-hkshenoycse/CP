#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
	// your code goes here
	ll t;
	cin>>t;
	
	while(t--){
	    ll n;
	    cin>>n;
	    
	    if(n%2==0){
	        cout<<2<<endl;
	    }else{
	        cout<<(n*n+1)/2+1<<endl;
	    }
	}

}
