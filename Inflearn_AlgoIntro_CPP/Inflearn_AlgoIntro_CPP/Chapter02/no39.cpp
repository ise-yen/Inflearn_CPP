#include <iostream>
#include <vector>

using namespace std;

int main() {
	int N{}, M{};
	cin >> N;
	vector<int> vn, vm, ans;
	for (int i = 0; i < N; i++) {
		int tmp{};
		cin >> tmp;
		vn.push_back(tmp);
	}
	cin >> M;
	for (int i = 0; i < M; i++) {
		int tmp{};
		cin >> tmp;
		vm.push_back(tmp);
	}

	int ni{}, mj{};
	while(ni < N && mj < M) {
		if (vn[ni] <= vm[mj]) {
			ans.push_back(vn[ni]);
			ni++;
		}
		else {
			ans.push_back(vm[mj]);
			mj++;
		}
	}

	if (ni == N) {
		while (mj < M) {
			ans.push_back(vm[mj]);
			mj++;
		}
	}
	else {
		while (ni < N) {
			ans.push_back(vn[ni]);
			ni++;
		}
	}

	for (int a = 0; a < ans.size(); a++) {
		cout << ans[a] << " ";
	}
}