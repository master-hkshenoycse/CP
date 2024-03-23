#include<bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


class Solution{
    public:
    //Function to store the zig zag order traversal of tree in a list.
    vector <int> zigZagTraversal(Node* root)
    {
    	// Code here
    	deque<Node*> dq;
    	vector<int> sol;
    	
    	dq.push_back(root);
    	int d=0;
    	
    	while(dq.size()>0){
    	    int sz=dq.size();
    	    
    	    if(d==0){
    	        for(int i=0;i<sz;i++){
    	            Node *curr=dq.back();
    	            dq.pop_back();
    	            sol.push_back(curr->data);
    	            
    	            if(curr->left){
    	                dq.push_front(curr->left);
    	            }
    	            
    	            if(curr->right){
    	                dq.push_front(curr->right);
    	            }
    	            
    	        }    
    	    }else{
    	        for(int i=0;i<sz;i++){
    	            Node *curr=dq.front();
    	            dq.pop_front();
    	            sol.push_back(curr->data);
    	            
    	            if(curr->right){
    	                dq.push_back(curr->right);
    	            }
    	            
    	            if(curr->left){
    	                dq.push_back(curr->left);
    	            }
    	            
    	            
    	            
    	        }
    	        
    	    }
    	    d=1-d;
    	}
    	
    	return sol;
    }
};