fun main() {
    readln()
    val str = readln()
    var s = 0
    var b = 0
    str.forEach { if (it == 's') s++ else if (it == 'b') b++ }
    if(s == b) println("bigdata? security!")
    else if(s > b) println("security!")
    else println("bigdata?")
}