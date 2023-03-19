class Solution {
public:
    bool valid_alpha(char c){
        return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9');
    }
    char to_lower(char c){
        if (c >= 'A' && c <= 'Z') return c + 32;
        return c;
    }
    bool isPalindrome(string s) {
        int l = 0, r = s.size()-1;
        while (l < r){
            while (l < r && !valid_alpha(s[l]))
                l++;
            while (r >= l && !valid_alpha(s[r]))
                r--;
            s[l] = to_lower(s[l]);
            s[r] = to_lower(s[r]);
            if (l >= r) break;
            if (s[l] != s[r]) return 0;
            l++;
            r--;
        }
        return 1;
    }
};