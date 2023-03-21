class Solution {
public:
    bool check(string& s){
        for (int i = 0, j = s.size()-1; i < j; i++, j--){
            if (s[i] != s[j])
                return 0;
        }
        return 1;
    }
    int maxProduct(string s) {
        vector<vector<int>> palindrom;
        int n = s.size();
        for (int i = 1; i < (1<<n); i++){
            string cur = "";
            for (int j = 0; j < n; j++){
                if (i & (1<<j)){
                    cur += s[j];
                }
            }
            if (check(cur)){
                palindrom.push_back({(int)cur.size(), i});
            }
        }
        n = palindrom.size();
        int ans = 0;
        for (int i = 0; i < n; i++){
            for (int j = i + 1; j < n; j++){
                int msk1 = palindrom[i][1];
                int msk2 = palindrom[j][1];
                int prod = palindrom[i][0] * palindrom[j][0];
                if ((msk1 & msk2) == 0){
                    ans = max(ans, prod);
                }
            }
        }
    return ans;
  }
};