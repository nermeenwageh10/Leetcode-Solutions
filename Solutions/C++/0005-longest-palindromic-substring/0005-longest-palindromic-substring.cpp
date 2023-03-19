class Solution {
public:
    string longestPalindrome(string s) {
        int pos = -1, sz = 0, n = s.size();
        for (int i = 0; i < n; i++)
        {
            // odd 
            int l = i-1, r = i + 1;
            while(l >= 0 && r < n && s[l] == s[r])
                l--,r++;
            l++,r--;
            if (r - l + 1 > sz)
            {
                sz = r - l + 1;
                pos = l;
            }
            // even 
            l = i, r = i + 1;
            while(l >= 0 && r < n && s[l] == s[r])
                l--,r++;
            l++,r--;
            if (r - l + 1 > sz)
            {
                sz = r - l + 1;
                pos = l;
            }
        }
        return s.substr(pos, sz);
    }
};