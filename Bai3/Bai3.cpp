#include <bits/stdc++.h>
#include <omp.h>
using namespace std;
using namespace std::chrono; // namespace count time

#define MAX 500000
int A[MAX];
int sum_in_range(int start_idx, int end_idx) {
	int sum = 0;
	for (int i = start_idx; i < end_idx; i++) {
		sum+= A[i];
	}
	return sum;
}
int main() {
	ifstream f("Bai3_Text.txt");
	for (int i = 0; i < MAX; i++) {
		f >> A[i];
	}
	int N_THREADS;
	cout << "Input number of threads: ";
	cin >> N_THREADS;

	cout << "Sum with serial: " << endl;
	cout << sum_in_range(0, MAX-1) << endl;

	omp_set_num_threads(N_THREADS);
	int sum[N_THREADS];
	
	auto start = high_resolution_clock::now();
	int start_idx, end_idx;
	#pragma omp parallel private (start_idx, end_idx)
	{
		int thread_id = omp_get_thread_num();
		int n_process_eles = MAX / N_THREADS;
		start_idx = thread_id*n_process_eles;
		end_idx =(thread_id+1)*n_process_eles-1; 	
		sum[thread_id]= sum_in_range(start_idx, end_idx) ;
		cout << "Thread "<< thread_id<<": " <<sum[thread_id] << 
			" from "<< start_idx << " to "<< end_idx <<endl;
	}

	for (int i = 1; i < N_THREADS; i++) {
		sum[0]+= sum[i];
	}

	cout << "Sum: "<< sum[0] << endl;
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);
	
	cout << duration.count() << "us to calc sum of " << MAX << " elements in array!" << endl ;
	ofstream log("log.txt", std::ios_base::app);
	log << N_THREADS << "threads: " << duration.count() << "us to calc sum of " << MAX << " elements in array! Sum: " << sum[0] << endl ;
	return 0;
}