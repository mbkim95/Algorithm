class Solution {
    public int buildStation(int left, int right, int w) {
        int length = right - left + 1;
        int range = 2 * w + 1;
        int count = 0;
        while (count * range < length) count++;
        return count;
    }

    public int solution(int n, int[] stations, int w) {
        int answer = 0;
        if (stations[0] - w > 1) answer += buildStation(1, stations[0] - w - 1, w);
        for (int i = 1; i < stations.length; i++)
            answer += buildStation(stations[i - 1] + w + 1, stations[i] - w - 1, w);
        int last = stations.length - 1;
        if (stations[last] + w < n) answer += buildStation(stations[last] + w + 1, n, w);
        return answer;
    }
}