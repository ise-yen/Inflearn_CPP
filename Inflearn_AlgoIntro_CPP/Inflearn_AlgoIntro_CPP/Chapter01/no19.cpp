#include <iostream>
#include <vector>

using namespace std;

vector<int> v;

void answer(int N) {
	int max = v[N-1];
	int cnt{};
	for (int i = N - 2; i >= 1; i--) {
		if (v[i] > max) {
			max = v[i];
			cnt++;
		}
	}
	cout << cnt;
}

int main() {
	int N{}, ans{};
	cin >> N;
	int max{}, maxP{};
	for (int i = 0; i < N; i++) {
		int tmp{};
		cin >> tmp;
		v.push_back(tmp);
		if (max <= tmp) {
			max = tmp;
			maxP = i;
		}
	}

	for (int i = maxP; i < v.size()-1; i++) {
		bool isVillian = true;
		for (int j = i+1; j < v.size(); j++) {
			if (v[i] <= v[j]) {
				isVillian = false;
				break;
			}
		}
		if (isVillian) {
			ans++;
		}
	}

	//cout << ans;
	answer(N);

	return 0;
}