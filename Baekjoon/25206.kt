fun main() {
    var total = 0.0
    var credits = 0.0
    repeat(20) {
        val (_, credit, grade) = readln().split(" ")
        if (grade != "P") {
            val c = credit.toDouble()
            credits += c
            total += c * when (grade) {
                "A+" -> 4.5
                "A0" -> 4.0
                "B+" -> 3.5
                "B0" -> 3.0
                "C+" -> 2.5
                "C0" -> 2.0
                "D+" -> 1.5
                "D0" -> 1.0
                else -> 0.0
            }
        }
    }
    println("%.6f".format(total / credits))
}