class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size())
            return false;
        //sort both strings
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        
        int i;
        for(i = 0; i < s.size(); i++){
            if(s[i] != t[i])
                return false;
        }
        return true;
    }
};
