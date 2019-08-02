#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

int moveSize, bcSize; //
int dirA[105], dirB[105]; //
int dx[5] = { 0,-1,0,1,0 }, dy[5] = { 0,0,1,0,-1 }; //
struct Node {
	int val, range, x, y;

	Node() : val(0), range(0) {}
	bool operator<(Node a)const {
		if (val == a.val) return range > a.range;
		return val > a.val;
	}
}; //
int info[10][10][10]; //
int infoSize[10][10]; //
Node MB[10];//
int ans = 0;//


// 각 좌표의 무선을 표시
void crossColor(int k) {
	int x = MB[k].x, y = MB[k].y, range = MB[k].range, val = MB[k].val;
	for (int i = x - range; i <= x + range; ++i) {
		for (int j = y - range; j <= y + range; ++j) {
			int D = abs(x - i) + abs(y - j);
			if (D > range) continue;
			if (i < 0 || i >= 10 || j < 0 || j >= 10) continue;
			info[i][j][infoSize[i][j]++] = k;
		}
	}
}

// A와 B가 이동하면서 ans 값에 더해줌
void solve(int a, int b, int c, int d) {
	if (infoSize[a][b] ==0 && infoSize[c][d] == 0) return;
	int firstA = MB[info[a][b][0]].val, secondA = MB[info[a][b][1]].val;
	int firstB = MB[info[c][d][0]].val, secondB = MB[info[c][d][1]].val;
	
	// 둘이 다른놈이면
	if (firstA != firstB) {
		ans += firstA + firstB;
	} 
	else {
		// 둘이 같은놈이면
		if (info[a][b][0] == info[c][d][0]) {
			if (secondA == 0 && secondB == 0) ans += firstA;
			else ans += (firstA + max(secondA, secondB));
		}
		// 둘이 다른놈이면 (index가)
		else {
			ans += firstA + firstB;
		}
	}
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int tc;
	cin >> tc;
	for (int t = 1; t <= tc; ++t) {
		ans = 0;
		for (int i = 0; i < 10; ++i)
			for (int j = 0; j < 10; ++j) {
				infoSize[i][j] = 0;
				for (int k = 0; k < 10; ++k)
					info[i][j][k] = 9;
			}

		cin >> moveSize >> bcSize;
		for (int i = 0; i < moveSize; ++i) cin >> dirA[i];
		for (int i = 0; i < moveSize; ++i) cin >> dirB[i];
		for (int i = 0; i < bcSize; ++i) {
			int x, y, range, val;
			cin >> MB[i].y >> MB[i].x >> MB[i].range >> MB[i].val;
			MB[i].y--; MB[i].x--;
		}
		sort(MB, MB + bcSize);
		

		for (int k = 0; k < bcSize; ++k) crossColor(k);


		int a = 0, b = 0, c = 9, d = 9;
		solve(a, b, c, d);
		for (int i = 0; i < moveSize; ++i) {
			a += dx[dirA[i]]; b += dy[dirA[i]];
			c += dx[dirB[i]]; d += dy[dirB[i]];
			solve(a, b, c, d);
		}
		cout << '#' << t << ' ' << ans << '\n';
	}
	
	

	
	



}