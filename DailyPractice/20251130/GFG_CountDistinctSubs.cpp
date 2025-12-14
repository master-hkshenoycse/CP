#include<bits/stdc++.h>
using namespace std;
class node
{
    public:
    bool end;
    vector<node*> child;
    node()
    {
        end=false;
        child.assign(26,nullptr);
        
    }
    ~node()
    {
        for(auto c:child)
        {
            if(c) delete c;
        }
    }
    bool haschild(char c)
    {
        return child[c-'a']!=nullptr;
    }
    void putchild(char c)
    {
        child[c-'a']=new node();
    }
    node* getchild(char c)
    {
        return child[c-'a'];
    }
};
class trie
{
    public:
    node * root;
    trie()
    {
        root=new node();
    }
    ~trie()
    {
        delete root;
    }
    
};
class Solution {
  public:
    int countSubs(string& s) {
        // code here
         int ans=0;
    trie* t=new trie();
    node* root=t->root;
    int n=s.size();
    for(int i=0;i<n;i++)
    {
        node * tmp=root;
        for(int j=i;j<n;j++)
        {
          if(!tmp->haschild(s[j]))
          {
            ans++;
            tmp->putchild(s[j]);
          }
          tmp=tmp->getchild(s[j]);
        }
    }
    delete t;
    return ans;
    }
};