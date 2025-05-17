#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        string countAndSay(int n) {
            string sol="1";
    
            
            for(int i=2;i<=n;i++){
    
                string tmp;
                int j=0,sz=sol.size();
    
                while(j<sz){
                    int k=j,cnt=0;
                    while(k<sz and sol[k]==sol[j]){
                        k++;
                        cnt++;
                    }
    
                    tmp+=char('0'+cnt);
                    tmp+=sol[j];
    
                    j=k;
                }
    
                sol=tmp;
            }
    
            return sol;
        }
    };