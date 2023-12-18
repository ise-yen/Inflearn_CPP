#include <iostream>
#include <vector>

using namespace std;

int main() {
	int N{}, ans{};
	cin >> N;
	vector<int> v;
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

	cout << ans;
	return 0;
}