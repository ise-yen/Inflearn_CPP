#include<iostream>
#include<vector>

using namespace std;

int ugly[3] = { 2, 3, 5 };
int N{}, answer{};

// 시간초과
void myCode() {
	int answer{}, cnt{};
	while(true) {
		answer++;
		int tmp = answer;
		bool isUgly = true;
		while (tmp > 1) {
			isUgly = false;
			for (int u = 0; u < 3; u++) {
				if (tmp % ugly[u] == 0) {
					tmp /= ugly[u];
					isUgly = true;
				}
			}

			if (tmp == 1) {
				isUgly = true;
				break;
			}
			if (isUgly) continue;
			else break;
		}
		if (isUgly) cnt++;
		if (cnt == N) break;
	}
}


void answerCode() {
	int p2 = 1, p3 = 1, p5 = 1;

	vector<int> v(N+1);
	v[1] = 1;

	for (int i = 2; i <= N; i++) {
		int min = INT_MAX;
		min = min < v[p2] * 2 ? min : v[p2] * 2;
		min = min < v[p3] * 3 ? min : v[p3] * 3;
		min = min < v[p5] * 5 ? min : v[p5] * 5;
		if (v[p2] * 2 == min) p2++;
		if (v[p3] * 3 == min) p3++;
		if (v[p5] * 5 == min) p5++;
		v[i] = min;
	}

	answer = v[N];
}

int main() {
	cin >> N;
	answerCode();

	cout << answer;
	return 0;
}