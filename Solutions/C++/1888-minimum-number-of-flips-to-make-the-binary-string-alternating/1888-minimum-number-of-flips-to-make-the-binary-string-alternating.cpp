class Solution {
public:
    int minFlips(string s) {
        s += s;
        int n = s.size();
        vector<vector<int>> need(n, vector<int>(2, 0));
        
        for (int i = 0; i < n; i++){
            int zero = (s[i] == '0');
            if (i % 2 == 0){
                need[0][0] += !zero;
                need[0][1] += zero;
            }else {
                need[0][0] += zero;
                need[0][1] += !zero;
            }
        }
        for (int i = 1; i < n; i++){
            need[i][0] = need[i-1][1] - (s[i-1] == '0');
            need[i][1] = need[i-1][0] - (s[i-1] != '0');
        }
        
        int mn = n;
        n /= 2;
        for (int i = 0; i < n; i++){
            mn = min(mn, min(need[i][0] - need[i+n][(n%2)], need[i][1] - need[i+n][(n%2==0)]));
        }
        return mn;
        
    }
};