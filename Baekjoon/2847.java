import java.io.*;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int n = Integer.parseInt(br.readLine());
        int[] num = new int[101];

        for (int i = 0; i < n; i++)
            num[i] = Integer.parseInt(br.readLine());
        int ans = 0;
        for (int i = n - 1; i > 0; i--) {
            while (num[i - 1] >= num[i]) {
                num[i - 1]--;
                ans++;
            }
        }
        bw.write(String.valueOf(ans));
        bw.flush();
    }
}
