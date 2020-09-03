#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool is_head(string str1, string str2) {
    for (int i = 0; i < str1.length(); i++)
        if (str1[i] != str2[i]) return false;
    return true;
}

bool solution(vector<string> phone_book) {
    sort(phone_book.begin(), phone_book.end());
    for (int i = 0; i < phone_book.size() - 1; i++) 
        for (int j = i + 1; j < phone_book.size(); j++) {
            if (phone_book[j].substr(0, phone_book[i].length()).find(phone_book[i]) != string::npos) return false;
        }
    return true;
}