#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#define MAX 64
#define endl "\n"
using namespace std;
typedef pair<int, int> p;

int n, q;
int map[MAX][MAX];
bool visited[MAX][MAX];
vector<int> cmd;
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };
int temp[MAX][MAX];

void storming(int x, int y, int len) {
	if (len == 0 || len == 1)return;
	vector<int> tmp;
	//위쪽 저장
	for (int i = 0; i < len; i++) {
		tmp.push_back(map[y][x + i]);
	}
	//왼쪽 위로 옮기기
	for (int i = 0; i < len; i++) {
		int j = len - i - 1;
		map[y][x + j] = map[y + i][x];
	}
	//아래 왼쪽으로 옮기기
	for (int i = 0; i < len; i++) {
		map[y + i][x] = map[y + len - 1][x + i];
	}
	//오른족 아래로 옮기기
	for (int i = 0; i < len; i++) {
		int j = len - i - 1;
		map[y + len - 1][x + i] = map[y + j][x + len - 1];
	}
	//위 오른쪽으로 옮기기
	for (int i = 0; i < len; i++) {
		map[y + i][x + len - 1] = tmp[i];
	}
	storming(x + 1, y + 1, len - 2);
}

void melt() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			temp[i][j] = map[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == 0)continue;
			int cnt = 0;
			for (int d = 0; d < 4; d++) {
				int x = j + dx[d];
				int y = i + dy[d];
				if (x < 0 || y < 0 || x >= n || y >= n)continue;
				if (map[y][x] > 0)cnt++;
			}
			if (cnt >= 3)continue;
			else {
				temp[i][j] -= 1;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			map[i][j] = temp[i][j];
		}
	}
}

int counting() {
	int sum = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			sum += map[i][j];
		}
	}
	return sum;
}

int bfs(int sx, int sy) {
	int cnt = 1;
	queue<p> q;
	q.push({ sx,sy });
	visited[sy][sx] = true;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= n)continue;
			if (visited[ny][nx] == true)continue;
			if (map[ny][nx] == 0)continue;
			visited[ny][nx] = true;
			cnt++;
			q.push({ nx,ny });
		}
	}
	return cnt;
}

int biggest() {
	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] != 0 && visited[i][j] == false) {
				ans = max(ans, bfs(j, i));
			}
		}
	}
	return ans;
}

void Solution() {
	for (int i = 0; i < cmd.size(); i++) {
		int len = cmd[i];
		//회전
		for (int i = 0; i < n; i += len) {
			for (int j = 0; j < n; j += len) {
				storming(j, i, len);
			}
		}
		//녹이기
		melt();
	}
	cout << counting() << endl << biggest();
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> q;
	n = pow(2, n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < q; i++) {
		int com;
		cin >> com;
		com = pow(2, com);
		cmd.push_back(com);
	}
	Solution();
	return 0;
}