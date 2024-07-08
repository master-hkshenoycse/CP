#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    
    int findTheWinner(int n, int k) {
        vector<int> persons(n,0),is_alive(n,0);
        
        for(int i=0;i<n;i++){
            persons[i]=i;
            is_alive[i]=1;
        }
        
        int steps=n-1;
        int c=0;
        while(steps--){
            
            int rep=k;
            int st=c;
            
            while(rep){
                
                if(is_alive[st]==1){
                    rep--;
                }
                
                if(rep==0){
                    break;
                }
                
                st=(st+1)%n;
            }
           // cout<<st<<" ";
            
            is_alive[st]=0;
            st=(st+1)%n;
            c=st;
            
        }
        int sol=0;
        for(int i=0;i<n;i++){
            if(is_alive[i]==1)sol=i;
        }
        return sol+1;
        
        
        
    }
};