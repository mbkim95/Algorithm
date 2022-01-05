/**
 * Example:
 * var li = ListNode(5)
 * var v = li.`val`
 * Definition for singly-linked list.
 * class ListNode(var `val`: Int) {
 *     var next: ListNode? = null
 * }
 */
class Solution {
    fun addTwoNumbers(l1: ListNode?, l2: ListNode?): ListNode? {
        var n1 = l1
        var n2 = l2
        var ans: ListNode? = null
        var n: ListNode? = null
        var up = 0
        while (n1 != null && n2 != null) {
            val sum = n1.`val` + n2.`val` + up

            if (n == null) {
                n = ListNode(if (sum >= 10) sum - 10 else sum)
                ans = n
            } else {
                n.next = ListNode(if (sum >= 10) sum - 10 else sum)
                n = n.next
            }
            up = if (sum >= 10) 1 else 0

            n1 = n1.next
            n2 = n2.next
        }

        while (n1 != null) {
            val sum = n1.`val` + up
            n?.next = ListNode(if (sum >= 10) sum - 10 else sum)
            n = n?.next
            up = if (sum >= 10) 1 else 0
            n1 = n1.next
        }

        while (n2 != null) {
            val sum = n2.`val` + up
            n?.next = ListNode(if (sum >= 10) sum - 10 else sum)
            n = n?.next
            up = if (sum >= 10) 1 else 0
            n2 = n2.next
        }

        if (up == 1) n?.next = ListNode(1)

        return ans
    }
}