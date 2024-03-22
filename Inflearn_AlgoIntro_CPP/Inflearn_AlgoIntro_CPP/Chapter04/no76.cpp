#include<iostream>
#include<vector>

using namespace std;

int N{}, R{}, answer = 1;
const int MAX = 20;
void myCode1() {
	for (int i = N; i > N - R; i--) {
		answer *= i;
	}

	for (int i = 1; i <= R; i++) {
		answer /= i;
	}
}

vector<int> memo(MAX+1, 1);
void myCode2() {
	for (int i = 2; i <= N; i++) {
		memo[i] = memo[i - 1] * i;
	}

	answer = memo[N] / memo[R];
	answer /= memo[N - R];
}

// nCr = n-1Cr-1 + n-1Cr // n번째를 포함하는 경우와 포함하지 않는 경우
int recur(int n, int r) { // 재귀 방식
	if (n == r || r == 0) return 1;
	else return recur(n-1, r-1) + recur(n-1, r);
}

void answerCode_recur() {
	answer = recur(N, R);
}

int dy[MAX + 1][MAX + 1];
int recur_memo(int n, int r) { // 재귀 방식
	// 메모된 게 있으면
	if (dy[n][r] > 0) return dy[n][r];

	if (n == r || r == 0) return 1;
	else return recur(n - 1, r - 1) + recur(n - 1, r);
}

void answerCode_memo() {
	answer = recur_memo(N, R);
}

int main() {
	cin >> N >> R;
	answerCode_memo();
	cout << answer;
	return 0;
}