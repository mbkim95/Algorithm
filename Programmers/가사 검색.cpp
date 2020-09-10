#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct Trie {
    Trie* child[26];
    int count;
    bool is_end;

    Trie() : is_end(false), count(1) {
        fill(child, child + 26, nullptr);
    }
    ~Trie() {
        for (int i = 0; i < 26; i++) {
            if (child[i]) delete child[i];
        }
    }
    void insert(const char* key) {
        if (*key == '\0') is_end = true;
        else {
            int idx = *key - 'a';
            if (!child[idx]) child[idx] = new Trie();
            else child[idx]->count++;
            child[idx]->insert(key + 1);
        }
    }

    int find(const char* key) {
        int idx = *key - 'a';
        if (*key == '?') {
            int tmp = 0;
            for (int k = 0; k < 26; k++)
                if (child[k] != NULL) tmp += child[k]->count;           
            return tmp;
        }
        if (!child[idx]) return 0;
        if (*(key + 1) == '?') return child[idx]->count;
        return child[idx]->find(key + 1);
    }
};

Trie* root[10001];
Trie* root2[10001];

vector<int> solution(vector<string> words, vector<string> queries) {
    vector<int> answer(queries.size() , 0);

    for (string& word : words) {
        int size = word.size();
        if (!root[size]) root[size] = new Trie();
        root[size]->insert(word.c_str());

        reverse(word.begin(), word.end());
        if (!root2[size]) root2[size] = new Trie();
        root2[size]->insert(word.c_str());
    }

    int idx = 0;
    for (string& query : queries) {
        int size = query.size();

        if (query[size - 1] == '?') {
            if (root[size])
                answer[idx] = root[size]->find(query.c_str());
        }
        else {
            reverse(query.begin(), query.end());
            if (root2[size])
                answer[idx] = root2[size]->find(query.c_str());
        }
        idx++;
    }
    return answer;
}