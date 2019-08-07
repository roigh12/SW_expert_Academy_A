#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int dx[4] = { 0,0,1,-1 }, dy[4] = { 1,-1,0,0 }; //동서남북
vector<int> info[8]; //
int n, m, r, c, L; //
int map[55][55]; //
bool visit[55][55]; //

struct Node {
	int x, y;
};

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	for (int i = 0; i < 4; ++i) info[1].push_back(i);
	info[2].push_back(2); info[2].push_back(3);
	info[3].push_back(0); info[3].push_back(1);
	info[4].push_back(0); info[4].push_back(3);
	info[5].push_back(0); info[5].push_back(2);
	info[6].push_back(1); info[6].push_back(2);
	info[7].push_back(1); info[7].push_back(3);


	int tc;
	cin >> tc;
	for (int t = 1; t <= tc; ++t) {

		cin >> n >> m >> r >> c >> L;
		for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j)	cin >> map[i][j];

		visit[r][c] = 1;
		queue<Node> q;
		q.push({ r,c });
		int cnt = 0;
		L--;
		while (L--) {
			int qsize = q.size();
			while (qsize--) {
				int x = q.front().x, y = q.front().y;
				q.pop();

				int num = map[x][y];
				for (int i = 0; i < info[num].size(); ++i) {
					int dir = info[num][i];
					int nx = x + dx[dir], ny = y + dy[dir];

					if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
					if (visit[nx][ny]) continue;
					if (map[nx][ny] == 0) continue;
					// 상대방이 연결 안되어 있으면 continue;
					bool flag = 0;
					int num2 = map[nx][ny];
					for (int j = 0; j < info[num2].size(); ++j) {
						int dir2 = info[num2][j];
						int nx2 = nx + dx[dir2], ny2 = ny + dy[dir2];
						if (x == nx2 && y == ny2) {
							flag = 1; break;
						}
					}
					if (flag == 0) continue;

					visit[nx][ny] = 1;

					q.push({ nx,ny });
				}
			}
		}

		int ans = 0;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (visit[i][j]) ++ans;
			}
		}
		cout << '#' << t << ' ' << ans << '\n';
		memset(visit, 0, sizeof(visit));
	}
}
