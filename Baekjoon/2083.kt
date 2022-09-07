fun main() {
    while (true) {
        val s = readLine()!!
        if (s == "# 0 0") break

        val (name, age, weight) = s.split(" ")

        if(age.toInt() > 17 || weight.toInt() >= 80) println("$name Senior")
        else println("$name Junior")
    }
}