#include <iostream>
using namespace std;

int n, x; //
int map[22][22]; //
int map2[22][22];//
int ans; //

bool isCan(int* arr) {
	int prev = 0;
	int cur = -1;
	for (int i = 1; i < n; ++i) {
		if (arr[prev] != arr[i]) {
			// ���̰� ������ ��
			if (arr[prev] > arr[i]) {
				int diff = arr[prev] - arr[i];
				if (diff != 1) return false;
				// ���������� �����
				if (prev + x >= n) return false;
				int end = i;
				while (end < n && arr[end] == arr[i]) {
					++end;
				}
				// �ε��� �ʰ��ϸ�
				if (prev + x > end - 1) return false;

				cur = prev + x;
			}
			//���̰� ������ ��
			else {
				int diff = arr[i] - arr[prev];
				if (diff != 1) return false;
				// ���������� �����
				if (i - x < 0) return false;
				int end = prev;
				while (end >= 0 && arr[end] == arr[prev]) {
					--end;
				}
				// �ε��� �ʰ��ϸ�
				if (i - x < end + 1) return false;
				
				if (i - x <= cur) return false;
				
			}
		}

		prev = i;
	}
	return true;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int tc;
	cin >> tc;
	for (int t = 1; t <= tc; ++t) {
		ans = 0;
		cin >> n >> x;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				cin >> map[i][j];
				map2[j][i] = map[i][j];
			}
		}
		for (int i = 0; i < n; ++i) {
			if (isCan(map[i])) {
				++ans;
			}
		}
		for (int i = 0; i < n; ++i) {
			if (isCan(map2[i])) {
				++ans;
			}
		}
		cout << '#' << t << ' ' << ans << '\n';
	}

}