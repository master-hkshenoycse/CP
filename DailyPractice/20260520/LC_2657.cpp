#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n=A.size();
        vector<int> sol(n);
        
        map<int,int> help;
        int ans=0;
        for(int i=0;i<n;i++){
            help[A[i]]++;
            help[B[i]]++;
            
            if(help[A[i]]==2){
                ans++;
            }
            
            if(help[B[i]]==2 and A[i]!=B[i]){
                ans++;
            }
            
            sol[i]=ans;
            
        }
        return sol;
    }
};