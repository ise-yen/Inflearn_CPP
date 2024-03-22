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

int main() {
	cin >> N >> R;
	myCode2();
	cout << answer;
	return 0;
}