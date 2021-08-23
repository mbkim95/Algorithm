fun dfs(idx: Int, str: String, alpha: List<String>, l: Int, ja: Int, mo: Int) {
    if (str.length == l) {
        if (ja >= 2 && mo >= 1) println(str)
        return
    }

    for (i in idx + 1 until alpha.size) {
        if (alpha[i] in listOf("a", "e", "i", "o", "u")) dfs(i, str + alpha[i], alpha, l, ja, mo + 1)
        else dfs(i, str + alpha[i], alpha, l, ja + 1, mo)
    }
}

fun main() {
    val (l, c) = readLine()!!.split(" ").map { it.toInt() }
    val alpha = readLine()!!.split(" ").sorted()
    dfs(-1, "", alpha, l, 0, 0)
}