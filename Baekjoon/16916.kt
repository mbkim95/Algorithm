lateinit var pi: Array<Int>

fun getPi(s: String) {
    val n = s.length
    var j = 0
    pi = Array(n) { 0 }

    for (i in 1 until n) {
        while ((j > 0) && s[i] != s[j]) {
            j = pi[j - 1]
        }
        if (s[i] == s[j]) {
            j++
            pi[i] = j
        }
    }
}

fun kmp(s: String, p: String): Boolean {
    var n = s.length
    var m = p.length
    var j = 0

    for (i in 0 until n) {
        while ((j > 0) && (s[i] != p[j])) {
            j = pi[j - 1]
        }
        if (s[i] == p[j]) {
            if (j == m - 1) return true
            else j++
        }
    }
    return false
}

fun main() {
    val s = readLine()!!
    val p = readLine()!!
    getPi(s)
    println(if (kmp(s, p)) 1 else 0)
}