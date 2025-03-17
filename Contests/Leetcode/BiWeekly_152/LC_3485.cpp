#include<bits/stdc++.h>
using namespace std;
struct trie_node{
    trie_node *child[26];
    int node_id=0,cnt=0;
    
    trie_node(int id){
        
        for(int i=0;i<26;i++){
            child[i]=NULL;
        }
        cnt=0;
        node_id=id;
    }
    
};
class Solution {
public:
    int id=0;
    set<pair<int,int> > len_by_node;
    
    void insert(trie_node *root,string &w,int k){
        
        int len=0;
        for(auto ch:w){
            
            if(root->child[ch-'a']==NULL){
                id++;
                root->child[ch-'a']=new trie_node(id);
            }
            
            root=root->child[ch-'a'];
            len++;
            root->cnt++;
            
            if(root->cnt>=k){
                if(len_by_node.find({len,root->node_id}) == len_by_node.end()){
                    len_by_node.insert({len,root->node_id});
                }
            }
            
            
            
        }
    }
    
    int do_query(trie_node *root,string &w,int k){
        
        
        int len=0;
        for(auto ch:w){
            len++;
            root=root->child[ch-'a'];
            root->cnt--;
            
            if(root->cnt < k){
                if(len_by_node.find({len,root->node_id}) != len_by_node.end()){
                    len_by_node.erase({len,root->node_id});
                }
            }
        }
        
        int ret=0;
        if(len_by_node.size()>0){
            auto it = *(--len_by_node.end());
            ret= it.first;
        }
        
        return ret;
    }
    vector<int> longestCommonPrefix(vector<string>& words, int k) {
        trie_node *root= new trie_node(0);
        
        
        for(auto w:words){
            insert(root,w,k);
        }
        
        
        vector<int> sol;
        int n=words.size();
        
        for(int i=0;i<n;i++){
            int ret=do_query(root,words[i],k);
            sol.push_back(ret);
            insert(root,words[i],k);
            
        }
        
        return sol;
        
        
    }
};