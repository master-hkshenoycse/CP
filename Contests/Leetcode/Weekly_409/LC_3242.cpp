#include <bits/stdc++.h>
using namespace std;
class neighborSum {
public:
    vector<vector<int>> grid;
    vector<int> pos_x,pos_y;
    int n;
    int adj_dx[4]={-1,1,0,0};
    int adj_dy[4]={0,0,-1,1};

    int diag_dx[4]={-1,1,1,-1};
    int diag_dy[4]={1,1,-1,-1};

    neighborSum(vector<vector<int>>& grid) {
        this->grid=grid;
        this->n=grid.size();
        pos_x.resize((this->n)*(this->n));
        pos_y.resize((this->n)*(this->n));

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                pos_x[grid[i][j]]=i;
                pos_y[grid[i][j]]=j;
            }
        }
    }
    
    int adjacentSum(int value) {
        int x=pos_x[value];
        int y=pos_y[value];
        int ret=0;

        for(int i=0;i<4;i++){
            int nx=x+adj_dx[i];
            int ny=y+adj_dy[i];
            if(nx>=0 and nx<n and ny>=0 and ny<n){
                ret=ret+grid[nx][ny];
            }
        }

        return ret;
    }
    
    int diagonalSum(int value) {
        int x=pos_x[value];
        int y=pos_y[value];
        int ret=0;

        for(int i=0;i<4;i++){
            int nx=x+diag_dx[i];
            int ny=y+diag_dy[i];
            if(nx>=0 and nx<n and ny>=0 and ny<n){
                ret=ret+grid[nx][ny];
            }
        }

        return ret;
    }
};

/**
 * Your neighborSum object will be instantiated and called as such:
 * neighborSum* obj = new neighborSum(grid);
 * int param_1 = obj->adjacentSum(value);
 * int param_2 = obj->diagonalSum(value);
 */