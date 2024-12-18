#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int check(vector<int> &p1,vector<int> &p2, vector<int> &p3,vector<int> &p4){
        int min_x=110,max_x=-110,min_y=110,max_y=-110;
        vector<vector<int> > p={p1,p2,p3,p4};

        for(int i=0;i<4;i++){

            min_x=min(min_x,p[i][0]);
            max_x=max(max_x,p[i][0]);
            min_y=min(min_y,p[i][1]);
            max_y=max(max_y,p[i][1]);
        }

        if(min_x==max_x or min_y==max_y){
            return 0;
        }
        vector<vector<int> > cons={{min_x,min_y},{min_x,max_y},{max_x,min_y},{max_x,max_y}};

        for(auto c:cons){
            int f=0;
            for(auto q:p){
                if(q[0]==c[0] and q[1]==c[1]){
                    f=1;
                    break;
                }
            }

            if(f==0){
                return 0;
            }
        }

        return (max_x-min_x)*(max_y-min_y);
    }

    bool check_inside(vector<int> &p1,vector<int> &p2, vector<int> &p3,vector<int> &p4,vector<int> &q){
        int min_x=110,max_x=-110,min_y=110,max_y=-110;
        vector<vector<int> > p={p1,p2,p3,p4};

        for(int i=0;i<4;i++){
            
            min_x=min(min_x,p[i][0]);
            max_x=max(max_x,p[i][0]);
            min_y=min(min_y,p[i][1]);
            max_y=max(max_y,p[i][1]);
        }

        return (q[0]>=min_x and q[0]<=max_x and q[1]>=min_y and q[1]<=max_y);
    }
    int maxRectangleArea(vector<vector<int>>& points) {
        int n=points.size();
        int ans=-1;

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                for(int k=j+1;k<n;k++){
                    for(int l=k+1;l<n;l++){
                        int area=check(points[i],points[j],points[k],points[l]);
                        if(area>0){

                            int f=1;
                            for(int p=0;p<n;p++){
                                if(p==i || p==j || p==k || p==l){
                                    continue;
                                }
                                if(check_inside(points[i],points[j],points[k],points[l],points[p])){
                                    f=0;
                                    break;
                                }
                            }

                            if(f){
                                ans=max(ans,area);
                            }
                        }                        

                    }
                }
            }
        }

        return ans;
    }
};