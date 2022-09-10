fun main() {
    val s = readLine()!!

    var ans = ""
    for (i in 1..s.length) ans += "z"
    for (i in 0..s.length - 3) {
        for (j in i + 1..s.length - 2) {
            val a = s.substring(0, i + 1).reversed()
            val b = s.substring(i + 1, j + 1).reversed()
            val c = s.substring(j + 1, s.length).reversed()

            if (ans > a + b + c) ans = a + b + c
        }
    }
    println(ans)
}