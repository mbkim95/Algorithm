fun main() {
    val n = readLine()!!.toInt()
    val p = readLine()!!.split("*")
    for (j in 1..n) {
        val str = readLine()!!
        if (str.length < p[0].length + p[1].length || !str.startsWith(p[0]) || !str.substring(p[0].length).endsWith(p[1])) println("NE")
        else println("DA")
    }
}