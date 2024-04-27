#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    
    map<string,int> index;
    int blocked[10005];
    vector<int> adj[10005];
    int dis[10005];
    
    string get_string(int num){
        string sol;
        while(num){
            sol=sol+char('0'+num%10);
            num/=10;
        }
        while(sol.size()<4)sol=sol+'0';
        reverse(sol.begin(),sol.end());
        return sol;
    }
    
    char get_next(char ch,int d){
        return char('0'+((ch-'0')+d+10)%10);
    }
    
    
    
    
    int openLock(vector<string>& deadends, string target) {
       
        for(int i=0;i<=9999;i++){
            index[get_string(i)]=i;
            blocked[i]=0;
            dis[i]=1000000;
        }
        
        for(auto d:deadends){
            if(d==target)return -1;
            blocked[index[d]]=1;
        }
        
        
    
        queue<int> q;
        int iter=0;
        
        if(blocked[0]==0){
            dis[0]=0;
            q.push(0);
        }
        
        while(q.size()){
            int v=q.front();

            
            if(index[target]==v) return dis[v];
            q.pop();
     
            string c=get_string(v);

            for(int j=0;j<4;j++){
                
                char ch=c[j];
                
                c[j]=get_next(ch,1); 
                if(dis[index[c]]>dis[v]+1 and blocked[index[c]]==0){
                    dis[index[c]]=dis[v]+1;
                    q.push(index[c]);
                }
                
                
                c[j]=get_next(ch,-1);
                
                
                if(dis[index[c]]>dis[v]+1 and blocked[index[c]]==0){
                    dis[index[c]]=dis[v]+1;
                    q.push(index[c]);
                }
                
                c[j]=ch;
            }
        }
        
        
        return -1;
        
        
    
    }
};