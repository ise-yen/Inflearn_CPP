#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N{};
vector<int> v;

void answer() {
	for (int i = 0; i < N - 1; i++) {
		for (int j = 0; j < N - 1 - j; j++) {
			if (v[j] > 0 && v[j + 1] < 0) {
				int tmp = v[j];
				v[j] = v[j + 1];
				v[j + 1] = tmp;
			}
		}
	}
}

int main() {
	cin >> N;

	vector <queue<int>> mzp(2);

	for (int i = 0; i < N; i++) {
		int tmp{};
		cin >> tmp;
		v.push_back(tmp);
	}

	for (int i = 0; i < N; i++) {
		if (v[i] < 0) mzp[0].push(v[i]);
		else mzp[1].push(v[i]);
	}

	int j = 0;
	for (int i = 0; i < mzp.size(); i++) {
		while (!mzp[i].empty()) {
			v[j] = mzp[i].front();
			mzp[i].pop();
			j++;
		}
	}

	for (auto elem : v) {
		cout << elem << " ";
	}

	return 0;
}