#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v;
int N{};

int main() {
	cin >> N;
	vector<int> answer(N);

	for (int i = 0; i < N; i++) {
		int num{};
		cin >> num;
		v.push_back(num);
	}

	int ans = N;
	for (int i = N - 1; i >= 0; i--) {
		if (v[i] == 0) answer[i] = ans;
		else {
			int j = i; // 현재 위치
			for (int k = 0; k < v[i]; k++) {
				answer[j] = answer[j + 1];
				j++;
			}
			answer[j] = ans;
		}
		ans--;
	}

	for (int i : answer) {
		cout << i << " ";
	}

	return 0;
}