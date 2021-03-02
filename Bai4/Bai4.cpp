#include <bits/stdc++.h>
#include <omp.h>
using namespace std;
using namespace std::chrono; // namespace count time

#define MAX 1000000
int A[MAX];
int main() {

	ifstream f("Bai4_Text.txt");
	for (int i = 0; i < MAX; i++) {
		f >> A[i];
	}
	int N_THREADS;
	cout << "Input number of threads: ";
	cin >> N_THREADS;
		
	// Serial area
	//
	int max=-1, min=999999;
	for (int i = 0; i < MAX; i++) {
		if (A[i]>max) max=A[i];
		if (A[i]<min) min=A[i];
	}
	cout << "Max: " << max << " Min: "<< min << endl;
	// Parallel area
	omp_set_num_threads(N_THREADS);
	int max1=-1, min1=999999;
	
	auto start = high_resolution_clock::now();
	#pragma omp parallel 
	{
        int minn = 999999;
		int maxx = -1;
		#pragma omp for nowait
    		for(int i = 0; i < MAX; i++)
      		{
        		minn = std::min(A[i], minn);
      			maxx = std::max(A[i], maxx);
		}
		#pragma omp critical 
    		{
      			min1 = std::min(min1, minn);
    			max1 = std::max(max1, maxx);
		}
  	}

	cout << "Max: " << max1 << " Min: "<< min1 << endl;

	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);
	
	cout << duration.count() << "us " << endl ;
	ofstream log("log.txt", std::ios_base::app);
	log << N_THREADS << "threads: " << duration.count() << "us with max " << max1 << " with Min " << min1 << endl ;
	return 0;
}