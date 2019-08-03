#include <iostream>
#include <cmath>
using namespace std;

int k; //
int map[4][8]; // 
pair<int, int> info[4]; //
int infoSize;//

void Clock(int *arr, int dir) {
	if (dir == 1) {
		int temp = arr[7];
		for (int i = 7; i >= 1; --i) {
			arr[i] = arr[i - 1];
		}
		arr[0] = temp;
	}
	else {
		int temp = arr[0];
		for (int i = 0; i <= 6; ++i) {
			arr[i] = arr[i + 1];
		}
		arr[7] = temp;
	}
}

void print() {
	cout << endl;
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 8; ++j) {
			cout << map[i][j] << ' ';
		}
		cout << endl;
	}
}

void solve(int num, int dir) {
	num--;
	if (num == 0) {
		info[infoSize++] = { 0, dir };
		if (map[0][2] != map[1][6]) {
			info[infoSize++] = { 1, -dir };
			if (map[1][2] != map[2][6]) {
				info[infoSize++] = { 2, dir };
				if (map[2][2] != map[3][6]) {
					info[infoSize++] = { 3, -dir };
				}
			}
		} 
	}
	else if (num == 1) {
		info[infoSize++] = { 1, dir };
		if (map[0][2] != map[1][6]) {
			info[infoSize++] = { 0, -dir };
		}
		if (map[1][2] != map[2][6]) {
			info[infoSize++] = { 2, -dir };
			if (map[2][2] != map[3][6]) {
				info[infoSize++] = { 3, dir };
			}
		}
	}
	else if (num == 2) {
		info[infoSize++] = { 2, dir };
		if (map[1][2] != map[2][6]) {
			info[infoSize++] = { 1, -dir };
			if (map[0][2] != map[1][6]) {
				info[infoSize++] = { 0, dir };
			}
		}
		if (map[2][2] != map[3][6]) {
			info[infoSize++] = { 3, -dir };
		}
	}
	else if (num == 3) {
		info[infoSize++] = { 3, dir };
		if (map[2][2] != map[3][6]) {
			info[infoSize++] = { 2, -dir };
			if (map[1][2] != map[2][6]) {
				info[infoSize++] = { 1, dir };
				if (map[0][2] != map[1][6]) {
					info[infoSize++] = { 0, -dir };
				}
			}
		}
	}

}

void simul() {
	for (int i = 0; i < infoSize; ++i) {
		int a = info[i].first, b = info[i].second;
		Clock(map[a], b);
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int tc;
	cin >> tc;
	for (int t = 1; t <= tc; ++t) {
		cin >> k;
		for (int i = 0; i < 4; ++i) for (int j = 0; j < 8; ++j) 
				cin >> map[i][j];
			
		int num, dir;
		for (int i = 0; i < k; ++i) {
			cin >> num >> dir; // 1 1 3 -1	
			solve(num, dir); //info 배열에 담기
			simul(); // info배열대로 회전
			infoSize = 0;
		}
		int ans = 0;
		for (int i = 0; i < 4; ++i) ans += map[i][0] * pow(2, i);
		cout << '#' << t << ' ' << ans << '\n';
	}
}