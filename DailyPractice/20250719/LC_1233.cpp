#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        static bool comp(string &a,string &b){
            return a.size()<b.size();
        }
        vector<string> removeSubfolders(vector<string>& folder) {
            sort(folder.begin(),folder.end(),comp);
            vector<string> sol;
            set<string> fol;
            for(auto f:folder){
                string tmp;
                int use=1;
                for(int i=0;i<f.size();i++){
                    if(f[i]=='/'){
    
                        if(fol.find(tmp) != fol.end()){
                            use=0;
                            break;
                        }
                    }
    
                    tmp+=f[i];
                }
    
                if(use){
                    fol.insert(f);
                    sol.push_back(f);
                }
            }
    
            return sol;
        }
    };