#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int n, m; //
int map[22][22]; //
int ans;//
void cross(int a, int b, int k, int val) {
	int c = k - 1;
	int summ = 0;

	for (register int i = a - c; i <= a + c; ++i) {
		for (register int j = b - c; j <= b + c; ++j) {
			if (i<0 || i >= n || j < 0 || j >= n) continue;
			if (abs(i - a) + abs(j - b) > c) continue;
			summ += map[i][j];
		}
	}
	// 손해를 보지 않으면
	if (summ * m >= val)
		ans = max(ans, summ);

}


int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int tc;
	cin >> tc;
	for (register int t = 1; t <= tc; ++t) {
		cin >> n >> m;
		int cnt = 0;
		for (register int i = 0; i < n; ++i) {
			for (register int j = 0; j < n; ++j) {
				cin >> map[i][j];
				if (map[i][j]) cnt++;
			}
		}
		if (cnt * m >= n * n + (n - 1)*(n - 1)) {
			cout << '#' << t << ' ' << cnt << '\n';
			continue;
		}

		for (register int k = n + 3; k >= 1; --k) {
			ans = 0;
			int val = k * k + (k - 1)*(k - 1);
			for (register int i = 0; i < n; ++i) {
				for (register int j = 0; j < n; ++j) {
					cross(i, j, k, val);
				}
			}
			if (ans != 0) {
				cout << '#' << t << ' ' << ans << '\n';
				break;
			}
		}
	}
	



}