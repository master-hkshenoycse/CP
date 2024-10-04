#include<bits/stdc++.h>
using namespace std;
class AllOne {
public:
    set<pair<int,string> > key_ranks;
    map<string,int> key_counter;
    AllOne() {
        key_ranks.clear();
        key_counter.clear();
    }
    
    void inc(string key) {
        if(key_counter.find(key) != key_counter.end()){
            key_ranks.erase(key_ranks.find({key_counter[key],key}));
        }
        
        key_counter[key]++;
        key_ranks.insert({key_counter[key],key});
    }
    
    void dec(string key) {
        key_ranks.erase(key_ranks.find({key_counter[key],key}));
        key_counter[key]--;

        if(key_counter[key]>0){
            key_ranks.insert({key_counter[key],key});
        }else{
            key_counter.erase(key);
        }
    }
    
    string getMaxKey() {

        if(key_ranks.size()==0){
            return "";
        }

        auto it=*(--key_ranks.end());
        return it.second;
        
    }
    
    string getMinKey() {

        if(key_ranks.size()==0){
            return "";
        }

        auto it=*key_ranks.begin();
        return it.second;
        
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */