#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        int sz=encodedText.size();
        int n_cols=sz/rows;
        
        
        
        string sol;
        
        if(n_cols==0){
            return sol;
        }
        
        for(int i=0;i<n_cols;i++){   
            int j=i;
            while(j<sz){
                sol+=encodedText[j];
                j+=(n_cols+1);
            }
        }
        
        int len=sol.size();
        while(sol[len-1]==' '){
            len--;
        }
        sol=sol.substr(0,len);
        
        return sol;
    }
};