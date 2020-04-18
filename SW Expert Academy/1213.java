import java.io.*;

class Solution{
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int t= 10;
        while(t-->0){
            int tmp = Integer.parseInt(br.readLine());
            String tok = br.readLine();
            String str = br.readLine();
            int idx = 0;
            int ans = 0;
            while(true){
                idx = str.indexOf(tok);
                if(idx == -1) break;
                str = str.substring(idx + tok.length(), str.length());
                ans++;
            }
            bw.write("#" + String.valueOf(tmp) + " " + String.valueOf(ans) + "\n");
            bw.flush();
        }
    }
}