import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int n = Integer.parseInt(br.readLine());

        StringTokenizer st;

        int[] num = new int[5];

        while (n-- > 0) {
            st = new StringTokenizer(br.readLine());
            for (int i = 0; i < 5; i++)
                num[i] = Integer.parseInt(st.nextToken());
            Arrays.sort(num);
            if (num[3] - num[1] > 3) bw.write("KIN\n");
            else bw.write(String.valueOf(num[1] + num[2] + num[3]) + "\n");
        }
        bw.flush();
    }
}
