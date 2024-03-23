#include<bits/stdc++.h>
using namespace std;

int largestSubsquare(int n, vector<vector<char>> a) {
        // code here
        vector<vector<int> >ver(n,vector<int> (n,0));//max consecative X ending at (i,j) in vertical direction
        vector<vector<int> >hor(n,vector<int> (n,0));//max consecative X ending at (i,j) in horizontal direction
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(a[i][j]=='X'){
                    
                    if(i==0){
                        ver[i][j]=1;
                    }else{
                        ver[i][j]=ver[i-1][j]+1;
                    }
                    
                    if(j==0){
                        hor[i][j]=1;
                    }else{
                        hor[i][j]=hor[i][j-1]+1;
                    }
                }
                
            }
        }
        
        int ans=0;
        for(int i=n-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                int val=min(ver[i][j],hor[i][j]);
                
                while(val>ans){
                    if(ver[i][j-val+1]>=val and hor[i-val+1][j]>=val){
                        ans=val;
                    }
                    val--;
                }
                
            }
        }
        
        return ans;
        
        
        
    }