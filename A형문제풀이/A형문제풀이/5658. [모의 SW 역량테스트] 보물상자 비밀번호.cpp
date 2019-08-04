#include <iostream>
#include <set>
#include <algorithm>
#include <string>

using namespace std;

int main() {
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; ++tc) {
		int n, k;
		cin >> n >> k;
		string s;
		cin >> s;
		set<int, greater<int>> vec;
		int multi = n / 4;
		for (int ro = 0; ro < multi; ++ro) {
			if (ro != 0) {
				s = s[s.size() - 1] + s.substr(0, s.size() - 1);
			}
			for (int i = 0; i < 4; ++i) {
				string temp = s.substr(multi * i, multi);
				int item = stoi(temp, nullptr, 16);
				vec.insert(item);
			}
		}

		set<int> ::iterator iter;
		int cnt = 0;
		for (iter = vec.begin(); iter != vec.end(); ++iter) {
			++cnt;
			if (cnt == k) {
				cout << "#" << tc << ' ' << *iter << '\n';
				break;
			}
		}

	}

}