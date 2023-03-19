class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 1, r = s.size(), m, ans = 1;
        vector<int> frq(26);
        while (l <= r){
            m = (l+r) >> 1;
            bool ok = 0;
            for (int i = 0; i < 26; i++) frq[i] = 0;
            for (int i = 0; i < m - 1; i++) frq[s[i] - 'A']++;
            for (int i = 0, j = m-1; j < s.size(); i++, j++){
                frq[s[j] - 'A']++;
                int mx = frq[0];
                for (int k = 0; k < 26; k++) mx = max(mx, frq[k]);
                if (m - mx <= k){
                    ok = 1;
                    break;
                }
                frq[s[i] - 'A']--;
            }
            if (ok)
                ans = m, l = m + 1;
            else 
                r = m - 1;
        }
        return ans;
    }
};