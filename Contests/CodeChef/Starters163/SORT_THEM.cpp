#include <bits/stdc++.h>
using namespace std;

char get_op(string &s,int pos){
    return s[25-pos];
}
int main() {
	// your code goes here
	int t;
	cin>>t;
	
	while(t--){
	    int n;
	    cin>>n;
	    
	    string s,p;
	    cin>>s>>p;
	    
	    vector<int> ord(26);
	    for(int i=0;i<26;i++){
	        ord[p[i]-'a']=i;
	    }
	    
	    vector<int> dp(26,1e9);
	    dp[s[0]-'a']=0;
	    dp[get_op(p,ord[s[0]-'a'])-'a']=1;
	    
	    for(int i=1;i<n;i++){
	        vector<int> tmp(26,1e9);
	        vector<int> chs={s[i]-'a',get_op(p,ord[s[i]-'a'])-'a'};
	        vector<int> ops={0,1};
	        
	        for(int j=0;j<26;j++){
	            for(int k=0;k<2;k++){
	                if(chs[k]>=j and dp[j]!=1e9){
	                    tmp[chs[k]]=min(tmp[chs[k]],dp[j]+ops[k]);
	                }
	            }
	        }
	        
	        
	        
	        dp=tmp;
	    }
	    
	    int ans=1e9;
	    for(int i=0;i<26;i++){
	        ans=min(ans,dp[i]);
	    }
	    
	    if(ans==1e9){
	        ans=-1;
	    }
	    
	    cout<<ans<<endl;
	    
	
	}

}
