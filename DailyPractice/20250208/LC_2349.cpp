#include<bits/stdc++.h>
using namespace std;
class NumberContainers {
public:
    map<int,set<int> > val_container;
    map<int,int> help;
    NumberContainers() {
        help.clear();
        val_container.size();
    }
    
    void change(int index, int number) {
        if(help.find(index)==help.end()){
            help[index]=number;
            val_container[number].insert(index);
        }else{
            val_container[help[index]].erase(index);
            help[index]=number;
            val_container[number].insert(index);
        }
    }
    
    int find(int number) {
        if(val_container[number].size()==0){
            return -1;
        }
        
        return *val_container[number].begin();
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */