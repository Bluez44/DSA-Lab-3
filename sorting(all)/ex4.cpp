#include<bits/stdc++.h>
using namespace std;


// IMPLEMENT QUICK SORT USING HOARE PARTITION ALGORITHM

void Print(int* start, int* end) {
    while(start != end) {
        cout << *start << " ";
        start++;
    }
}

int* Partition(int* start, int* end) {
    // TODO: return the pointer which points to the pivot after rearrange the array.
    int n = end - start;
    // cout << "\nstart =  " << *start << " end = " << *(end-1) <<  " n = " << n << endl;
    if(n <= 1) {
        if(n==1)cout << "0 ";
        return NULL;
    }
    int* tmp_start = start+1;
    int* tmp_end = end-1;
    bool flag = true;
    for(int i = 1, j = n-1; i < n || j >= 0; i++) {
        if(*tmp_start >= *start) {
            for( j; j >= 0; j--) {
                if(*tmp_end < *start && j > i) {
                    int data = *tmp_start;
                    *tmp_start = *tmp_end;
                    *tmp_end = data;
                    break;
                }
                else if(j < i) {
                    flag = false;
                    cout << j << " ";
                    break;
                }
                tmp_end--;
            }
        }
        if(!flag) {
            int data = *tmp_end;
            *tmp_end = *start;
            *start = data;
            break;
        }
        tmp_start++;
    }
    // cout << endl;
    // Print(start, end);
    // cout << endl;
    return tmp_end;
}

void QuickSort(int* start, int* end) {
    // TODO
    // In this question, you must print out the index of pivot in subarray after everytime calling method Partition.
    int* pivot = Partition(start, end); 
    if(!pivot) return;
    // pivot++;
    QuickSort(start, pivot);
    // cout << "tmp = " <<  *tmp << " end = " << *(end-1) << endl;
    if(pivot <= end-1) QuickSort(pivot+1, end);

}

int main() {
    int array[] = { 3, 5, 7, 10 ,12, 14, 15, 13, 1, 2, 9, 6, 4, 8, 11, 16, 17, 18, 20, 19 };
    for(int i = 0; i < 20; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
    QuickSort(&array[0], &array[20]);
    cout << endl;
    for(int i = 0; i < 20; i++) {
        cout << array[i] << " ";
    }
    return 0;
}

// 2 0 0 6 1 0 2 1 0 0 2 1 0 0 0 0 0 0 1 0
// 2 0 0 6 1 0 2 1 0 0 2 1 0 0 0 0 0 0 1 0