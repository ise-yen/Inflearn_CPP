#include<iostream>
#include<functional>
#include<queue>

using namespace std;

int main() {
	priority_queue<int> pq;
	int tmp{};

	cin >> tmp;
	if (tmp == -1) cout << -1;
	while (tmp != -1) {
		if(tmp != 0)
			pq.push(tmp);
		else {
			cout << pq.top() << "\n";
			pq.pop();
		}
		cin >> tmp;
	}
	return 0;
}