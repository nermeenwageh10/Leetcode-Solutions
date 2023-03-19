class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
       unordered_set<int> hashset;
       for(int n : nums){
            if(hashset.count(n) == 1) // The element exists in the Set
                return true;
            else
                hashset.insert(n);
        }
        
        return false;
    }
};
