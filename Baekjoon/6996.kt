fun main() {
    repeat(readLine()!!.toInt()) {
        val (a, b) = readLine()!!.split(" ")
        println("$a & $b are${if (a.toCharArray().sorted() == b.toCharArray().sorted()) " " else " NOT "}anagrams.")
    }
}