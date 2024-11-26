#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n=code.size();
        vector<int> sol(n,0);
        
        for(int i=0;i<n;i++){
          
            if(k==0){
                sol[i]=0;
            }else if(k>0){
                int s=0;
                int steps=k;
                int st=i;
                while(steps--){
                    st=(st+1)%n;
                    s+=code[st];
                    
                }
                sol[i]=s;
            }else{
                int s=0;
                int steps=-k;
                int st=i;
                while(steps--){
                    st=(st-1+n)%n;
                    s+=code[st];
                    
                }
                sol[i]=s;
                
            }
        }
        return sol;
    }
};