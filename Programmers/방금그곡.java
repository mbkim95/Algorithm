class Solution {
    public int getMinutes(String time) {
        int h = Integer.parseInt(time.substring(0, 2));
        int m = Integer.parseInt(time.substring(3, 5));
        return h * 60 + m;
    }

    public String replaceAll(String str) {
        str = str.replaceAll("C#", "c");
        str = str.replaceAll("D#", "d");
        str = str.replaceAll("F#", "f");
        str = str.replaceAll("G#", "g");
        str = str.replaceAll("A#", "a");
        return str;
    }

    public String solution(String m, String[] musicinfos) {
        String answer = "(None)";
        m = replaceAll(m);

        int length = 0;
        for (String info : musicinfos) {
            int t1 = getMinutes(info.substring(0, 5));
            int t2 = getMinutes(info.substring(6, 11));
            int time = t2 - t1;
            info = info.substring(12);
            String music = info.substring(0, info.indexOf(","));
            String melody = info.substring(music.length() + 1);
            melody = replaceAll(melody);
            String s = melody;
            while (s.length() < time) {
                s += melody;
            }
            s = s.substring(0, time);
            System.out.println(s);
            if (s.contains(m) && length < time) {
                length = time;
                answer = music;
            }
        }
        return answer;
    }
}