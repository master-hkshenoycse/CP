
#include<bits/stdc++.h>
using namespace std;


class Manacher{


    public: 
    string s;
    vector<int> p;
    Manacher(string s){
        this->s=s;
        do_preprocess();
        build();
    }

    void do_preprocess(){
        string tmp;
        for(auto ch:s){
            tmp+='#';
            tmp+=ch;
        }
        tmp+='#';
        s=tmp;
    }

    void build(){
        int n=s.size();
        
        for(int i=0;i<n;i++){
            p.push_back(1);
        }

        int l=1,r=1;

        for(int i=1;i<n;i++){
           // cout<<i<<" "<<r+l-i<<endl;
            int x=0;
            if(r+l-i>=0){
                x=p[r+l-i];
            }
            p[i]=max(0,min(r-i,x));
           
            while(i+p[i]<n and i-p[i]>=0 and s[i+p[i]]==s[i-p[i]]){
                p[i]++;
            }

            if(i+p[i]>r){
                l=i-p[i];
                r=i+p[i];
            }

            
        }
    }
    
    void print(){
        cout<<"Printing the array"<<endl;
        cout<<s<<endl;
        for(int i=0;i<p.size();i++){
            cout<<p[i]<<" ";
        }
        cout<<endl;
    }

    //odd means odd length palindrome,use the arrya
    //even means center betweee two indices.

    int get_longest(int index,bool odd){
        int pos=2*index+1;
        if(odd==0){
            pos++;//center shifted to next
        }

        return p[pos]-1;
    }


    bool checkPalin(int l,int r){
        int center=(l+r)/2;
        int parity=((l%2)==(r%2));

        return (r-l+1)<=get_longest(center,parity);
    }
};

class Solution {
public:
    void dfs(int v,int p,vector<vector<int> >&adj,vector<int> &order,vector<int> &sub_sz,string &dfs_trav,string &s){
        
        sort(adj[v].begin(),adj[v].end());


        for(auto to:adj[v]){
            if(to==p){
                continue;
            }
            dfs(to,v,adj,order,sub_sz,dfs_trav,s);
            sub_sz[v]+=sub_sz[to];
        }
        sub_sz[v]++;
        dfs_trav+=s[v];
        order[v]=dfs_trav.size()-1;
    }
    vector<bool> findAnswer(vector<int>& parent, string s) {
        int n=s.size();
        vector<int> order(n,0),sub_sz(n,0);
        vector<vector<int> > adj(n);
        for(int i=0;i<n;i++){
            if(parent[i] != -1){
                adj[i].push_back(parent[i]);
                adj[parent[i]].push_back(i);
            }
        }

        string dfs_trav;
        dfs(0,-1,adj,order,sub_sz,dfs_trav,s);

        Manacher manacher(dfs_trav);
      
        vector<bool> sol(n,0);

        for(int i=0;i<n;i++){
            int end=order[i];
            int start=end-sub_sz[i]+1;
            
            if(manacher.checkPalin(start,end)){
                sol[i]=1;
            }
        }

        return sol;


    }
};