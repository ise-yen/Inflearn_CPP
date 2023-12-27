#include <iostream>
#include <vector>

using namespace std;

int main() {
	int N{};
	cin >> N;
	vector<int> v;

	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		v.push_back(tmp);
	}

	for (int i = 0; i < N-1; i++) {
		int pos = i+1;

		// i 다음 배열값 중 최소값 찾기
		for (int j = i+1; j < N; j++) {
			if (v[j] < v[pos]) {
				pos = j;
			}
		}
		if (v[pos] < v[i]) {
			int tmp = v[pos];
			v[pos] = v[i];
			v[i] = tmp;
		}
	}

	for (int i = 0; i < N; i++) {
		cout << v[i] << " ";
	}

}