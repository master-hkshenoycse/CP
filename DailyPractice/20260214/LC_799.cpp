#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    double a[105][105];
    double champagneTower(int poured, int query_row, int query_glass) {
        
        
        a[0][0]=poured*1.000;
        
        for(int i=0;i<=query_row;i++){
            for(int j=0;j<=i;j++){
                
                    double ex=max(a[i][j]-1.000,0.00);
                    ex/=2.0000;
                    a[i+1][j]+=ex;
                    a[i+1][j+1]+=ex;
                    a[i][j]=min(a[i][j],1.0000);
                
                //cout<<a[i][j]<<" ";
            }
          //  cout<<endl;
        }
        
        
        
        return a[query_row][query_glass];
    }
};