#include <string>
#include <vector>
using namespace std;

string replace_all(string& str, const string& from, const string& to) {
    int pos = 0;
    while ((pos = str.find(from, pos)) != string::npos) {
        str.replace(pos, from.length(), to);
        pos += to.length();
    }
    return str;
}

void translate_sharp(string& melody) {
    replace_all(melody, "C#", "c");
    replace_all(melody, "D#", "d");
    replace_all(melody, "F#", "f");
    replace_all(melody, "G#", "g");
    replace_all(melody, "A#", "a");
}

pair<string, string> parse_music_info(string info) {
    // 음악 재생 시, 음악 끝 시
    int h1 = stoi(info.substr(0, 2)); int h2 = stoi(info.substr(6, 2));
    // 음악 재생 분, 음악 끝 분
    int m1 = stoi(info.substr(3, 2)); int m2 = stoi(info.substr(9, 2));
    info = info.substr(12);
    int idx = info.find(',');
    // 음악 제목
    string name = info.substr(0, idx);
    // 노래 멜로디
    string melody = info.substr(idx + 1);
    // #을 다른 문자로 처리
    translate_sharp(melody);
    // 재생 시간 분으로 계산
    int time = m2 - m1 + 60 * (h2 - h1);
    // 재생 시간이 노래의 전체 멜로디보다 짧으면 재생되는 부분만 추출
    if (time < melody.length()) melody = melody.substr(0, time);
    // 재생 시간이 노래 전체 멜로디보다 길면 재생 시간에 맞게 노래 변환
    else {
        while(true){
            if (time < melody.length()) break;
            melody += melody;
        }
        melody = melody.substr(0, time);
    }    
    return { name, melody};
}


string solution(string m, vector<string> musicinfos) {
    // 사용자가 들은 멜로디에 있는 #을 다른 문자로 변환
    translate_sharp(m);
    int len = 0;
    // 못찾은 경우를 위해 (None)으로 초기화
    string answer = "(None)";
    for (string s : musicinfos) {
        pair<string, string> t = parse_music_info(s);
        // 멜로디를 찾은 경우
        if (t.second.find(m) != string::npos) {
            // 가장 긴 길이의 멜로디가 정답
            if (len < t.second.length()) {
                len = t.second.length();
                answer = t.first;
            }
        }
    }
    return answer;
}