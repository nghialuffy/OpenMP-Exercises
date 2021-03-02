#include <bits/stdc++.h>
#include <omp.h>
using namespace std;
using namespace std::chrono; // namespace count time

#define MAX 500000
int A[MAX];
int main() {

	// Read file
	ifstream f("Bai3_Text.txt");
	for (int i = 0; i < MAX; i++) {
		f >> A[i];
	}
	int N_THREADS;
	cout << "Input number of threads: ";
	cin >> N_THREADS;
		
	// Serial area
	//
	int s = 0;
	for (int i = 0; i < MAX; i++) {
		s+=A[i];
	}
	cout << "Sum serial: " << s << endl;
	// Parallel area
	//
	omp_set_num_threads(N_THREADS);
	int sum=0;
	
	auto start = high_resolution_clock::now();
	#pragma omp parallel for reduction(+:sum)
	for (int i = 0; i < MAX; i++){
			sum+=A[i];
		}


	cout << "Sum: "<< sum << endl;
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);
	
	cout << duration.count() << "us to calc sum of " << MAX << " elements in array!" << endl ;
	ofstream log("log.txt", std::ios_base::app);
	log << N_THREADS << "threads: " << duration.count() << "us to calc sum of " << MAX << " elements in array! Sum: " << sum << endl ;
	return 0;
}