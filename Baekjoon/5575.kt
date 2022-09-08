fun main()=repeat(3){
    val a=readLine()!!.split(" ").map {it.toInt()}
    var s=a[5]-a[2]
    var m=a[4]-a[1]
    var h=a[3]-a[0]
    if(s<0){s+=60;m--}
    if(m<0){m+=60;h--}
    println("$h $m $s")
}