#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void rec(string &curr,vector<string> &sol,int n){
        if(curr.size()==n){
            sol.push_back(curr);
            return;
        }
        
        curr.push_back('1');
        rec(curr,sol,n);
        curr.pop_back();
        
        if(curr.size()==0 or curr.back()!='0'){
            curr.push_back('0');
            rec(curr,sol,n);
            curr.pop_back();
        }
        
    }
    vector<string> validStrings(int n) {
        vector<string> sol;
        string curr;
        
        rec(curr,sol,n);
        
        return sol;
    }
};