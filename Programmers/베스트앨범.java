import java.util.*;

class Pair {
    int first, second;

    public Pair(int first, int second) {
        this.first = first;
        this.second = second;
    }
}

class Song {
    String genre;
    int count;

    public Song(String genre, int count) {
        this.genre = genre;
        this.count = count;
    }
}

class Solution {
    Comparator<Pair> comp = (o1, o2) -> {
        if (o1.first > o2.first) return -1;
        else if (o1.first == o2.first && o1.second < o2.second) return -1;
        return 1;
    };

    public int[] solution(String[] genres, int[] plays) {
        HashMap<String, Integer> genre = new HashMap<>();
        HashMap<String, ArrayList<Pair>> song = new HashMap<>();
        for (int i = 0; i < genres.length; i++) {
            genre.put(genres[i], genre.getOrDefault(genres[i], 0) + plays[i]);
            if (!song.containsKey(genres[i])) song.put(genres[i], new ArrayList<>());
            song.get(genres[i]).add(new Pair(plays[i], i));
        }
        ArrayList<Song> arr = new ArrayList<>();
        for (String it : genre.keySet()) arr.add(new Song(it, genre.get(it)));
        arr.sort((o1, o2) -> {
            if (o1.count > o2.count) return -1;
            return 1;
        });

        ArrayList<Integer> tmp = new ArrayList<>();
        for (Song s : arr) {
            String g = s.genre;
            song.get(g).sort(comp);
            if (song.get(g).size() < 2) {
                tmp.add(song.get(g).get(0).second);
                continue;
            }
            for (int i = 0; i < 2; i++)
                tmp.add(song.get(g).get(i).second);
        }
        int[] answer = new int[tmp.size()];
        for (int i = 0; i < tmp.size(); i++) answer[i] = tmp.get(i);
        return answer;
    }
}