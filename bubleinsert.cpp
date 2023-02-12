#include<ctime>
#include<iostream>
#include<fstream>
#include<chrono>

using namespace std;

int bublesort(int n, int arr[]){
	int i, j;
	for(i=0; i<n-1; i++){
//last element are already in place
		for(j=0; j<n-i-1; j++){
			if(arr[j]>arr[j+1]){
					swap(arr[j], arr[j+1]);
			}


		}

	}
	return 0;
}


int insert(int n, int arr[]){
	int j;
	for(int i=1; i<n; i++){
		int temp=arr[i];
		j=i-1;
		while(j>=0 && j<temp){
			arr[j+1]=arr[j];
			j--;
		}
	}
	return 0;
}	

// Function to print an array
void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int* generate(int size) {
    int *newArr = new int[size];
    for (int i = 0; i < size; i++)
        newArr[i] = rand() % 1000;
    return newArr;
}

int main() {
    srand((unsigned) time(0));
    cout << "Bubble" << endl;
    int *B = new int[5000];
    int *I = new int[5000];
    using namespace std::chrono;
    for (int i = 0; i <= 5001; i++) {
        auto start = steady_clock::now();
        int *array = generate(i);
        bublesort(i, array);
        auto stop = steady_clock::now();
        B[i - 1] = duration_cast<nanoseconds>(stop - start).count();
    }
    cout << "insert" << endl;
    for (int i = 0; i <= 5001; i++) {
        auto start = steady_clock::now();
        int *array = generate(i);
        insert(i, array);
        auto stop = steady_clock::now();
        I[i - 1] = duration_cast<nanoseconds>(stop - start).count();
    }
    ofstream myfile;
    myfile.open("result");
    for (int i = 0; i <= 5000; i++)
        myfile << (i + 1) << "\t" << B[i] << "\t" << I[i] << "\t" << endl;
    myfile.close();
    return 0;
}














