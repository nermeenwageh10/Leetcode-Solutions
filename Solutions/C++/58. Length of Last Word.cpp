class Solution {
public:
    int lengthOfLastWord(string s) {
        int i = s.size() - 1;
        int LastWordLength  = 0;
        for(i = i; i > -1; i--){
            if(s[i] == ' '){
                if(LastWordLength == 0)
                    continue;
                else
                    break;
            }
            else
                LastWordLength++;
        }
        return LastWordLength;
    }
};
