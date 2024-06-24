#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    int t;
    cin>>t;
    
    while(t--){
        int n;
        cin>>n;
        
        string s;
        cin>>s;
        
        int i=0,c1=0,c0=0;
        while(i<n){
            int j=i;
            while(j<n and s[i]==s[j]){
                j++;
            }
            
            if(s[i]=='1'){
                c1++;
            }else{
                c0++;
            }
            
            i=j;
        }
        
        cout<<min(c1,c0)<<endl;
    
    }
}
