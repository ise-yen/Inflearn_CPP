#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(int i, int j) {
	return j < i;
}

int main() {
	int N{};
	cin >> N;
	vector<int> v;
	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		v.push_back(tmp);
	}

	sort(v.begin(), v.end(), compare);

	int rank = 1;
	int score = v[0];
	for (int i = 1; i < N; i++) {
		if (score > v[i]) {
			rank++;
			score = v[i];
		}
		if (rank == 3) {
			cout << score;
			break;
		}
	}

	return 0;
}