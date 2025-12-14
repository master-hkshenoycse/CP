#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    pair<int,int> get_slope(vector<int> &p1,vector<int> &p2){
        int num = p2[1]-p1[1];
        int den = p2[0]-p1[0];
        
        if(num == 0) return {0,1};
        if(den == 0) return {1,0};
        
        if(num<0){
            num*=-1;
            den*=-1;
        }

        int gc = __gcd(abs(num),abs(den));
        num/=gc;
        den/=gc;
        return {num,den};
    }
    
    int countTrapezoids(vector<vector<int>>& points) {
        int n=points.size();
        
        map<pair<int,int> , map<int,int> > slopes_intercept;
        map<pair<int,int> , int > midpoints;
        map<pair<int,int> , map< pair<int,int> ,int> > midpoint_slope;

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
            
                pair<int,int> slope = get_slope(points[i],points[j]);
                int intercept= slope.second * points[i][1]-slope.first*points[i][0];
                slopes_intercept[slope][intercept]++;

                pair<int,int> midpoint= make_pair(points[i][0]+points[j][0],points[i][1]+points[j][1]);
                midpoints[midpoint]++;
                midpoint_slope[midpoint][slope]++;
            
            }
        }

        int trapizoids=0,parllelgm=0,ret=0;

        for(auto sp:slopes_intercept){
            int tot=0;
            for(auto inter:slopes_intercept[sp.first]){
                trapizoids=trapizoids+tot*inter.second;
                tot+=inter.second;
            }
        }

        for(auto mp:midpoints){
            parllelgm = parllelgm + (mp.second*(mp.second-1))/2;
        }

        for(auto mp_s:midpoint_slope){
            for(auto sl:midpoint_slope[mp_s.first]){
               parllelgm = parllelgm -(sl.second*(sl.second-1))/2;
            }
        }

        ret=trapizoids-parllelgm;
        return ret;
    }
};