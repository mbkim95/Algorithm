fun main() {
    while (true) {
        val s = readLine() ?: break
        println("${s.count { it in 'a'..'z' }} ${s.count { it in 'A'..'Z' }} ${s.count { it in '0'..'9' }} ${s.count { it == ' ' }}")
    }
}