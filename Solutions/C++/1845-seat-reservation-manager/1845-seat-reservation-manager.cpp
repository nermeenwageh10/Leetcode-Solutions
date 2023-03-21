class SeatManager {
public:
    set<int> unlocked;
    int toTake = 1;
    SeatManager(int n) {}
    
    int reserve() {
        if (unlocked.size()){
            int val = *unlocked.begin();
            unlocked.erase(val);
            return val;
        }
        return toTake++;
    }
    
    void unreserve(int seatNumber) {
        unlocked.insert(seatNumber);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */