
/**When we change the array to "Set". The new Set will implicitly remove duplicate elements.
We check the size of the Array and the size of the Set, if the size of the array bigger then it means it has duplicates.**/

class Solution {
    fun containsDuplicate(nums: IntArray) = nums.size > nums.toSet().size
}
