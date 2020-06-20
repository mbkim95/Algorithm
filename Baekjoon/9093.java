import java.io.*;
import java.util.StringTokenizer;

class Main {
    public static void main(String[] args) throws IOException {
        int n;
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        n = Integer.parseInt(br.readLine());
        StringTokenizer tok;
        for (int i = 0; i < n; i++) {
            tok = new StringTokenizer(br.readLine());
            while (tok.hasMoreTokens()) {
                String word = tok.nextToken();
                for (int j = word.length() - 1; j >= 0; j--)
                    System.out.print(word.charAt(j));
                System.out.print(' ');
            }
            System.out.println();
        }
    }
}