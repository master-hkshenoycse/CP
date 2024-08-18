#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	
	while(t--){
        vector<int> a(3);
        cin>>a[0]>>a[1]>>a[2];
        sort(a.begin(),a.end());
        
        int max_poss=a[0]+a[1]+1;
        
        if(a[2]>max_poss){
            cout<<"NO"<<endl;
        }else{
            cout<<"YES"<<endl;
        }
	}
}
