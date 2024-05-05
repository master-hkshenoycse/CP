
#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *left,*right;
};

class Solution{
  public:
    void rec(Node *root,int h,int d,map<int,int> &help){
        if(root){
            help[d]+=root->data;
            
            rec(root->left,h+1,d-1,help);
            rec(root->right,h+1,d+1,help);
        }
    }
    vector <int> verticalSum(Node *root) {
        // add code here.
        map<int,int> help;
        rec(root,0,0,help);
        
        vector<int> sol;
        for(auto it:help){
            sol.push_back(it.second);
        }
        
        return sol;
    }
};