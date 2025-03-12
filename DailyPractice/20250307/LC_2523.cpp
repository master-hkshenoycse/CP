#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        vector<int> closestPrimes(int left, int right) {
           vector<int> sol={-1,-1};
            
            
            vector<int> chk(right+1,0);
            int prev_p=-1,c_diff=1e9;
            
            for(int i=2;i<=right;i++){
                if(chk[i]==0){
                    if(prev_p != -1){
                        if(i-prev_p < c_diff){
                            sol={prev_p,i};
                            c_diff=i-prev_p;
                        }
                    }
                    
                    if(i>=left){
                        prev_p=i;
                    }
                    for(int j=2*i;j<=right;j+=i){
                        chk[j]=1;
                    }
                }
            }
            
            
            return sol;
        }
    };