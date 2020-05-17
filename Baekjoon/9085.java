import java.io.*;
import java.util.StringTokenizer;

class Main{
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st;

        int t = Integer.parseInt(br.readLine());
        while(t-- > 0){
            int n = Integer.parseInt(br.readLine());
            int sum = 0;
            st = new StringTokenizer(br.readLine());
            while(n-- > 0){
                sum += Integer.parseInt(st.nextToken());
            }
            bw.write(Integer.toString(sum) + "\n");
        }
        bw.flush();
    }
}