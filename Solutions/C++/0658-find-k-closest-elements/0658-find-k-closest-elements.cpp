class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        sort(arr.begin(), arr.end(), [&](int A, int B){
            if (abs(A - x) != abs(B - x)) return abs(A - x) < abs(B - x);
            return A < B;
        });
        arr.erase(arr.begin() + k, arr.end());
        sort(arr.begin(), arr.end());
        return arr;
    }
};