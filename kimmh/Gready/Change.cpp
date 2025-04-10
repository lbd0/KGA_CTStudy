#include <iostream>
#include <vector>

using namespace std;

int change(int change) {
	
	int answer = 0;

	vector<int> coins = { 500, 100, 50, 10 };

	for (int coin : coins) {
		answer += change / coin;
		change %= coin;
	}

	return answer;

}

int main() {
	cout << change(1460) << endl;
	cout << change(1890) << endl;
}