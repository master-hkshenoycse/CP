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
	    s="bb"+s+"bb";
	   
	    n=s.size();
	    vector<int> pref_a(n+1,0),pref_c(n+1,0);
	    vector<int> index_b;
	    for(int i=1;i<=n;i++){
	        pref_a[i]=pref_a[i-1]+(s[i-1]=='a');
	        pref_c[i]=pref_c[i-1]+(s[i-1]=='c');
	        if(s[i-1]=='b'){
	            index_b.push_back(i);
	        }
	    }
	    
	    int ans=n;
	    int sz=index_b.size();
	    
	    for(int i=0;i+1<sz;i++){
	        ans=min(ans,pref_a[index_b[i]]+pref_c[n]-pref_c[index_b[i+1]]);
	    }
	    
	    
	    cout<<ans<<endl;
	    
	    
	   
	   
	}

}
