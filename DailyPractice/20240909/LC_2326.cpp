#include<bits/stdc++.h>
using namespace std;
struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int> > sol(m,vector<int>(n,-1));

        int dx[4]={0,1,0,-1};
        int dy[4]={1,0,-1,0};
        int d=0,x=0,y=0;

        while(head){
            int data=head->val;
            sol[x][y]=data;
            head=head->next;
            
            for(int p=0;p<4;p++){
                int nx_dir=(d+p)%4;
                int nx=x+dx[nx_dir];
                int ny=y+dy[nx_dir];
            
                if(nx>=0 and nx<m and ny>=0 and ny<n and sol[nx][ny]==-1){
                    d=nx_dir;
                    x=nx;
                    y=ny;
                    break;
                }
            }
        }

        return sol;
    }   
};