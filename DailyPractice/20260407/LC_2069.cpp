#include<bits/stdc++.h>
using namespace std;
class Robot {
public:
    vector<vector<int> > pos;
    int w,h,x=0,y=0,p=0,sz=0,f=0;
    int vis[105][105];
    
    Robot(int width, int height) {
        w=width;
        h=height;
        
        for(int i=0;i<width;i++){
            pos.push_back({i,0});
        }
        for(int i=1;i<height;i++){
            pos.push_back({width-1,i});
        }
        
        for(int i=width-2;i>=0;i--){
            pos.push_back({i,height-1});
        }
        
        for(int i=height-2;i>0;i--){
            pos.push_back({0,i});
        }
            
            
        sz=pos.size();
        
        
    }
    
    void step(int num) {
        p=(p+num)%sz;
        f=1;

    }
    
    vector<int> getPos() {
        return pos[p];
    }
    
    string getDir() {
        
        if(pos[p][0]==0 and pos[p][1]==0 and f==1) return "South";
        if(pos[p][1]==0)return "East";
        if(pos[p][0]==w-1)return "North";
        if(pos[p][1]==h-1)return "West";
        return "South";
        
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->move(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */