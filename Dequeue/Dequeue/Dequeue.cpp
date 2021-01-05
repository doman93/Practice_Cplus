#include <iostream>
#include <deque> 
#include <vector>
#include <string>
using namespace std;

void Print_queue(deque<int> De_que){
	int n_que = De_que.size();
	for (int i = 0; i < n_que; ++i)
	{
		cout << De_que[i] << " ";
	}
	cout << "Data" << endl;
}
void printKMax(vector<int> arr, int n, int k) {
	//Write your code here.
	deque<int> De_que;
	int i;

	for (i = 0; i < k; i++)
	{
		bool tmp = De_que.empty();
 
		 
		// Remove all value of de_que if exist
		while (!De_que.empty() && arr[i] >= arr[De_que.back()])
		{
			int x = De_que.front();
			cout <<"Pos0:"<< x << endl;
			De_que.pop_back();
		}
		// Add data to de_que
		De_que.push_back(i);
	}
	Print_queue(De_que);

	for (i = k; i < n; i++)
	{
		cout << arr[De_que.front()] << endl;
		Print_queue(De_que);

		while (!De_que.empty() && De_que.front() <= i - k)
		{
			int x = De_que.front();
			cout << "Pos1:"<< x << endl;
			De_que.pop_front();
		}
		Print_queue(De_que);
		while (!De_que.empty() && arr[i] >= arr[De_que.back()])
		{
			int x = De_que.back();
			cout <<"Pos2:"<<x << endl;
			De_que.pop_back();
		}
		cout << "i = " << i << endl;
		De_que.push_back(i);
		Print_queue(De_que);

	}
	cout << arr[De_que.front()] << endl;
	Print_queue(De_que);
}


int main() {

	int t;
	cin >> t;
	while (t > 0) {
		int n, k;
		cin >> n >> k;
		int i;
		vector<int> arr(n);
		for (i = 0; i < n; i++)
			cin >> arr[i];
		printKMax(arr, n, k);
		t--;
	}
	return 0;
}