#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
            vector<vector<int> > sort_by_y,sort_by_x;
            
            for(auto r:rectangles){
                sort_by_y.push_back({r[1],r[3]});
                sort_by_x.push_back({r[0],r[2]});
            }
            
            sort(sort_by_y.begin(),sort_by_y.end());
            sort(sort_by_x.begin(),sort_by_x.end());
            
            int en_x=-1,en_y=-1;
            int seg_y=0,seg_x=0;
            
            for(auto s:sort_by_y){
                if(s[0]>=en_y){
                    seg_y++;
                    en_y=s[1];
                }else{
                    en_y=max(en_y,s[1]);
                }
            }
            
            for(auto s:sort_by_x){
                if(s[0]>=en_x){
                    seg_x++;
                    en_x=s[1];
                }else{
                    en_x=max(en_x,s[1]);
                }
            }
            
            return seg_y>=3 or seg_x>=3;
        }
    };