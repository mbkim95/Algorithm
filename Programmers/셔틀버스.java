import java.util.ArrayList;
import java.util.Collections;

class Solution {
    public int timeToInt(String time) {
        int h = Integer.parseInt(time.substring(0, 2));
        int m = Integer.parseInt(time.substring(3, 5));
        return h * 60 + m;
    }

    public String timeToString(int h, int m) {
        String hour = String.valueOf(h);
        String minute = String.valueOf(m);
        if (hour.length() == 1) hour = "0" + hour;
        if (minute.length() == 1) minute = "0" + minute;
        return hour + ":" + minute;
    }

    public String solution(int n, int t, int m, String[] timetable) {
        String answer = "";

        ArrayList<Integer> table = new ArrayList<>();
        for (String time : timetable)
            table.add(timeToInt(time));

        Collections.sort(table);

        int bus = 9 * 60;
        int idx = 0;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int count = 0;
            for (int j = idx; j < table.size(); j++) {
                if (table.get(j) <= bus) {
                    count++;
                    idx++;
                }
                if (count == m) break;
            }
            if (i == n - 1) {
                if (count < m) ans = bus;
                else ans = table.get(idx - 1) - 1;
                break;
            }
            bus += t;
        }
        answer = timeToString(ans / 60, ans % 60);
        return answer;
    }
}