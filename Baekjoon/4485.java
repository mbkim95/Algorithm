 import java.io.*;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

class Link {
    int x, y, dir;

    public Link(int x, int y, int dir) {
        this.x = x;
        this.y = y;
        this.dir = dir;
    }
}

public class Main {
    static int[][] map;
    static int[][][] chk;
    static final int[] dx = {-1, 0, 1, 0}, dy = {0, -1, 0, 1};

    public static int bfs(int size) {
        Queue<Link> q = new LinkedList<>();
        for (int i = 0; i < 4; i++) {
            q.add(new Link(0, 0, i));
            chk[0][0][i] = map[0][0];
        }

        while (!q.isEmpty()) {
            Link cur = q.poll();
            int x = cur.x, y = cur.y, dir = cur.dir;

            for (int i = 0; i < 4; i++) {
                int nx = cur.x + dx[i];
                int ny = cur.y + dy[i];

                if (nx < 0 || nx >= size || ny < 0 || ny >= size) continue;

                if (chk[y][x][dir] + map[ny][nx] < chk[ny][nx][i]) {
                    chk[ny][nx][i] = chk[y][x][dir] + map[ny][nx];
                    q.add(new Link(nx, ny, i));
                }
            }
        }
        int ret = Integer.MAX_VALUE;
        for (int i = 0; i < 4; i++) ret = Integer.min(ret, chk[size - 1][size - 1][i]);
        return ret;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st;
        int t = 1;
        while (true) {
            int size = Integer.parseInt(br.readLine());
            if (size == 0) break;

            map = new int[size][size];
            chk = new int[size][size][4];
            for (int i = 0; i < size; i++)
                for (int j = 0; j < size; j++)
                    for (int k = 0; k < 4; k++)
                        chk[i][j][k] = Integer.MAX_VALUE;

            for (int i = 0; i < size; i++) {
                st = new StringTokenizer(br.readLine(), " ");
                for (int j = 0; j < size; j++)
                    map[i][j] = Integer.parseInt(st.nextToken());
            }
            int answer = bfs(size);
            bw.write("Problem " + t++ + ": " + answer + "\n");
            bw.flush();
        }
    }
}
