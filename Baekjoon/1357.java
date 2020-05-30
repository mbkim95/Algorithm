import java.io.*;
import java.util.StringTokenizer;

class Main{
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int a = Integer.parseInt(new StringBuilder(st.nextToken()).reverse().toString());
        int b = Integer.parseInt(new StringBuilder(st.nextToken()).reverse().toString());
        String answer = new StringBuilder(Integer.toString(a + b)).reverse().toString();
        StringBuilder sb = new StringBuilder();
        boolean flag = true;
        for(int i=0; i<answer.length(); i++){
            char c = answer.charAt(i);
            if(c != '0') {
                if(flag) flag =false;
                sb.append(c);
            }else{
                if(!flag) sb.append(c);
            }
        }
        bw.write(sb.toString());
        bw.flush();
    }
}