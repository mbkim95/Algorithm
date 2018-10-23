#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool match(const string& w, const string& s){
	int pos = 0;

	while(pos < s.size() && pos < w.size() && (w[pos] == '?' || w[pos] == s[pos]))
		pos++;
	
	if(pos == w.size())
		return pos == s.size();
	
	if(w[pos] == '*')
		for(int skip=0; pos+skip<=s.size(); skip++)
			if(match(w.substr(pos+1), s.substr(pos+skip)))
				return true;
	
	return false;
}

int main(){
	int c, n;
	string w, s;
	vector<string> v;
	cin >> c;
	while(c--){
		cin >> w;
		cin >> n;

		for(int i=0; i<n; i++){
			cin >> s;
			if(match(w, s))
				v.push_back(s);
		}		
		sort(v.begin(), v.end());
		for(int i=0; i<v.size(); i++){
			cout << v[i] << endl;
		}
		v.clear();
	}
}