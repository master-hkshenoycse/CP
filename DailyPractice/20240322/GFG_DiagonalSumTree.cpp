#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *left,*right;
};


class Solution
{
    public:
    vector <int> diagonalSum(Node* root) {
        // Add your code here
        queue<pair<Node *,int> > q;
        q.push({root,0});
        int d=0;
        map<int,int> help;
        
        while(q.size()>0){
            int sz=q.size();
            
            for(int i=0;i<sz;i++){
                Node *curr=q.front().first;
                int h=q.front().second;
                q.pop();
                //cout<<h<<" "<<d<<" "<<curr->data<<endl;
                help[d-h]+=curr->data;
                
                if(curr->left){
                    q.push({curr->left,h-1});
                }
                
                if(curr->right){
                    q.push({curr->right,h+1});
                }
                
            }
            
            d++;
        }
        
        vector<int> sol;
        for(auto it:help){
            sol.push_back(it.second);
        }
        return sol;
    }
};