#include <iostream>
using namespace std;

int v[15], vSize, b[15], bSize, n, r;

int D, W, K; // 두께, 가로, 합격기준
int map[15][22]; //

bool flag; //

// v,b 배열대로 패딩시키고 합격기준 통과하는지 검사
bool solve() {
	int temp[15][22];
	for (int i = 0; i < D; ++i) {
		for (int j = 0; j < W; ++j) {
			temp[i][j] = map[i][j];
		}
	}

	// 패딩
	for (int i = 0; i < vSize; ++i) {
		for (int j = 0; j < W; ++j) {
			temp[v[i]][j] = b[i];
		}
	}


	// 시뮬
	bool can = true;
	for (int j = 0; j < W; ++j) {
		int cnt = 1;
		for (int i = 1; i < D; ++i) {
			if (temp[i][j] == temp[i - 1][j]) ++cnt;
			else cnt = 1;

			if (cnt == K) break;
		}
		if (cnt < K) {
			can = false;
			break;
		}

	}
	return can;
}

// v배열 가지고 1 0 10
void dfs2(int depth) {
	if (flag) return;
	if (depth == vSize) {
		if (solve()) flag = true;
		return;
	}
	for (int i = 0; i < 2; ++i) {
		b[bSize++] = i;
		dfs2(depth + 1);
		bSize--;
	}
}


// nCr에 해당하는 행을 v배열에 담음 항상 0,0
void dfs(int depth, int start) {
	if (flag) return;
	if (depth == r) {
		dfs2(0);
		return;
	}
	for (int i = start; i < D; ++i) {
		v[vSize++] = i;
		dfs(depth + 1, i + 1);
		
		vSize--;
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int tc;
	cin >> tc;
	for (int t = 1; t <= tc; ++t) {
		flag = false;
		cin >> D >> W >> K;
		for (int i = 0; i < D; ++i) {
			for (int j = 0; j < W; ++j) {
				cin >> map[i][j];
			}
		}
		bool can = true;
		for (int j = 0; j < W; ++j) {
			int cnt = 1;
			for (int i = 1; i < D; ++i) {
				if (map[i][j] == map[i - 1][j]) ++cnt;
				else cnt = 1;

				if (cnt == K) break;
			}
			if (cnt < K) {
				can = false;
				break;
			}

		}
		if (can) {
			cout << '#' << t << ' ' << 0 << '\n';
		}
		else {
			for (int i = 1; i <= D; ++i) {
				r = i;
				dfs(0, 0);
				if (flag) break;
			}
			cout << '#' << t << ' ' << r << '\n';
		}
	}
	
}