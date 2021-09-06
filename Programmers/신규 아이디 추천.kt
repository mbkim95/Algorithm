class Solution {
    fun solution(new_id: String): String {
        var newId =
            new_id.toLowerCase().filter { it in 'a'..'z' || it in '0'..'9' || it == '-' || it == '_' || it == '.' }
        while (newId.contains("..")) {
            newId = newId.replace("..", ".")
        }
        newId = if (newId.isNotEmpty() && newId.toCharArray()[0] == '.') newId.substring(1) else newId
        newId = if (newId.isNotEmpty() && newId.toCharArray()[newId.length - 1] == '.')
            newId.substring(0, newId.length - 1) else newId
        if (newId.isEmpty()) newId = "a"
        if (newId.length > 15) newId = newId.substring(0, 15)
        newId = if (newId.toCharArray()[newId.length - 1] == '.') newId.substring(0, newId.length - 1) else newId
        val tmp = newId.toCharArray()[newId.length - 1]
        for (i in 0 until 3 - newId.length) newId = "$newId$tmp"
        return newId
    }
}