#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int n=derived.size();
        
        if(n==1){
            return derived[0]==0;
        }
        
        vector<int> poss(n,0);
        poss[0]=0;
        for(int i=0;i<n;i++){
            if(i==n-1){
                if((poss[i] ^ poss[0])==derived[i]){
                    return 1;
                }
            }else{
                poss[i+1]=(derived[i] ^ poss[i]);
            }
        }
        
        poss[0]=1;
        for(int i=0;i<n;i++){
            if(i==n-1){
                if((poss[i] ^ poss[0])==derived[i]){
                    return 1;
                }
            }else{
                poss[i+1]=(derived[i] ^ poss[i]);
            }
        }
        
        return 0;
    }
};