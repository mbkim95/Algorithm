fun main()=print(when(readln().split(" ").indexOf(readln())+1){in 1..5->"A+";in 6..15->"A0";in 16..30->"B+";in 31..35->"B0";in 36..45->"C+";in 46..48->"C0";else->"F"})