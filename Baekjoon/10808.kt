val alpha = IntArray(26)

fun main() {
    readLine()!!.forEach { alpha[it - 'a']++ }
    alpha.forEach { print("$it ") }
}
