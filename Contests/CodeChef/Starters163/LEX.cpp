#include <bits/stdc++.h>
using namespace std;
vector<vector<int> > get_compress(string &a){
    int i=0,n=a.size();
    vector<vector<int> > ret;
    while(i<n){
        int c=0,j=i;
        while(j<n and a[i]==a[j]){
            c++;
            j++;
        }
        
    
        ret.push_back({a[i]-'a',c});
        i=j;
        
    }
    
    return ret;
    
}
int main() {
	// your code goes here
	int t;
	cin>>t;
	
	while(t--){
	    int n,m;
	    string a,b;
	    
	    cin>>n>>m;
	    cin>>a>>b;
	    
	    vector<vector<int> > comp_a,comp_b;
        comp_a=get_compress(a);
        comp_b=get_compress(b);
        
        int f=1;
        
        if(comp_a.size() != comp_b.size()){
            f=0;
        }
        
        if(f){
            for(int i=0;i<comp_a.size();i++){
                
                if(comp_a[i][0] != comp_b[i][0]){
                    f=0;
                    break;
                }
                
                if(comp_a[i][1]<comp_b[i][1]){
                    f=0;
                    break;
                }
                
                if((comp_a[i][1]-comp_b[i][1])%2){
                    f=0;
                    break;
                }
                
                if((comp_a[i][1]-comp_b[i][1])>0 ){
                    if(i==0 and i==comp_a.size()-1){
                        f=0;
                        break;
                    }
                }
                
            }
        }
        
        if(f){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
	    
	}

}
