#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int a[15][15];
    int b[15][15];
    int c[15][15];
    int n;
    void rotate(){
        int N=n;
        
        for (int i = 0; i < N / 2; i++) {
            for (int j = i; j < N - i - 1; j++) {
 
            // Swap elements of each cycle
            // in clockwise direction
            int temp = a[i][j];
            a[i][j] = a[N - 1 - j][i];
            a[N - 1 - j][i] = a[N - 1 - i][N - 1 - j];
            a[N - 1 - i][N - 1 - j] = a[j][N - 1 - i];
            a[j][N - 1 - i] = temp;
        }
    }
        
    }
    bool chk(){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(a[i][j] != b[i][j])return 0;
            }
        }
        return 1;
    }
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        n=mat.size();

        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                a[i][j]=mat[i][j];
                b[i][j]=target[i][j];
           }
        }
        
        int cnt=0;
        while(cnt<5){
            
            if(chk()){
                return 1;
            }
            
            
            cnt++;
            rotate();
        }
        
        return 0;
    }
};