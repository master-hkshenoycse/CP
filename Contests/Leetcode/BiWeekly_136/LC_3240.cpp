#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minFlips(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        
        int ans=0;
        


        int one_turned_1=0,one_turned_2=0;
        int c_1=0;
        
        
        for(int i=0;i<(n+1)/2;i++){
            for(int j=0;j<(m+1)/2;j++){
                
                set<pair<int,int> > cord;
                
                cord.insert({i,j});
                cord.insert({i,m-j-1});
                cord.insert({n-i-1,j});
                cord.insert({n-i-1,m-j-1});
                
                int c0=0,c1=0;
                for(auto c:cord){
                    c0+=(grid[c.first][c.second]==0);
                    c1+=(grid[c.first][c.second]);
                }
                
                
                
                if(cord.size()==4){
                    ans=ans+4-max(c0,c1);
                }else if(cord.size()==2){
                    if(c0==1 and c1==1){
                        c_1+=2;
                        ans+=1;
                        one_turned_1++;
                    }else if(c1==2){
                        c_1+=2;
                        one_turned_2++;
                    }
                }else{
                    
                    
                    ans=ans+(c0==0);//this needs to be 1 
                }
                
                
                
            }
        }
        
        
      
        cout<<ans<<" "<<c_1<<endl;
        
       
        if(c_1%4){
            if(one_turned_1>=1){
                ans-=0;
            }else{
                ans+=2;
            }
        }
        
        return ans;
    }
};