#include <iostream>
using namespace std;

int const SIZE = 15;

void BucketSort(int *array);
void InsertionSort(int*array,int size);
void PrintArray(int *array);

int main ()
{
	srand (time(NULL));
	int array[SIZE];
	for(int i = 0;i < SIZE;i++) {
		array[i] = rand() % 99 + 1;
	}
	cout << "unsorted: ";
	PrintArray(array);
	BucketSort(array);
	cout << "sorted:   ";
	PrintArray(array);
	return 0;
}
void BucketSort(int *array) {
	int buckets[SIZE][SIZE] = {0};
	int counts[SIZE] ={0};
	for(int i = 0;i < SIZE;i++) {
		if(array[i] < 10) {
			buckets[0][counts[0]] = array[i];
			counts[0]++; 
			InsertionSort(buckets[0],counts[0]);
		} else if(array[i] < 20) {
			buckets[1][counts[1]] = array[i];
			counts[1]++; 
			InsertionSort(buckets[1],counts[1]);
		} else if(array[i] < 30) {
			buckets[2][counts[2]] = array[i];
			counts[2]++; 
			InsertionSort(buckets[2],counts[2]);
		} else if(array[i] < 40) {
			buckets[3][counts[3]] = array[i];
			counts[3]++; 
			InsertionSort(buckets[3],counts[3]);
		} else if(array[i] < 50) {
			buckets[4][counts[4]] = array[i];
			counts[4]++; 
			InsertionSort(buckets[4],counts[4]);
		} else if(array[i] < 60) {
			buckets[5][counts[5]] = array[i];
			counts[5]++;
			InsertionSort(buckets[5],counts[5]);
		} else if(array[i] < 70) {
			buckets[6][counts[6]] = array[i];
			counts[6]++; 
			InsertionSort(buckets[6],counts[6]);
		} else if(array[i] < 80) {
			buckets[7][counts[7]] = array[i];
			counts[7]++; 
			InsertionSort(buckets[7],counts[7]);
		} else if(array[i] < 90) {
			buckets[8][counts[8]] = array[i];
			counts[8]++; 
			InsertionSort(buckets[8],counts[8]);
		} else if(array[i] < 100) {
			buckets[9][counts[9]] = array[i];
			counts[9]++; 
			InsertionSort(buckets[9],counts[9]);
		}
	}
	int count = 0;
	for(int i = 0;i < SIZE;i++) {
		for(int j = 0;j < SIZE;j++) {
			if(buckets[i][j] != 0) {
				array[count] = buckets[i][j];
				count++;
			}
		}
	}
}
void InsertionSort(int*array,int size) {
	for(int i = 1;i < size;i++) {
		int current = array[i];
		int j = i - 1;
		while(j >= 0 && array[j] > current) {
			array[j+1] = array[j];
			j--;
		}
		array[j+1] = current;
	}
}
void PrintArray(int *array) {
	for(int i = 0;i < SIZE;i++) {
		cout << array[i] << " ";
	}
	cout << endl;
}