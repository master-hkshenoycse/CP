#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    int t;
    cin>>t;
    
    while(t--){
        int n;
        cin>>n;
        
        int ans=0;
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
            ans=ans+a[i];
        }
        
        sort(a.begin(),a.end());
        int neg=n-(n+1)/2;
        for(int i=0;i<neg;i++){
            ans=ans-2*a[i];
        }
        cout<<ans<<endl;
    }
}
