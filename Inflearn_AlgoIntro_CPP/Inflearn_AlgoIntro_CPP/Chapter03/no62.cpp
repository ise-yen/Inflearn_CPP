#include <iostream>
#include <vector>

using namespace std;

vector<int> v;
vector<int> tmp;

void divide(int left, int right) {
	int mid{}, p1{}, p2{}, p3{};
	if (left < right) {
		// 분할
		mid = (left + right) / 2;
		divide(left, mid);
		divide(mid + 1, right);

		p1 = left;
		p2 = mid + 1;
		p3 = left;
		
		// 병합
		while (p1 <= mid && p2 <= right) {
			if (v[p1] < v[p2]) tmp[p3++] = v[p1++];
			else tmp[p3++] = v[p2++];
		}

		// 남은 거 싹쓰리
		while (p1 <= mid) tmp[p3++] = v[p1++];
		while (p2 <= right) tmp[p3++] = v[p2++];

		// 복붙
		for (int i = left; i <= right; i++) {
			v[i] = tmp[i];
		}
	}
}

int main() {
	int N{};
	cin >> N;
	tmp.resize(N);
	for (int i = 0; i < N; i++) {
		int tmp{};
		cin >> tmp;
		v.push_back(tmp);
	}

	divide(0, N-1);

	for (int i = 0; i < N; i++) {
		cout << v[i] << " ";
	}

	return 0;
}