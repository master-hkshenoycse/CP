//https://codeforces.com/blog/entry/57534
/*
It is well known that given points (x, y) 
and you need to calculate the Manhattan distances between them, 
instead of using |x1-x2|+|y1-y2| you can first convert all points (x, y) into (x+y, x-y) 
and the distances will become max(|x1-x2|, |y1-y2|) (also known as Chebyshev distance).
*/

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int minimumDistance(vector<vector<int>>& points) {
        int n=points.size();
        for(int i=0;i<n;i++){
            int x=points[i][0];
            int y=points[i][1];
            points[i][0]=x+y;
            points[i][1]=x-y;
        }
        int ans=INT_MAX;
        vector<int> max_x_suffix(n+2,INT_MIN),min_x_suffix(n+2,INT_MAX);
        vector<int> max_y_suffix(n+2,INT_MIN),min_y_suffix(n+2,INT_MAX);
        
        for(int i=n;i>=1;i--){
            max_x_suffix[i]=max(max_x_suffix[i+1],points[i-1][0]);
            min_x_suffix[i]=min(min_x_suffix[i+1],points[i-1][0]);

            max_y_suffix[i]=max(max_y_suffix[i+1],points[i-1][1]);
            min_y_suffix[i]=min(min_y_suffix[i+1],points[i-1][1]);
        }

        int prefix_min_x=INT_MAX,prefix_max_x=INT_MIN,prefix_min_y=INT_MAX,prefix_max_y=INT_MIN;
        
        for(int i=1;i<=n;i++){

            if(i==1){
                ans=min(ans,max(max_x_suffix[i+1]-min_x_suffix[i+1],max_y_suffix[i+1]-min_y_suffix[i+1]));
            }else if(i==n){
                ans=min(ans,max(prefix_max_x-prefix_min_x,prefix_max_y-prefix_min_y));
            }else{
                int distance=max(max(prefix_max_x,max_x_suffix[i+1])-min(prefix_min_x,min_x_suffix[i+1]),
                                 max(prefix_max_y,max_y_suffix[i+1])-min(prefix_min_y,min_y_suffix[i+1])
                                );
                
                ans=min(ans,distance);
            }

            prefix_max_x=max(prefix_max_x,points[i-1][0]);
            prefix_min_x=min(prefix_min_x,points[i-1][0]);

            prefix_max_y=max(prefix_max_y,points[i-1][1]);
            prefix_min_y=min(prefix_min_y,points[i-1][1]);

            cout<<ans<<endl;
        }


        return ans;

    }
};