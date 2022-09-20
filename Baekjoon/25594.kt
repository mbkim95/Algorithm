import java.io.*

val hg = mapOf(
    'a' to "aespa",
    'b' to "baekjoon",
    'c' to "cau",
    'd' to "debug",
    'e' to "edge",
    'f' to "firefox",
    'g' to "golang",
    'h' to "haegang",
    'i' to "iu",
    'j' to "java",
    'k' to "kotlin",
    'l' to "lol",
    'm' to "mips",
    'n' to "null",
    'o' to "os",
    'p' to "python",
    'q' to "query",
    'r' to "roka",
    's' to "solvedac",
    't' to "tod",
    'u' to "unix",
    'v' to "virus",
    'w' to "whale",
    'x' to "xcode",
    'y' to "yahoo",
    'z' to "zebra",
)

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.out))
    var idx = 0
    val str = br.readLine()

    var isAnswer = true
    val ans = StringBuilder()
    while (idx < str.length) {
        if (idx + hg[str[idx]]!!.length > str.length || str.substring(idx, idx + hg[str[idx]]!!.length) != hg[str[idx]]!!) {
            isAnswer = false
            break
        }
        ans.append(str[idx])
        idx += hg[str[idx]]!!.length
    }
    bw.write(if (isAnswer) "It's HG!\n$ans" else "ERROR!")
    bw.flush()
}