#include <string>
#include <vector>

using namespace std;

struct Trie {
    int child_cnt;
    bool end;
    Trie* child[26];

    Trie() {
        end = false;
        child_cnt = 0;
        fill(child, child + 26, nullptr);
    }

    ~Trie() {
        for (int i = 0; i < 26; i++)
            if (child[i]) delete child[i];
    }

    void insert(const string& word, int idx) {
        char key = word[idx];
        if (key == '\0') end = true;
        else {
            int next = key - 'a';
            if (!child[next]) child[next] = new Trie;
            child[next]->child_cnt++;
            child[next]->insert(word, idx + 1);
        }
    }

    int find(const string& word, int idx) {
        int key = word[idx] - 'a';
        // 단어를 끝까지 탐색한 경우는 단어 길이를 그대로 리턴
        if (end && word[idx] == '\0') return word.length();
        // child의 개수가 1이라는 것은 자동 완성이 가능하다는 것이므로 입력한 길이만큼 리턴해준다
        if (child[key]->child_cnt == 1) return idx + 1;
        // 자동완성이 불가능한경우 다음 글자로 넘어간다
        return child[key]->find(word, idx + 1);
    }
};

int solution(vector<string> words) {
    int answer = 0;
    Trie* root = new Trie;
    for (string str : words)
        root->insert(str, 0);

    for (string str : words)
        answer += root->find(str, 0);
    return answer;
}