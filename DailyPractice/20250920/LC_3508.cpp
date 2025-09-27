#include<bits/stdc++.h>
using namespace std;
class Router {
public:
    vector<vector<int> > router;
    set<vector<int> > check_packet;
    vector<int> router_ts; 
    int curr_sz=0,start_index=-1;
    map<int,vector<int> > packets_dest;
    map<int,int> packets_ind;
    int sz_limit;
    
    Router(int memoryLimit) {
        curr_sz=0;
        start_index=-1;
        router.clear();
        router_ts.clear();
        sz_limit=memoryLimit;
    }
    
    bool addPacket(int source, int destination, int timestamp) {
        
            
        if(check_packet.find({source, destination,timestamp}) != check_packet.end()){
            return 0;
        }
        
        curr_sz++;
        router.push_back({source,destination,timestamp});
        check_packet.insert({source, destination,timestamp});
        packets_dest[destination].push_back(timestamp);
        
        if(curr_sz > sz_limit){
            curr_sz--;
            start_index++;
            packets_ind[router[start_index][1]]++;
            check_packet.erase({router[start_index][0], router[start_index][1],router[start_index][2]});
        }
        
        return 1;
    }
    
    vector<int> forwardPacket() {
        
        vector<int> ret;
        
        if(curr_sz>0){
            start_index++;
            curr_sz--;
            packets_ind[router[start_index][1]]++;
            check_packet.erase({router[start_index][0], router[start_index][1],router[start_index][2]});
            ret = router[start_index];
        }
        
        return ret;
    }
    
    int getCount(int destination, int startTime, int endTime) {
        
        if(packets_dest.find(destination) == packets_dest.end()){
            return 0;
        }
        
        int start_index = packets_ind[destination];
        
        int lb = lower_bound(packets_dest[destination].begin()+start_index,packets_dest[destination].end(),startTime)-packets_dest[destination].begin();
        int ub = upper_bound(packets_dest[destination].begin()+start_index,packets_dest[destination].end(),endTime)-packets_dest[destination].begin();
        
        
        return max(0,ub-lb);
    }
};

/**
 * Your Router object will be instantiated and called as such:
 * Router* obj = new Router(memoryLimit);
 * bool param_1 = obj->addPacket(source,destination,timestamp);
 * vector<int> param_2 = obj->forwardPacket();
 * int param_3 = obj->getCount(destination,startTime,endTime);
 */