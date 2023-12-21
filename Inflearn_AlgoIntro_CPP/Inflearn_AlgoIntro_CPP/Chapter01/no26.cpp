#include <iostream>
#include <vector>

using namespace std;

int main() {
	int N{};
	cin >> N;
	vector<pair<int, int>> v;
	for (int i = 0; i < N; i++) {
		int average{};
		cin >> average;
		v.push_back({ average, i+1 });
	}

	for (int i = 1; i < N; i++) {
		for (int j = 0; j < i; j++) {
			if (v[j].first < v[i].first) v[i].second--;
		}
	}

	for (int i = 0; i < N; i++) {
		cout << v[i].second << " ";
	}

	return 0;
}