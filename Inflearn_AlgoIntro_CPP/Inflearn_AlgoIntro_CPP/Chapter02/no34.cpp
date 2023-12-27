#include <iostream>
#include <vector>

using namespace std;

int N{};
vector<int> v;
void answer() {
	for (int i = 0; i < N-1; i++) {
		for (int j = 0; j < N - i - 1; j++) {
			if (v[j] > v[j + 1]) {
				int tmp = v[j];
				v[j] = v[j+1];
				v[i+1] = tmp;
			}
		}
	}
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int tmp{};
		cin >> tmp;
		v.push_back(tmp);
	}

	int start = 1, end = N;
	bool isChange = true;
	while ((start < end) && isChange) {
		isChange = false;
		for (int i = start; i < end; i++) {
			if (v[i - 1] > v[i]) {
				int tmp = v[i];
				v[i] = v[i - 1];
				v[i - 1] = tmp;
				isChange = true;
			}
		}
		end--;
	}

	for (int i = 0; i < N; i++) {
		cout << v[i] << " ";
	}
	return 0;
}