class Solution {
public:
    int countPalindromicSubsequence(string s) {
        vector<int> prefix(26, 0), suffix(26, 0);
        for (int i = 0; i < s.size(); i++) 
            suffix[s[i] - 'a']++;
        int ans = 0;
        vector<vector<bool>> seen(26);
        for (int i = 0; i < 26; i++) {
            seen[i] = vector<bool>(26, 0);
        }
        for (int i = 0; i < s.size(); i++){
            suffix[s[i] - 'a']--;
            for (int j = 0; j < 26; j++){
                if (prefix[j] && suffix[j]){
                    if (seen[j][s[i] - 'a'] == 0){
                        ans++;
                        seen[j][s[i] - 'a'] = 1;
                    }
                }
            }
            prefix[s[i] - 'a']++;
        }
        return ans;
    }
};