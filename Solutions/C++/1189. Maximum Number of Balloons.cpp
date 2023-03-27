class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int freq[27] = {0};
        int i ;
        for(char c: text){
            freq[c-'a']++;
        }
        // Since "L" and "O" are repeated twice we need to normalize them to 1 
        freq[11]/=2; // Divide "L" by half
        freq[14]/=2; // Divide "O" by half 
        int minOccurence = min(freq[0],min(freq[1],min(freq[11], min(freq[13],freq[14]))));
        return minOccurence;
    }
};
