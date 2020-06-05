import java.io.*;
import java.util.*;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        Set<String> hs = new HashSet<>();
        int n = Integer.parseInt(br.readLine());
        for (int i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            String name = st.nextToken();
            String status = st.nextToken();
            if (status.equals("enter")) hs.add(name);
            else hs.remove(name);
        }
        ArrayList<String> arr = new ArrayList<>(hs);
        Collections.sort(arr);
        for(int i=arr.size()-1; i>=0; i--)
            bw.write(arr.get(i) + "\n");
        bw.flush();
    }
}