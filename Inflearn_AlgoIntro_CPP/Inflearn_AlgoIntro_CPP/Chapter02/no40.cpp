#include<iostream>
#include<unordered_set>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	int N{}, M{};
	cin >> N;
	unordered_set<int> A;
	vector<int> answer;

	for (int i = 0; i < N; i++) {
		int tmp{};
		cin >> tmp;
		A.insert(tmp);
	}

	cin >> M;
	for (int i = 0; i < M; i++) {
		int tmp{};
		cin >> tmp;
		auto it = A.find(tmp);
		if (it != A.end()) {
			answer.push_back(tmp);
		}
	}

	sort(answer.begin(), answer.end());

	for (auto it : answer) {
		cout << it << " ";
	}

	return 0;
}