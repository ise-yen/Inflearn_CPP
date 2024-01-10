#include<iostream>
#include<unordered_set>
#include<vector>
#include<algorithm>

using namespace std;

void Answer() {
	int N{}, M{};
	cin >> N;
	vector<int> A;
	vector<int> B;
	vector<int> C;

	for (int i = 0; i < N; i++) {
		int tmp{};
		cin >> tmp;
		A.push_back(tmp);
	}
	sort(A.begin(), A.end());

	cin >> M;
	for (int i = 0; i < M; i++) {
		int tmp{};
		cin >> tmp;
		B.push_back(tmp);
	}
	sort(B.begin(), B.end());

	int pa{}, pb{};
	while (pa < N && pb < M) {
		if (A[pa] == B[pb]) {
			C.push_back(A[pa++]);
			pb++;
		}
		else if (A[pa] < B[pb]) pa++;
		else pb++;
	}

	for (auto it : C) {
		cout << it << " ";
	}
}

void MyAnswer() {
	int N{}, M{};
	cin >> N;
	unordered_set<int> A;
	vector<int> v;

	for (int i = 0; i < N; i++) {
		int tmp{};
		cin >> tmp;
		A.insert(tmp);
	}

	cin >> M;
	for (int i = 0; i < M; i++) {
		int tmp{};
		cin >> tmp;
		auto it = A.find(tmp);
		if (it != A.end()) {
			v.push_back(tmp);
		}
	}

	sort(v.begin(), v.end());

	for (auto it : v) {
		cout << it << " ";
	}
}

int main() {
	MyAnswer();
	return 0;
}