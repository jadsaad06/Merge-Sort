#include <bits/stdc++.h>

using namespace std;

void merge(vector<int> arr, int left, int mid, int right){
    int n1 = mid - left + 1; //array 1 size
    int n2 = right - mid; //array 2 size

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

    //if subarrays are odd, copy the rest
    while(i < n1){
        arr[k] =  LArr[i];
        i++;
        k++;
    }

    while(j < n2){
        arr[k] =  LArr[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int> arr, int size){
    int currSize;
    int left;

    for(currSize = 1; currSize <= size-1; currSize = 2 * currSize){ // start small, double size everytime

        for(left = 0; left < size-1; left += 2 * currSize){
            int mid = min(left + currSize - 1, size);
            int right = min(left + 2 * currSize - 1, size);

            merge(arr, left, mid, right);
        }
    }
}

int main(){
    vector<int> arr = {9,6,7,8,2,3,4,1,5,0};

    return 0;
}