#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    struct node{
        node *child[26];
        int len,str_index;
        node(){
            len=INT_MAX;
            str_index=-1;
            for(int i=0;i<26;i++){
                child[i]=NULL;
            }
        }
    };

    void insert(string &s,int i,node *root){
        int n=s.size();

        for(auto ch:s){
            if(root->child[ch-'a']==NULL){
                root->child[ch-'a']=new node();
            }
            root=root->child[ch-'a'];
            if(root->len > n){
                root->len=n;
                root->str_index=i;
            }
        }
    }

    int find_prefix(string &s,node* root){

        int ans=-1;
        for(auto ch:s){
            if(root->child[ch-'a']==NULL){
                return ans;
            }

            root=root->child[ch-'a'];
            ans=root->str_index;
        }

        return ans;


    }

    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        int n=wordsContainer.size();
        int min_len=INT_MAX;
        int default_index=-1;
        
        

        node *root=new node();
        for(int i=0;i<n;i++){
            reverse(wordsContainer[i].begin(),wordsContainer[i].end());
            if(wordsContainer[i].size() < min_len){
                min_len=wordsContainer[i].size();
                default_index=i;
            }
            insert(wordsContainer[i],i,root);
        }

        vector<int> sol;
        for(auto &q:wordsQuery){
            reverse(q.begin(),q.end());
            int ans=find_prefix(q,root);
            if(ans==-1){
                ans=default_index;
            }
            sol.push_back(ans);
        }        

        return sol;


    }
};