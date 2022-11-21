fun main() {
    while (true) {
        val t = readLine()!!
        if (t == "0 0 0") break

        val l = t.split(" ").map { it.toInt() }.sorted()
        if (l[0] + l[1] <= l[2]) println("Invalid")
        else if (l[0] == l[1] && l[1] == l[2]) println("Equilateral")
        else if (l[0] == l[1] || l[0] == l[2] || l[1] == l[2]) println("Isosceles")
        else println("Scalene")
    }
}