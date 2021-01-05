#include <iostream>
#include <vector>

using namespace std;

vector< pair <vector<int>, int> > Bublesort(vector<int> &arr) {
	int numSwaps = 0;
	int n = arr.size();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
				numSwaps++;
			}
		}
		if (numSwaps == 0) break;
	}
	vector< pair <vector<int>, int> > vect;
	vect.push_back(make_pair(arr, numSwaps));

	 
	return vect;
};
// input must be reference, if not only the image of input is sort but not input
vector<int>  Bublesort_only(vector<int> &arr) {
	int n = arr.size();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
	 
			}
		} 
	}  
	return arr;
};

int main() {
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	// Write Your Code Here

	vector< pair <vector<int>, int> > vect = Bublesort(arr);
	arr = vect[0].first;
	int numSwaps = vect[0].second;
	for (int i = 0; i < n; i++) {
		cout << arr[i] <<" ";
	}
	cout << endl;
	printf("Array is sorted in %i swaps.\n", numSwaps);
	printf("First Element: %i\n", arr[0]);
	printf("Last Element: %i\n", arr[arr.size() - 1]);

	return 0;
}
