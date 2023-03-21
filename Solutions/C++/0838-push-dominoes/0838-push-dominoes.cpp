class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.size();
        for (int i = 0; i < n; i++){
            if (dominoes[i] != '.') continue;
            int j = i + 1;
            while (j < n && dominoes[j] == '.')
                j++;
            bool leftForce = 0, rightForce = 0;
            if (i-1>=0&&dominoes[i-1] == 'R') leftForce = 1;
            if (j<n&&dominoes[j]=='L') rightForce = 1;
            if (!leftForce && !rightForce){
                i = j;
                continue;
            }
            if (leftForce && rightForce){
                int half = (j - i) / 2;
                int k = 0;
                while (k < half){
                    dominoes[i+k] = 'R';
                    dominoes[j-1-k] = 'L';
                    k++;
                }
                i = j;
                continue;
            }
            while (i < j){
                dominoes[i] = (leftForce? 'R': 'L');
                i++;
            }
        }
        return dominoes;
    }
};