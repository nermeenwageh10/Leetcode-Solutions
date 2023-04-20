class Solution {
    public boolean isPalindrome(String s) {
        boolean isPalindrome = true;
        int i = 0;
        s = (s.replaceAll("[^a-zA-Z0-9]", "")).toLowerCase();
        int j = s.length()-1;
        while((isPalindrome) && (i<j)){
            if(!(s.charAt(i) == s.charAt(j))){
                isPalindrome = false;
            }
            i++;
            j--;
        }
        return isPalindrome;
        
    }
}
