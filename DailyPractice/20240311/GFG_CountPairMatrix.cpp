#include<bits/stdc++.h>
using namespace std;


int countPairs(vector<vector<int>> &mat1, vector<vector<int>> &mat2, int n, int x)
{
    // Your code goes here
    int ans=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int req=x-mat1[i][j];
            int p=0,q=n-1;
            while(p<n and q>=0){
                if(mat2[p][q]==req){
                    ans++;
                    break;
                }
                if(mat2[p][q]>req){
                    q--;
                }else{
                    p++;
                }
            }
        }
    }
    
    return ans;
}