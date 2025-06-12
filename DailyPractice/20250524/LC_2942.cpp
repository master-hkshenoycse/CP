#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        vector<int> findWordsContaining(vector<string>& words, char x) {
            vector<int> sol;
            int n=words.size();
            
            for(int i=0;i<n;i++){
                int f=0;
                for(auto ch:words[i]){
                    if(ch==x){
                        f=1;
                        break;
                    }
                }
                
                if(f){
                    sol.push_back(i);
                }
            }
            
            return sol;
        }
    };