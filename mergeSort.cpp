#include <iostream>
#include <vector>
#include <random>
#include <ctime>
#include <algorithm>

using namespace std;

void merge(vector<int>& arr, int left, int mid, int right){
    int n1 = mid - left + 1; 
    int n2 = right - mid; 

    vector<int> LArr(n1);
    vector<int> RArr(n2);

    //set subarrays
    for(int i = 0; i < n1; i++){
        LArr[i] = arr[left + i];
    }

    for(int j = 0; j < n2; j++){
        RArr[j] = arr[mid + 1 + j];
    }

    int i = 0; 
    int j = 0;
    int k = left;

    ///merge sub arrays back in
    while(i < n1 && j < n2){
        if(LArr[i] <= RArr[j]){
            arr[k] = LArr[i];
            i++;
        }else{
            arr[k] = RArr[j];
            j++;
        }
        
        k++;
    }

    //copy the rest of the subarrays if needed
    while(i < n1){
        arr[k] =  LArr[i];
        i++;
        k++;
    }

    while(j < n2){
        arr[k] =  RArr[j];
        j++;
        k++;
    }
}


void mergeSort(vector<int>& arr, int size){
    int currSize;
    int left;

    for(currSize = 1; currSize <= size-1; currSize = 2 * currSize){
        for(left = 0; left < size - 1; left += 2 * currSize){
            int mid = min(left + currSize - 1, size - 1); 
            int right = min(left + 2 * currSize - 1, size - 1); 
            merge(arr, left, mid, right);
        }
    }
}

void genVector(vector<int>& arr, int size){
    for(int i = 0; i < size; i++){
         int num = rand() % 51;

        arr.push_back(num);
    }
}

int main(){
    for(int i = 0; i < 10; i++){
        clock_t start = clock();
        vector<int> arr;
        int size = pow(10, i);

        genVector(arr, size);
        vector<int> arr2 = arr;  // Copy arr into arr2

        mergeSort(arr, arr.size());
        clock_t end = clock();

        double duration = (double)(end - start) / CLOCKS_PER_SEC;
        cout << "Time taken by function: " << duration << " seconds" << endl;
    }

    return 0;
}