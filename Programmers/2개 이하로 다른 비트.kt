class Solution {
    fun solution(numbers: LongArray): LongArray {
        val answer = numbers.toMutableList()
        for(i in answer.indices) {
            answer[i]++
            answer[i] += (answer[i].xor(numbers[i])).shr(2) 
        }
        return answer.toLongArray()
    }
}