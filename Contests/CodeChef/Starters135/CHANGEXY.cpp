#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    int t;
    cin>>t;
    
    while(t--){
        int a,b,k;
        cin>>a>>b>>k;
        
        int ans=0;
        while(b>a){
            if(b%k==0 and b/k>=a){
                ans++;
                b/=k;
            }else{
                int req;
                
                if(b%k){
                    req=min(b%k,b-a);
                }else{
                    req=b-a;
                }
                b-=req;
                ans+=req;
                
            }
        }
        
        cout<<ans<<endl;
    }
}
