fun main() {
    var i = 0
    while (true) {
        i++
        val a = readln()
        val b = readln()

        if (a == "END" && b == "END") break

        print("Case $i: ")
        if (a.length != b.length) println("different")
        else if (a.toList().sorted() == b.toList().sorted()) println("same")
        else println("different")
    }
}