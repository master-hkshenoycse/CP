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
        
        vector<int> index_to_flip;
        char prev='1';
        
        //as even length substring is considrerd
        //so every 2 consecative disjoint index should be equal
        //(0,1)(2,3),(4,5) etc 
        
        for(int i=0;i<n;i+=2){
            if(s[i]!=s[i+1]){
                if(prev=='0'){
                    if(s[i]=='1'){
                        index_to_flip.push_back(i);
                    }else{
                        index_to_flip.push_back(i+1);
                    }
                    prev='1';
                }else{
                    if(s[i]=='0'){
                        index_to_flip.push_back(i);
                    }else{
                        index_to_flip.push_back(i+1);
                    }
                    prev='0';
                }
            }
        }
        
        cout<<index_to_flip.size()<<endl;
        for(auto ind:index_to_flip){
            cout<<ind+1<<" ";
        }
        cout<<endl;
    
    }
}
