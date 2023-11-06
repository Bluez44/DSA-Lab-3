// Given a list of distinct unsorted integers nums.

// Your task is to implement a function with following prototype:
// int minDiffPairs(int* arr, int n);
// This function identify and return all pairs of elements with the smallest absolute difference among them. If there are multiple pairs that meet this criterion, the function should find and return all of them.

// Note: Following libraries are included: iostream, string, algorithm, sstream

#include<bits/stdc++.h>
using namespace std;



void selectionSort(int* &arr, int n) {
    int *head = arr;
    for(int i = 0; i < n; i++) {
        int *curr = head;
        int *min = head;
        for(int j = i+1; j < n; j++) {
            curr++;
            if(*curr < *min) min = curr;
        }
        int data = *min;
        *min = *head;
        *head = data;
        head++;
    }
}

string minDiffPairs(int* arr, int n){
    // STUDENT ANSWER
    if(n <= 1) return "";
    selectionSort(arr,n);
    int mindiff = 100000;
    string RES ="";
    for(int i = 0; i < n-1; i++) {
        int sub = arr[i]-arr[i+1]; if(sub < 0) sub = 0-sub;
        if(sub < mindiff) mindiff = sub;
    }
    for(int i = 0; i < n-1; i++) {
        int sub = arr[i]-arr[i+1]; if(sub < 0) sub = 0-sub;
        if(sub == mindiff) RES += '(' + to_string(arr[i]) + ", " + to_string(arr[i+1]) + "), ";
    }
    
    return RES.substr(0,RES.length()-2);
}

int main() {
    int arr[] = {10, 5, 7, 9, 15, 6, 11, 8, 12, 2};
    cout << minDiffPairs(arr, 10);
    return 0;
}