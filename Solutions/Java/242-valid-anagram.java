/*
 * Time complexity: O(n)
 * Space complexity: O(1), since input strings
 * consist of lowercase English letters only
 *
 */

class Solution {
    public boolean isAnagram(String s, String t) {
        HashMap<Character, Integer> charsCount = new HashMap<>();

        for(char letter : s.toCharArray()) {
            charsCount.put(letter, charsCount.getOrDefault(letter, 0) + 1);
        }

        for(char letter : t.toCharArray()) {
            if(!charsCount.containsKey(letter)) {
                return false;
            } else {
                int count = charsCount.get(letter);
                if(count == 0) {
                    return false;
                } else {
                    charsCount.put(letter, count-1);
                }
            }
        }

        for(Character letter : charsCount.keySet()) {
            if(charsCount.get(letter) != 0) {
                return false;
            }
        }

        return true;
    }
}