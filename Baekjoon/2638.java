import java.io.*;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
    static int n, m, cnt = 0;
    static int[][] map;
    static int[][] visited;
    static StringTokenizer st;
    static BufferedReader br;
    static BufferedWriter bw;
    static int[] dx = {-1, 0, 1, 0};
    static int[] dy = {0, -1, 0, 1};

    public static void main(String[] args) {
        input();
        solve();
    }

    public static void solve() {
        int time = 0;
        while (cnt > 0) {
            checkOutline();
            removeCheese();
            time++;
        }
        try {
            bw.write(String.valueOf(time));
            bw.flush();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public static void removeCheese() {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (visited[i][j] > 1) {
                    map[i][j] = 0;
                    cnt--;
                }
            }
        }
    }

    public static void checkOutline() {
        for (int i = 0; i < n; i++) Arrays.fill(visited[i], 0);
        Queue<Point> q = new LinkedList<>();
        q.add(new Point(0, 0));
        visited[0][0] = 1;

        while (!q.isEmpty()) {
            Point cur = q.poll();

            for (int i = 0; i < 4; i++) {
                int nx = cur.x + dx[i];
                int ny = cur.y + dy[i];
                if (nx < 0 || nx > m - 1 || ny < 0 || ny > n - 1) continue;
                if (map[ny][nx] == 1) visited[ny][nx]++;
                if (visited[ny][nx] == 0 && map[ny][nx] == 0) {
                    q.add(new Point(nx, ny));
                    visited[ny][nx] = 1;
                }
            }
        }
    }

    public static void input() {
        try {
            br = new BufferedReader(new InputStreamReader(System.in));
            bw = new BufferedWriter(new OutputStreamWriter(System.out));
            st = new StringTokenizer(br.readLine(), " ");
            n = Integer.parseInt(st.nextToken());
            m = Integer.parseInt(st.nextToken());
            map = new int[n][m];
            visited = new int[n][m];
            for (int i = 0; i < n; i++) {
                st = new StringTokenizer(br.readLine(), " ");
                for (int j = 0; j < m; j++) {
                    map[i][j] = Integer.parseInt(st.nextToken());
                    if (map[i][j] == 1) cnt++;
                }
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}

class Point {
    int x;
    int y;

    public Point(int x, int y) {
        this.x = x;
        this.y = y;
    }
}
