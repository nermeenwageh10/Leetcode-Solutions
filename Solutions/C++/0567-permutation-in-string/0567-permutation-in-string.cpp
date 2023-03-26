class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return 0;
        vector<int> frq(26, 0), frq2(26, 0);
        for (int i = 0; i < s1.size(); i++) frq[s1[i] - 'a']++;
        for (int i = 0; i < s1.size()-1; i++)frq2[s2[i] - 'a']++;
        for (int i = 0, j = s1.size()-1; j < s2.size(); j++, i++){
            frq2[s2[j] - 'a']++;
            bool ok = 1;
            for (int k = 0; ok && k < 26; k++)
                if (frq[k] != frq2[k])
                    ok = 0;
            if (ok) return 1;
            frq2[s2[i]-'a']--;
        }   
        return 0;
    }
};