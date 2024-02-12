#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	int N{}, M{}, answer{};
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		int tmp{};
		cin >> tmp;
		if (tmp <= M) answer++;
	}

	cout << answer;
	return 0;
}