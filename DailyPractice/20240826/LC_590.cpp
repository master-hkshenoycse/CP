#include<bits/stdc++.h>
using namespace std;
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};


class Solution {
public:
    void rec(Node *root,vector<int> &sol){
        if(root==NULL){
            return;
        }
        for(auto c:root->children){
            rec(c,sol);
        }
        sol.push_back(root->val);
    }
    vector<int> postorder(Node* root) {
        vector<int> sol;
        rec(root,sol);
        return sol;
    }
};