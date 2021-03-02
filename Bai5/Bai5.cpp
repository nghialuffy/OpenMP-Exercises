#include <bits/stdc++.h>
#include <omp.h>
using namespace std;
using namespace std::chrono; // namespace count time

#define MAX 1000000
int A[MAX];
int B[MAX];
int C1[MAX];
int C2[MAX];
int main() {

	// Read file
	ifstream f1("Bai5_A.txt");
	ifstream f2("Bai5_B.txt");
	for (int i = 0; i < MAX; i++) {
		f1 >> A[i];
		f2 >> B[i];
	}
	int N_THREADS;
	cout << "Input number of threads: ";
	cin >> N_THREADS;
		
	// Serial area
	//
	auto starts = high_resolution_clock::now();
	for (int i = 0; i < MAX; i++) {
		C1[i] = A[i] + B[i];
	}
	
	for (int i = 500051; i < 500060; i++) {
		cout << C1[i] << " ";
	}
	auto stops = high_resolution_clock::now();
	auto durations = duration_cast<microseconds>(stops - starts);
	cout << endl;
	cout << "Serial: "<< durations.count() << "us " << endl ;
	// Parallel area
	omp_set_num_threads(N_THREADS);
	
	auto start = high_resolution_clock::now();
	#pragma omp parallel 
	{
		#pragma omp for nowait
    	for(int i = 0; i < MAX; i++)
      	{
			C2[i] = A[i] + B[i];    	
		}
  	}

	
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);
	
	for (int i = 500051; i < 500060; i++) {
		cout << C2[i] << " ";
	}
	cout << duration.count() << "us " << endl ;
	ofstream log("log.txt", std::ios_base::app);
	log << N_THREADS << "threads: " << duration.count() << "us" << endl ;
	return 0;
}