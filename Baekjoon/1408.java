import java.io.*;

public class Main {
    public static int convertTimeStringToInt(String time) {
        String hour = time.substring(0, 2);
        String minute = time.substring(3, 5);
        String second = time.substring(6, 8);
        return Integer.parseInt(hour) * 3600 + Integer.parseInt(minute) * 60 + Integer.parseInt(second);
    }

    public static String convertTimeIntToString(int time) {
        int h = time / 3600;
        time -= (h * 3600);
        int m = time / 60;
        time -= (m * 60);
        int s = time;
        String hour = String.valueOf(h);
        String minute = String.valueOf(m);
        String second = String.valueOf(s);
        if (hour.length() == 1) hour = "0" + hour;
        if (minute.length() == 1) minute = "0" + minute;
        if (second.length() == 1) second = "0" + second;
        return hour + ":" + minute + ":" + second;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String now = br.readLine();
        String mission = br.readLine();

        int nowTime = convertTimeStringToInt(now);
        int missionTime = convertTimeStringToInt(mission);
        if (nowTime > missionTime) nowTime -= convertTimeStringToInt("24:00:00");
        String ans = convertTimeIntToString(missionTime - nowTime);
        bw.write(ans);
        bw.flush();
    }
}
