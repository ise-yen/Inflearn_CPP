#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
	int N{};
	cin >> N;

	vector<int> v;
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