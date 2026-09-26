#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        stack<int> op_br;
        map<string,string> help;
        for(auto it:knowledge){
            help[it[0]]=it[1];
        }
        
        string sol;
        int n=s.size();
        string key;
        
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                op_br.push(i);
            }else if(op_br.size()==0){
                sol+=s[i];
            }else if(s[i]!=')'){
                key+=s[i];
            }else{
                op_br.pop();
                if(help.find(key) == help.end()){
                    sol+='?';
                }else{
                    sol+=help[key];
                }
                    
                key="";
        
            }
        }
        return sol;
        
    }
};