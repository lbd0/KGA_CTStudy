#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template<typename T>
int Divide(vector<T>& v, int low, int high) {
	T pivot = v[low];
	int i = low;
	int j = high + 1;

	while (true) {
		do {
			i++;
		} while (i <= high && v[i] < pivot);

		do {
			j--;
		} while (j >= low && v[j] > pivot);

		if (i >= j)
			break;

		std::swap(v[i], v[j]);
	}
	
	std::swap(v[low], v[j]);

	return j;
}

template<typename T>
void QuickSort(vector<T>& v, int low, int high) {
	if (low < high) {
		int pivoiIndex = Divide(v, low, high);

		QuickSort(v, low, pivoiIndex - 1);
		QuickSort(v, pivoiIndex + 1, high);
	}

}


int main() {
	vector<int> a;
	a.push_back(5);
	a.push_back(3);
	a.push_back(8);
	a.push_back(4);
	a.push_back(9);
	a.push_back(1);
	a.push_back(6);
	a.push_back(2);
	a.push_back(7);


	QuickSort(a, 0, a.size()-1);

	for (auto n : a) {
		cout << n << endl;
	}

}