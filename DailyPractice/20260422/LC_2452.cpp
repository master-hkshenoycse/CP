#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string> sol;
        for(auto q:queries){
            int f=0;
            
            for(auto d:dictionary){
                if(d.size() == q.size()){
                   
                    int c=0,sz=d.size();
                    for(int i=0;i<sz;i++){
                        if(q[i] != d[i]){
                            c++;
                        }
                        if(c>2){
                            break;
                        }
                    }
                    
                    if(c<=2){
                        f=1;
                        break;
                    }
                    
                    
                }
            }
            
            if(f){
                sol.push_back(q);
            }
        }
        return sol;
    }
};