#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string removeOuterParentheses(string S) {
        stack<int> bra;
        map<int,int> remove;
        int n=S.size();
        for(int i=0;i<n;i++){
            if(S[i]=='(')bra.push(i);
            else{
                int x=bra.top();
                bra.pop();
                if(bra.size()==0)remove[i]=1,remove[x]=1;
            }
        }
        string ans;
        for(int i=0;i<n;i++) if(remove[i]==0)ans+=S[i];
        return ans;
    }
};