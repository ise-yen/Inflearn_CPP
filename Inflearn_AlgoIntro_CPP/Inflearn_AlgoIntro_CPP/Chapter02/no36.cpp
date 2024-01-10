#include<iostream>
#include<vector>

using namespace std;

int main() {
	int N{};
	cin >> N;
	vector<int> v;
	for (int i = 0; i < N; i++) {
		int tmp{};
		cin >> tmp;
		v.push_back(tmp);
	}

	for (int i = 1; i < N; i++) {
		int tmp = v[j];
		int j = i;
		for (j = i - 1; j >= 0; j--) {
			if (tmp < v[j]) v[j + 1] = v[j];
			else break;
		}
		v[j + 1] = tmp;
	}

	for (auto it : v) {
		cout << it << " ";
	}
}