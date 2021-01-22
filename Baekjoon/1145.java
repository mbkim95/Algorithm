import java.io.*;
import java.util.StringTokenizer;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int[] num = new int[5];
        int minNum = Integer.MAX_VALUE;
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < 5; i++) {
            num[i] = Integer.parseInt(st.nextToken());
            minNum = Integer.min(minNum, num[i]);
        }

        for (int i = minNum; i < Integer.MAX_VALUE; i++) {
            boolean find = false;
            int cnt = 0;
            for (int j = 0; j < 5; j++) {
                if (i % num[j] == 0) cnt++;
                if (cnt == 3) {
                    find = true;
                    break;
                }
            }
            if (find) {
                bw.write(String.valueOf(i));
                bw.flush();
                break;
            }
        }
    }
}
