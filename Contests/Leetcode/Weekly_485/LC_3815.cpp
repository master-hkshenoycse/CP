#include<bits/stdc++.h>
using namespace std;
class AuctionSystem {
public:
    map<int,multiset<pair<int,int> > > itemBids;
    map<int,map<int,int> > userItemBids;

    AuctionSystem() {
        itemBids.clear();
        userItemBids.clear();    
    }
    
    void addBid(int userId, int itemId, int bidAmount) {
        if(userItemBids.find(userId) == userItemBids.end() || 
            userItemBids[userId].find(itemId) == userItemBids[userId].end()){

        }else{
            itemBids[itemId].erase({-userItemBids[userId][itemId], -userId});            
        }
        userItemBids[userId][itemId]=bidAmount;
        itemBids[itemId].insert({-bidAmount,-userId});
    }
    
    void updateBid(int userId, int itemId, int newAmount) {
        itemBids[itemId].erase({-userItemBids[userId][itemId], -userId});   
        userItemBids[userId][itemId]=newAmount;
        itemBids[itemId].insert({-newAmount,-userId});
    }
    
    void removeBid(int userId, int itemId) {
        itemBids[itemId].erase({-userItemBids[userId][itemId], -userId});
        userItemBids[userId].erase(itemId);
    }
    
    int getHighestBidder(int itemId) {
        if(itemBids.find(itemId) == itemBids.end())
            return -1;
        if(itemBids[itemId].size()==0)
            return -1;
        
        return -1*(*itemBids[itemId].begin()).second;
    }
};

/**
 * Your AuctionSystem object will be instantiated and called as such:
 * AuctionSystem* obj = new AuctionSystem();
 * obj->addBid(userId,itemId,bidAmount);
 * obj->updateBid(userId,itemId,newAmount);
 * obj->removeBid(userId,itemId);
 * int param_4 = obj->getHighestBidder(itemId);
 */