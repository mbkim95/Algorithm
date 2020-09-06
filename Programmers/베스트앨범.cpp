#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

struct Song {
    string genre;
    int count;
};

bool cmp(Song& a, Song& b) {
    return a.count < b.count;
}

bool cmp2(pair<int, int>& a, pair<int, int>& b) {
    if (a.first > b.first) return true;
    else if (a.first == b.first && a.second < b.second) return true;
    return false;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    map<string, int> genre;
    map<string, vector<pair<int, int>>> song;
    for (int i = 0; i < genres.size(); i++) {
        genre[genres[i]] += plays[i];
        song[genres[i]].push_back({ plays[i], i });
    }
    vector<Song> arr;
    for (auto it : genre) arr.push_back({ it.first, it.second });
    sort(arr.begin(), arr.end(), cmp);
    for (int i = 0; i < arr.size(); i++) {
        string g = arr[i].genre;
        sort(song[g].begin(), song[g].end(), cmp2);
        if (song[g].size() < 2) {
            answer.push_back(song[g][0].second);
            continue;
        }
        for(int j=0; j<2; j++) answer.push_back(song[g][j].second);
    }
    return answer;
}