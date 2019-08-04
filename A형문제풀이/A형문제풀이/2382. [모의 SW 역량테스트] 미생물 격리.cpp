#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

int dx[4] = { 0,1,-1,0 }, dy[4] = { 1,0,0,-1 };// 우하상좌
int convert[5] = { 0,2,1,3,0 };//


struct Node {
	int x, y, val, dir;
};
queue<Node> q; //
int n, m, k; //

struct mapInfo {
	int map, visit, maxx, vall;
	mapInfo() : map(0) {}
};

mapInfo info[105][105];

Node st[10005];//
int stSize;//

void bfs() {
	while (m--) {
		int qsize = q.size();
		while (qsize--) {
			Node F = q.front();
			int x = q.front().x, y = q.front().y, val = q.front().val, dir = q.front().dir;
			q.pop();
			
			int nx = x + dx[dir], ny = y + dy[dir];
			if (nx < 0 || ny < 0 || nx >= n || ny >= n) {
				cout << "error" << endl;
			}
			// 벽 처리
			if (info[nx][ny].map == -1) {
				dir = 3 - dir;
				val /= 2;
				q.push({ nx,ny,val,dir });
			}
			else {
				info[nx][ny].visit++;
				info[nx][ny].maxx = max(info[nx][ny].maxx, val);
				info[nx][ny].vall += val;
				st[stSize++] = { nx,ny,val,dir };
			}
		}

		

		// 합쳐진거 처리
		for (int i = 0; i < stSize; ++i) {
			Node F = st[i];
			int x = F.x, y = F.y, val = F.val, dir = F.dir;
			if (info[x][y].visit == 1) q.push(F);
			else if (info[x][y].visit >= 2) {
				if (info[x][y].maxx == val) q.push({ x,y,info[x][y].vall,dir });
			}
		}

		// 초기화
		for (int i = 0; i < stSize; ++i) {
			Node F = st[i];
			int x = F.x, y = F.y, val = F.val, dir = F.dir;
			info[x][y].visit = 0;
			info[x][y].maxx = 0;
			info[x][y].vall = 0;
		}

		stSize = 0;

	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int tc;
	cin >> tc;

	for (int t = 1; t <= tc; ++t) {
		cin >> n >> m >> k;

		// 벽 패딩
		for (int i = 0; i < n; ++i) {
			info[0][i].map = -1; info[n-1][i].map = -1;
		}
		for (int i = 0; i < n; ++i) {
			info[i][0].map = -1; info[i][n - 1].map = -1;
		}


		for (int i = 0; i < k; ++i) {
			int x, y, val, dir;
			cin >> x >> y >> val >> dir;
			dir = convert[dir];
			q.push({ x,y,val,dir });
		}


		bfs();

		int ans = 0;

		while (!q.empty()) {
			ans += q.front().val;
			q.pop();
		}
		cout << '#' << t << ' ' << ans << '\n';

		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				info[i][j].map = 0;
			}
		}


	}
	
	
}