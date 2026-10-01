#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    char get_c(char ch){
        if(ch==')')return '(';
        if(ch=='}') return '{';
        return '[';
    }
    bool isValid(string s) {
        stack<char> op_pr;
        int n=s.size();
        
        for(int i=0;i<n;i++){
            
            if(s[i]=='(' or s[i]=='[' or s[i]=='{')op_pr.push(s[i]);
            else{
               if(op_pr.size()==0)return 0;
               if(op_pr.top() != get_c(s[i]))return 0;
               op_pr.pop();
            }
 
        }
        
        
        
        return op_pr.size()==0;
    }
};