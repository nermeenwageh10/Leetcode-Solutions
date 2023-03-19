class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> need(128, 0);
        vector<int> cur(128, 0);
        int tot = 0;
        for (int i = 0; i < t.size(); i++)
            need[t[i]]++;
        for (int i = 0; i < 128; i++)
            tot += (need[i] > 0);
        int l = 0, r = 0;
        int L = -1, sz = 1e9;
        int curTot = 0;
        
        while(r < s.size())
        {
            
            while (curTot < tot && r < s.size())
            {
                if (++cur[s[r]] == need[s[r]])
                    curTot++;
                r++;
            }
            if (curTot == tot)
            {
                while(l < r && cur[s[l]] - 1 >= need[s[l]])
                    cur[s[l]]--, l++;
                if (r - l < sz)
                    sz = r - l, L = l;
                if (--cur[s[l]] < need[s[l]])
                    curTot--;
                l++;
                if (l > r)
                    r = l;
            }
            
        }
        if (L == -1)return "";
        return s.substr(L, sz);
    }
};