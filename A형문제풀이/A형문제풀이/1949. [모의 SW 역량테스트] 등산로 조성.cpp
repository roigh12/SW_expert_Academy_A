#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int map[8][8]; //
int n, k; //
pair<int, int> start[70];//
int startSize;//

bool visit[8][8];//

int dx[4] = { 0,1,-1,0 }, dy[4] = { 1,0,0,-1 };//
int ans;//


// z는 1로 시작
void dfs(int depth, int x, int y, int z) {

	if (ans < depth) {
		ans = depth;
	}

	for (int i = 0; i < 4; ++i) {
		int nx = x + dx[i], ny = y + dy[i];
		if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;

		// 깎을 필요 없는 것
		if (map[nx][ny] < map[x][y]) {
			if (visit[nx][ny]) continue;
			visit[nx][ny] = 1;
			dfs(depth + 1, nx, ny, z);
			visit[nx][ny] = 0;
		}
		// 깎아야 진행 가능한 것
		else {
			int diff = map[nx][ny] - map[x][y] + 1;
			// 차이+1 만큼 깎는다
			if (diff > k) continue;
			if (z == 0) continue;
			if (visit[nx][ny]) continue;
			map[nx][ny] -= diff;
			visit[nx][ny] = 1;
			dfs(depth + 1, nx, ny, z-1);
			visit[nx][ny] = 0;
			map[nx][ny] += diff;
		}
	}
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int tc;
	cin >> tc;
	for (int t = 1; t <= tc; ++t) {
		startSize = 0;
		ans = 0;
		cin >> n >> k;
		int maxx = 0;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				cin >> map[i][j];
				maxx = maxx < map[i][j] ? map[i][j] : maxx;
			}
		}
		for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) 
				if (maxx == map[i][j]) 
					start[startSize++] = { i,j };

		for (int i = 0; i < startSize; ++i) {
			visit[start[i].first][start[i].second] = 1;
			dfs(1, start[i].first, start[i].second, 1);
			visit[start[i].first][start[i].second] = 0;
		}
		cout << '#' << t << ' ' << ans << '\n';
	}
	

}