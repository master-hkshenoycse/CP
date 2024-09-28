#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    struct trie_node{
        int cnt;
        trie_node *child[26];

        trie_node(){
            cnt=0;
            for(int i=0;i<26;i++){
                child[i]=NULL;
            }
        }
    };
    void insert(trie_node *root,string &w){
        for(auto ch:w){
            if(root->child[ch-'a']==NULL){
                root->child[ch-'a']=new trie_node();
            }
            root=root->child[ch-'a'];
            root->cnt++;

        }
    }

    void get_sol(trie_node *root,string &w,int &sol){

        for(auto ch:w){
            
            root=root->child[ch-'a'];
            sol+=root->cnt;

        }


    }
    vector<int> sumPrefixScores(vector<string>& words) {
        trie_node *root=new trie_node();
        int n=words.size();
        vector<int> sol(n,0);

        for(int i=0;i<n;i++){
            insert(root,words[i]);
        }

        for(int i=0;i<n;i++){
            get_sol(root,words[i],sol[i]);
        }

        return sol;
    }
};