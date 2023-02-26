fun main() {
    readln()
    val c = readln().filter { it != 'A' && it != 'J' && it != 'V' }
    if(c.isEmpty()) println("nojava") else println(c)
}