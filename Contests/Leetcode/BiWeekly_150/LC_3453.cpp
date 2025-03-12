#include<bits/stdc++.h>
using namespace std;
#define dd double
class Solution {
public:
    double separateSquares(vector<vector<int>> &squares) {
        dd lo=0,hi=1500000000;
        dd ret=hi;
        dd tot_area=0.0;
        int n=squares.size();
        
        for(auto sq:squares){
            tot_area+=(sq[2]*1.00)*(sq[2]*1.00);
        }

        for(;abs(hi-lo) >= 0.00001 ;){
            dd mid=(lo+hi)/2.00;
            dd area_above = 0.00;
            dd area_below = 0.00;
            
            for(int i=0;i<n;i++){

                dd y=squares[i][1]*1.00;
                dd l=squares[i][2]*1.00;

                if(y>=mid){
                    area_above+=l*l;
                }else if(y+l<=mid){
                    //area_below+=l*l;
                }else{
                    //area_below+=(mid-y)*l;
                    area_above+=(y+l-mid)*l;
                }

                if(area_above > tot_area/2.00){
                    break;
                }
            }
            area_below=tot_area-area_above;
            //cout<<mid<<" "<<area_above<<" "<<area_below<<endl;
            if(area_below >= area_above){
                ret=min(ret,mid);
                hi=mid-0.000001;
            }else{
                lo=mid+0.000001;    
            }

            
        }

        return ret;
    }
};