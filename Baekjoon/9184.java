import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

class Main {
    static int a, b, c;
    static int[][][] dp = new int[101][101][101];

    public static int w(int a, int b, int c) {
        if (dp[a + 50][b + 50][c + 50] != -1) return dp[a + 50][b + 50][c + 50];

        if (a <= 0 || b <= 0 || c <= 0) dp[a + 50][b + 50][c + 50] = 1;
        else if (a > 20 || b > 20 || c > 20) dp[a + 50][b + 50][c + 50] = w(20, 20, 20);
        else if (a < b && b < c) dp[a + 50][b + 50][c + 50] = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
        else
            dp[a + 50][b + 50][c + 50] = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
        return dp[a + 50][b + 50][c + 50];
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st;

        for (int i = 0; i <= 100; i++)
            for (int j = 0; j <= 100; j++)
                for (int k = 0; k <= 100; k++)
                    dp[i][j][k] = -1;

        while (true) {
            st = new StringTokenizer(br.readLine());
            a = Integer.parseInt(st.nextToken());
            b = Integer.parseInt(st.nextToken());
            c = Integer.parseInt(st.nextToken());
            if (a == -1 && b == -1 && c == -1) break;
            bw.write("w(" + a + ", " + b + ", " + c + ") = " + w(a, b, c) + "\n");
        }
        bw.flush();
    }
}
