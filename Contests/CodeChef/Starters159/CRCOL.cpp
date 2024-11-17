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
        
        for(ll i=0;i<k;i++){
            //how many times does index i%k occur from 0,n-1;
            ll no_times=(n-1)/k;
            if(((n-1)%k) >= i){
                no_times++;
            }

            
            if(s[i]=='A'){
                al_cnt+=(n+m-1)*(no_times)-2*(n-1)*(no_times)+(no_times)*(i+i+(no_times-1)*k);
            }else{
                bob_cnt+=(n+m-1)*(no_times)-2*(n-1)*(no_times)+(no_times)*(i+i+(no_times-1)*k);
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
