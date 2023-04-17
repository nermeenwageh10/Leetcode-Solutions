/** We need to see if String "s" has the same letters as String "t" **/

class Solution {
    fun isAnagram(s: String, t: String): Boolean {
      /*If they don't have the same length then it means one of them has more letters = false*/
        if (s.length != t.length) return false

      /*We create a map to put our char/letters and the value is an int to track how many "a" for example we have*/
        val map = mutableMapOf<Char, Int>()

        /*We iterate through the first string and each char/letter we increment the int/value */
        s.forEach {
            map[it] = map.getOrDefault(it, 0) + 1
        }

        /*We iterate through the second string and each char/letter we Increment the int/value */
        t.forEach {
            val i = map.getOrDefault(it, 0) - 1
            map[it] = i

          /*Here we check if there's a key/character that holds a value of -1 which it means that they not equal*/
            if (i == -1) return false
        }

        /*if they are equal that means all the values are 0, because we increment and then decrement the same amount which results in the value being 0*/
        return true
    }
}
