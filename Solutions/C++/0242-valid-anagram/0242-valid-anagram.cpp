class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size() || !t.size())return !t.size();
        int frq[26] = {0}; 
        for (int i =0 ; i< t.size() ;i++)
        {
            frq[ s[i] - 'a' ]++; 
            frq[ t[i] -'a']--;
        }
        for (int i =0 ; i < 26 ;i++)if (frq[i] != 0 )return 0; 
        return 1 ; 
    }
};