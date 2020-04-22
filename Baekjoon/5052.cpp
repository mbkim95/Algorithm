#include <iostream>
#include <cstring>
using namespace std;

struct Trie {
    bool end, has_child;
    Trie* child[10];

    Trie() {
        end = false;
        has_child = false;
        fill(child, child + 10, nullptr);
    }

    ~Trie() {
        for (int i = 0; i < 10; i++)
            if (child[i]) delete child[i];
    }

    void insert(const string& str, int idx) {
        char key = str[idx];
        if (key == '\0') end = true;
        else {
            int next = key - '0';
            if (!child[next]) child[next] = new Trie;
            has_child = true;
            child[next]->insert(str, idx+1);
        }
    }

    bool consistent() {
        if (end && has_child) return false;
        for (int i = 0; i < 10; i++)
            if (child[i] && !child[i]->consistent()) return false;
        return true;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Trie* root = new Trie;
        while (n--) {
            string num;
            cin >> num;
            root->insert(num, 0);
        }
        cout << (root->consistent() ? "YES\n" : "NO\n");
        delete root;
    }
}