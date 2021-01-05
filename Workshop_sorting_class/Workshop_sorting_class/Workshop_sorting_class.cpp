#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
/*
// Solution 1 : Using vector pointer

//Define the structs Workshops and Available_Workshops.
//Implement the functions initialize and CalculateMaxWorkshops


class Available_Workshops{
public:
	int n;
	int start_time;
	int duration;
	int end_time;
public:
	Available_Workshops(int start_time, int duration, int n)
	{
		this->n = n;
		for (int i = 0; i < n; i++) {
			//construct a Workshops
			this->start_time  = start_time ;
			this->duration  = duration ;
			this->end_time  = start_time  + duration ;
		}
	}
};


bool compare( Available_Workshops*   w1,  Available_Workshops*   w2) {
	return (w1->end_time < w2->end_time);
}

int CalculateMaxWorkshops(vector<Available_Workshops*> ptr, int n) {
	// sort workshops by end_time

	sort(ptr.begin() , ptr.end(), compare);

	// interval scheduling
	int last_processed_time = -1;
	int maxWorkshops = 0;
	for (int i = 0; i <  n; i++) {
		if (ptr[i]-> start_time  >= last_processed_time ) {
			last_processed_time = ptr[i]-> end_time ;
			maxWorkshops++;
		}
	}

	return maxWorkshops;
}
int main(int argc, char *argv[]) {
	int n; // number of workshops
	cin >> n;
	// create arrays of unknown size n
	vector<int> start_time(n);
	vector<int> duration(n);

	for (int i = 0; i < n; i++) {
		cin >> start_time[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> duration[i];
	}

	vector<Available_Workshops*>  ptr(n);
	for (int i = 0; i < n; i++) {
		 ptr[i] =  new Available_Workshops(start_time[i], duration[i], n);
	}
	cout << CalculateMaxWorkshops(ptr,n) << endl;
	return 0;
}

*/

// Solution 2:
//Define the structs Workshops and Available_Workshops.
//Implement the functions initialize and CalculateMaxWorkshops
struct Workshops {
	int start_time;
	int duration;
	int end_time;
};

struct Available_Workshops {
	int n;
	vector <Workshops> w;
};

Available_Workshops *initialize(int *start_time, int *duration, int n) {
	Available_Workshops *paw = new(Available_Workshops);
	Workshops ws;

	paw->n = n;
	for (int i = 0; i < n; i++) {
		//construct a Workshops
		ws.start_time = start_time[i];
		ws.duration = duration[i];
		ws.end_time = start_time[i] + duration[i];
		paw->w.push_back(ws);
	}

	return paw;
}

bool compare(Workshops w1, Workshops w2) {
	return (w1.end_time < w2.end_time);
}

int CalculateMaxWorkshops(Available_Workshops* ptr) {
	// sort workshops by end_time
	sort(ptr->w.begin(), ptr->w.end(), compare);

	// interval scheduling
	int last_processed_time = -1;
	int maxWorkshops = 0;
	for (int i = 0; i < ptr->n; i++) {
		if (ptr->w[i].start_time >= last_processed_time) {
			last_processed_time = ptr->w[i].end_time;
			maxWorkshops++;
		}
	}

	return maxWorkshops;
}
int main(int argc, char *argv[]) {
	int n; // number of workshops
	cin >> n;
	// create arrays of unknown size n
	int* start_time = new int[n];
	int* duration = new int[n];

	for (int i = 0; i < n; i++) {
		cin >> start_time[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> duration[i];
	}

	Available_Workshops * ptr;
	ptr = initialize(start_time, duration, n);
	cout << CalculateMaxWorkshops(ptr) << endl;
	return 0;
}

