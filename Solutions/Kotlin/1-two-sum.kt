/**Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.**/

/* * Runtime: 183 ms, faster than 98.29% of Kotlin online submissions for Two Sum.
   * Memory Usage: 37.6 MB, less than 54.96% of Kotlin online submissions for Two Sum.*/
class Solution {
    fun twoSum(nums: IntArray, target: Int): IntArray {
        
        // Create a mutable map to store the difference between the target and each element in nums
        val diffMap = mutableMapOf<Int, Int>()
        
        /*Loop through each element of nums with its index*/
        nums.forEachIndexed { index, int -> 
            /*Check if the current element's complement (target - int) exists in the map
            If it does, return an array containing its index and the current index*/
            diffMap[int]?.let { return intArrayOf(it, index) }
            
            // If it doesn't, add the current element's difference from target to the map
            diffMap[target - int] = index   
        }
        // If no solution is found, return an empty array
        return intArrayOf()
    }
}
