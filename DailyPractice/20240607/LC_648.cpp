#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    struct node{
        node *child[26];
        bool is_end;
        node(){
            for(int i=0;i<26;i++){
                child[i]=NULL;
            }
            is_end=0;
        }
    };
    void insert(node *root,string &s){
        
        for(auto ch:s){
            int ind=ch-'a';
            if(root->child[ind]==NULL){
                root->child[ind]=new node();
            }

            root=root->child[ind];
        }
        root->is_end=1;
    }
    string find_root(node *root,string &s){
        string curr;
        for(auto ch:s){
            int ind=ch-'a';
            if(root->child[ind]==NULL){
                return s;
            }

            root=root->child[ind];
            curr+=ch;

            if(root->is_end){
                return curr;
            }
        }

        return s;
    }
    string replaceWords(vector<string>& dictionary, string sentence) {
        node  *root=new node();

        for(auto d:dictionary){
            insert(root,d);
        }

        string sol;
        int sz=sentence.size();
        string curr;

        for(auto ch:sentence){
            if(ch==' '){
                sol+=find_root(root,curr);
                sol+=' ';
                curr.clear();
            }else{
                curr+=ch;
            }
        }

        if(curr.size()>0){
            sol+=find_root(root,curr);
        }
        

        return sol;

    }
};