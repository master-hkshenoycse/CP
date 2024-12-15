#include<bits/stdc++.h>
using namespace std;
#define dd double
class Solution {
public:
    double get_cost(int x,int y){
        dd num=(dd)y-(dd)x;
        dd den=(dd)y*y+(dd)y;
        
        return num/den;
    }
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        double sol=0;
        int n=classes.size();
        
        
        priority_queue<pair<double,pair<int,int> > > q;
        for(int i=0;i<n;i++){
          //  cout<<get_cost(classes[i][0],classes[i][1])<<endl;
            q.push({get_cost(classes[i][0],classes[i][1]),{classes[i][0],classes[i][1]}});
        }
        
        
        while(extraStudents--){
            auto v=q.top();
            q.pop();
            
            
            int x=v.second.first;
            int y=v.second.second;

                    
            q.push({get_cost(x+1,y+1),{x+1,y+1}});
            
        }
        
        
        
        while(q.size()){
            auto v=q.top();
            q.pop();
        
            int x=v.second.first;
            int y=v.second.second;
            
            dd rat=(dd)x/(dd)y;
            sol=sol+rat;
        }
        
        sol=sol/(dd)n;
        
        return sol;
        
        
        
    }
};