#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool is_ana(string x,string y){
        sort(x.begin(),x.end());
        sort(y.begin(),y.end());
        return x==y;
    }
    
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> sol;
        int n=words.size();
        for(int i=0;i<n;i++){
            if(i==0)sol.push_back(words[i]);
            else if(is_ana(words[i],words[i-1])==0){
                sol.push_back(words[i]);
            }
        }
        return sol;
    }
};