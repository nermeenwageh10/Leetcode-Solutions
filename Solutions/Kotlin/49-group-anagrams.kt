/*
 * Runtime: 298 ms, faster than 94.13% of Kotlin online submissions for Group Anagrams.
 * Memory Usage: 43.7 MB, less than 39.88% of Kotlin online submissions for Group Anagrams.
*/

class Solution {
    fun groupAnagrams(strs: Array<String>): List<List<String>> {
        
        var i = 0
        var map = hashMapOf<String,ArrayList<String>>()
        var result = arrayListOf<List<String>>()
        
        // 1-This while loop goes through each string in the strs array
        while(i<strs.size){
            var actual =  strs[i]
            
            // 2-sorts its characters alphabetically
            var arr = actual.toCharArray()
            arr.sort()
            
            // 3-stores it as a new string called sortedText.
            var sortedText = String(arr)
            
            /* 4- checks if this sortedText key is already present in the map HashMap.
            If it is, it retrieves the ArrayList of strings that corresponds to that key,
            adds the current actual string to the list, and puts the list back into the map.*/
            var actualList =  map.getOrDefault(sortedText, arrayListOf<String>())
            
            /* 5- If the key is not present in the map, 
            it creates a new empty ArrayList of strings and puts it in the map with the current sortedText key.*/
            actualList.add(actual)
            map.put(sortedText,actualList)
            //println(arr)
            i++
        }
        
        
        /*6-This forEach loop goes through each key-value pair in the map HashMap,
        and adds the corresponding ArrayList of strings to the result ArrayList of Lists of Strings.*/
        map.forEach{key, item->
        
            result.add(item)
        }
        
        return result
    }
}
