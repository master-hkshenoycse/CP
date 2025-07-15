#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        vector<string> divideString(string s, int k, char fill) {
            vector<string> sol;
            int n=s.size();
            
            string curr;
            for(int i=0;i<n;i++){
                curr+=s[i];
                if((i+1)%k==0){
                    sol.push_back(curr);
                    curr.clear();
                }
    
            }
            
            if(curr.size()>0){
                while(curr.size()<k){
                    curr+=fill;
                }
                sol.push_back(curr);
            }
            return sol;
        }
    };