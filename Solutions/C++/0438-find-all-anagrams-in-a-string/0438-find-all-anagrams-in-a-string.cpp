class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if (p.size() > s.size()) return {};
        vector<int> frq(26, 0), frq2(26, 0), indices;
        for (int i = 0; i < p.size(); i++) frq[p[i]-'a']++;
        for (int i = 0; i < p.size()-1; i++) frq2[s[i] - 'a']++;
        int match = 0;
        for (int i = 0; i < 26; i++){
            if (frq[i] == frq2[i])
                match++;
        }
        for (int i =0, j = p.size()-1; j < s.size(); i++, j++){
            frq2[s[j]-'a']++;
            if (frq2[s[j] - 'a'] == frq[s[j] - 'a'])
                match++;
            else if (frq2[s[j] - 'a'] - 1 == frq[s[j] - 'a'])
                match--;
            if (match == 26) 
                indices.push_back(i);
            frq2[s[i]-'a']--;
            if (frq2[s[i] - 'a'] == frq[s[i] - 'a'])
                match++;
            if (frq2[s[i] - 'a'] + 1 == frq[s[i] - 'a'])
                match--;
        }
        return indices;
    }
};