#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

int n; //
int map[12][12]; //
vector<pair<int, int>> stair;
vector<pair<int, int>> people;
vector<int> v; //

// 계단 0
int start0[12]; //
int arrive0[12]; //
int size0; // 

// 계단 1
int start1[12]; //
int arrive1[12]; //
int size1; //

int result = 987654321; //


// 모두 도착하는 시간 계산
int solve() {
	for (int i = 0; i < people.size(); ++i) {
		int a = people[i].first, b = people[i].second, s = v[i];
		int c = stair[s].first, d = stair[s].second;

		if (s == 0) {
			start0[size0++] = abs(a - c) + abs(b - d) + 1;
		}
		else if (s == 1) {
			start1[size1++] = abs(a - c) + abs(b - d) + 1;
		}
	}
	sort(start0, start0 + size0);
	sort(start1, start1 + size1);

	for (int i = 0; i < size0; ++i) {
		arrive0[i] = start0[i] + map[stair[0].first][stair[0].second];
	}
	for (int i = 0; i < size1; ++i) {
		arrive1[i] = start1[i] + map[stair[1].first][stair[1].second];
	}

	if (size0 > 3) {
		for (int i = 3; i < size0; ++i) {
			if (start0[i] < arrive0[i - 3]) {
				arrive0[i] = arrive0[i - 3] + map[stair[0].first][stair[0].second];

			}

		}
	}
	if (size1 > 3) {
		for (int i = 3; i < size1; ++i) {
			if (start1[i] < arrive1[i - 3]) {
				arrive1[i] = arrive1[i - 3] + map[stair[1].first][stair[1].second];
			}
		}
	}

	int ans0 = 0;

	ans0 = arrive0[size0 - 1];
	int ans1 = 0;
	ans1 = arrive1[size1 - 1];

	int ans = max(ans0, ans1);
	return ans;
}


void dfs(int depth) {
	if (depth == people.size()) {
		size0 = 0;
		size1 = 0;
		result = min(solve(), result);


		return;
	}
	for (int i = 0; i < 2; ++i) {
		v.push_back(i);
		dfs(depth + 1);
		v.pop_back();
	}
}

int main() {
	int tc;
	cin >> tc;
	for (int t = 1; t <= tc; ++t) {
		stair.clear();
		people.clear();
		result = 987654321;
		cin >> n;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				cin >> map[i][j];
				if (map[i][j] > 1) stair.push_back({ i,j });
				else if (map[i][j] == 1) people.push_back({ i,j });
			}
		}
		dfs(0);
		cout << '#' << t << ' ' << result << '\n';

	}



}