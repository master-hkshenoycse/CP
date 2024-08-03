#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	
	while(t--){
	    int n;
	    cin>>n;
	    
	    map<int,int> freq;
	    int e;
	    
	    for(int i=0;i<n;i++){
	        cin>>e;
	        freq[e]++;
	    }
	    
	    vector<int> freq_list;
	    for(auto it:freq){
	        freq_list.push_back(it.second);
	    }
	    
	    sort(freq_list.begin(),freq_list.end());
	    reverse(freq_list.begin(),freq_list.end());
	    int ans=0,sz=freq_list.size(),cs=0;
	    
	    for(int i=0;i<sz;i++){
	        cs=cs+freq_list[i];
	        ans=max(ans,(cs/(i+1))*(i+1));
	    }
	    
	    cout<<ans<<endl;
	}

}