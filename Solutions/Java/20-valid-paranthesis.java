import java.util.*;

class Solution {
    
    public static boolean isValid(String s) {
        boolean isValid = true;
        s = s.replaceAll("[^\\[\\]\\(\\)\\{\\}]", "");
        char[] schar = s.toCharArray();
        ArrayList<Character> now = new ArrayList<>();
        for (int i = 0; i < schar.length; i++) {
            if (schar[i] == '(' || schar[i] == '{' || schar[i] == '[') {
                now.add(schar[i]);
            } else if (schar[i] == ')' || schar[i] == '}' || schar[i] == ']') {
                if(now.size() == 0){
                   isValid = false;
                    return isValid;     
                }else if (now.size() > 0 && (((schar[i] == ')') && (now.get(now.size() - 1) != '('))
                        || ((schar[i] == '}') && (now.get(now.size() - 1) != '{'))
                        || ((schar[i] == ']') && (now.get(now.size() - 1) != '[')))){
                    isValid = false;
                    return isValid;
                } else if(now.size() > 0){
                    now.remove(now.size() - 1);
                }
            }
        }
        if (now.size() == 0) {
            isValid = true;
        } else {
            isValid = false;
        }
        return isValid;
    }
}
