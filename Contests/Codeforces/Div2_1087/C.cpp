#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    
    while(t--){
        int n;
        cin>>n;
        
        int ret;
        int ans=-1;
        for(int i=3;i<=2*n;i+=2){
            cout<<"? "<<i<<" "<<i+1<<endl;
            cin>>ret;
            
            if(ret==1){
                ans=i;
                break;
            }
        }
        
        if(ans==-1){
            int ret1,ret2;
            cout<<"? "<<2<<" "<<3<<endl;
            cin>>ret1;
            
            cout<<"? "<<2<<" "<<4<<endl;
            cin>>ret2;
            
            if(ret1==1){
                ans=2;    
            }else if(ret2==1){
                ans=2;
            }else{
                ans=1;
            }
            
        }
        
        
        cout<<"! "<<ans<<endl;
    }
}