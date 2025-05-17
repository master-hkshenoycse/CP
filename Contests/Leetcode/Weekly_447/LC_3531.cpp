#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
            vector< set<int> > x_cords(n+1),y_cords(n+1);
            for(auto b:buildings){
                x_cords[b[0]].insert(b[1]);
                y_cords[b[1]].insert(b[0]);
            }
    
    
            int ans=0;
            set<int>::iterator it;
    
            for(auto b:buildings){
                int x=b[0];
                int y=b[1];
    
                if(x_cords[x].lower_bound(y) != x_cords[x].begin() && x_cords[x].upper_bound(y) != x_cords[x].end()){
                    if(y_cords[y].lower_bound(x) != y_cords[y].begin() &&  y_cords[y].upper_bound(x) != y_cords[y].end()){
                        ans++;
                    }
                }
                
            }
    
    
            return ans;
        }
    };