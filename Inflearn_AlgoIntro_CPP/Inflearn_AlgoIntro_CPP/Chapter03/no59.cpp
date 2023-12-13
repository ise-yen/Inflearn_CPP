#include <iostream>
#include <vector>

using namespace std;

vector<int> v;
vector<bool> isVisit;
int ch[11];

void answerDFS(int L, int n);

void dfs(int x, int n) { // 1부터 시작
	if (x > n) {
		for (int i = 1; i < isVisit.size();i++) {
			if (isVisit[i]) cout << i << " ";
		}
		cout << "\n";
		return;
	}
	isVisit[x] = true;
	dfs(x + 1, n);
	isVisit[x] = false;
	dfs(x + 1, n);
}

int main() {
	int N;
	cin >> N;
	
	isVisit.resize(N + 1, false);
	fill(isVisit.begin(), isVisit.end(), false);
	dfs(1, N);

	return 0;
}


// 이진 트리 구조로 구현
// 왼(참여) 오(비참여)
void answerDFS(int L, int n) {
	if (L == n + 1) {
		for (int i = 1; i <= n; i++) {
			if (ch[i] == 1) cout << i << " ";
		}
		cout << "\n";
	}
	else {
		ch[L] = 1;
		answerDFS(L + 1, n);
		ch[L] = 0;
		answerDFS(L + 1, n);
	}
}

