fun main() {
    repeat(readLine()!!.toInt()) {
        val alpha = MutableList(26) { 0 }
        readLine()!!.filter { it in 'a'..'z' || it in 'A'..'Z' }.forEach { alpha[(it.lowercaseChar() - 'a')]++ }
        var isPangram = true
        var missing = ""
        for (i in 0 until 26) {
            if (alpha[i] == 0) {
                missing += ('a' + i)
                isPangram = false
            }
        }
        println(if (isPangram) "pangram" else "missing $missing")
    }
}