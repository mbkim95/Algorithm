import java.io.*;
import java.util.ArrayList;
import java.util.StringTokenizer;

class Main {
    static int n;
    static ArrayList<Integer> num = new ArrayList<>();

    public static int gcd(int a, int b) {
        if (a % b == 0) return b;
        return gcd(b, a % b);
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st;

        n = Integer.parseInt(br.readLine());
        st = new StringTokenizer(br.readLine());

        for (int i = 0; i < n; i++) num.add(Integer.parseInt(st.nextToken()));

        int g = gcd(num.get(0), num.get(1));
        if (n == 3) g = gcd(g, num.get(2));

        for (int i = 1; i <= g; i++)
            if (g % i == 0)
                bw.write(i + "\n");
        bw.flush();
    }
}
