data class User(val name: String, val day: Int, val month: Int, val year: Int)

fun main() {
    val users = mutableListOf<User>()
    repeat(readLine()!!.toInt()) {
        val u = readLine()!!.split(" ")
        users.add(User(u[0], u[1].toInt(), u[2].toInt(), u[3].toInt()))
    }
    users.sortWith { p0, p1 ->
        if (p0.year < p1.year) 1
        else if (p0.year == p1.year && p0.month < p1.month) 1
        else if (p0.year == p1.year && p0.month == p1.month && p0.day < p1.day) 1
        else -1
    }
    println("${users[0].name}\n${users[users.size - 1].name}")
}
