class AuctionSystem {

    private:
    struct itemState{

        unordered_map<int,int> userBids;
        set<pair<int,int>> rankedBids;
    };

    unordered_map<int,itemState> items;
public:
    AuctionSystem() {
        
    }
    
    void addBid(int userId, int itemId, int bidAmount) {

        itemState& state = items[itemId];
        if(state.userBids.count(userId)) {
            int oldAmount = state.userBids[userId];
            state.rankedBids.erase({oldAmount,userId});
        }
        state.userBids[userId]=bidAmount;
        state.rankedBids.insert({bidAmount,userId});
    }
    
    void updateBid(int userId, int itemId, int newAmount) {

        itemState& state = items[itemId];
        
        int oldAmount = state.userBids[userId];
        state.rankedBids.erase({oldAmount,userId});
        
        state.userBids[userId]=newAmount;
        state.rankedBids.insert({newAmount,userId});
    }
    
    void removeBid(int userId, int itemId) {

        itemState& state = items[itemId];
        
        int amt = state.userBids[userId];
        state.rankedBids.erase({amt,userId});
        state.userBids.erase(userId);
    }
    
    int getHighestBidder(int itemId) {
        if(items.find(itemId) == items.end() || items[itemId].rankedBids.empty()) {

            return -1;
        }

        return items[itemId].rankedBids.rbegin()->second;
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