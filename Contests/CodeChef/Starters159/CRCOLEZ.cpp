#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
	// your code goes here
	ll t;
	cin>>t;
	
	while(t--){
	    ll n,m,k;
	    cin>>n>>m>>k;
	    
	    string s;
	    cin>>s;
        
        if(n>m){
            swap(n,m);
        }
        ll al_cnt=0,bob_cnt=0;
        
        for(int i=n-1;i>=0;i--){
            int ch=(i%k);
            if(s[i%k]=='A'){
                al_cnt+=(n+m-1)-2*(n-i-1);
            }else{
                bob_cnt+=(n+m-1)-2*(n-i-1);
            }
        }
	    
	    if(al_cnt>bob_cnt){
	        cout<<"Alice"<<endl;
	    }else if(bob_cnt>al_cnt){
	        cout<<"Bob"<<endl;
	    }else{
	        cout<<"Draw"<<endl;
	    }
	}

}
