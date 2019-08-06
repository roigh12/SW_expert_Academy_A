#include <iostream>
using namespace std;

int visit[22][22]; //
int map[22][22]; //
int dx[4] = { -1,1,1,-1 }, dy[4] = { 1,1,-1,-1 }; //
int a, b, n; //
int desert[105]; //
int ans = -1; //

bool isInside(int a, int b) {
	if (a < 0 || a >= n || b < 0 || b >= n) return false;
	return true;
}
void dfs(int x, int y, int dir, int cnt) {
	if (x == a && y == b && dir == 3) {
		ans = cnt > ans ? cnt : ans;
		return;
	}
	
	int nx = x + dx[dir], ny = y + dy[dir];
	if (isInside(nx,ny) && !visit[nx][ny] && !desert[map[nx][ny]]) {
		desert[map[nx][ny]] = 1;
		visit[nx][ny] = 1;
		dfs(nx, ny, dir, cnt+1);
		visit[nx][ny] = 0;
		desert[map[nx][ny]] = 0;
	}

	if (dir < 3) {
		nx = x + dx[dir + 1]; ny = y + dy[dir + 1];
		if (isInside(nx, ny) && !visit[nx][ny] && !desert[map[nx][ny]]) {
			desert[map[nx][ny]] = 1;
			visit[nx][ny] = 1;
			dfs(nx, ny, dir + 1,cnt+1);
			visit[nx][ny] = 0;
			desert[map[nx][ny]] = 0;
		}
	}

}


int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int tc;
	cin >> tc;
	for (int t = 1; t <= tc; ++t) {
		ans = -1;
		cin >> n;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				cin >> map[i][j];
			}
		}

		for (int i = 1; i < n - 1; ++i) {
			for (int j = 0; j < n - 2; ++j) {
				a = i; b = j;
				dfs(a, b, 0, 0);
			}
		}
		cout << '#' << t << ' ' << ans << '\n';
	}
}