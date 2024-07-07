#include<bits/stdc++.h>
using namespace std;
struct trie_node{
    trie_node *child[26];
    int is_end;
    int cost;
    
    trie_node(){
        for(int i=0;i<26;i++){
            child[i]=NULL;
        }
        is_end=0;
        cost=1e9;
    }
};

class Solution {
public:
    void insert(trie_node *root,string &w,int &c){
        for(auto ch:w){
            int v=ch-'a';
            if(root->child[v]==NULL){
                root->child[v]=new trie_node();
            }
            root=root->child[v];
        }
        root->is_end=1;
        root->cost=min(root->cost,c);
    }
    
    int solve(int ind,string &target,vector<int> &dp,trie_node *root){
        
       // cout<<ind<<endl;
        
        if(ind==target.size()){
            return 0;
        }
        
        if(dp[ind] != -1){
            return dp[ind];
        }
        
        int res=1e9;
        int n=target.size();
        trie_node *tmp=root;
        int st=ind;
        
        while(ind<n){
            
            if(tmp->child[target[ind]-'a']==NULL){
                break;
            }
            
            tmp=tmp->child[target[ind]-'a'];
            
            if(tmp->is_end){
                res=min(res,tmp->cost+solve(ind+1,target,dp,root));
            }
                
            ind++;
            
        }
        
        return dp[st]=res;
    }
    int minimumCost(string target, vector<string>& words, vector<int>& costs) {
        int n=target.size();
        
        vector<int> dp(n,-1);

        trie_node *root;
        root=new trie_node();
        int m=words.size();
        
        for(int i=0;i<m;i++){
            insert(root,words[i],costs[i]);
        }
        
        
        int res=solve(0,target,dp,root);
        
        if(res==1e9){
            res=-1;
        }
        return res;
    }
};