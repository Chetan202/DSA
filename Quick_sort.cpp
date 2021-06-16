//https://www.geeksforgeeks.org/quick-sort/
#include <iostream>
#include <bits/stdc++.h>
#include <iostream>
#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

void swap(int* a,int* b){
	int t=*a;
	*a=*b;
	*b=t;
}

int partitioned(int arr[],int low,int high){
	int pivot = arr[high];
	int  i =(low-1); 
	for(int j=low;j<=high-1;j++){
		if(arr[j]<pivot){
			i++;
			swap(&arr[i],&arr[j]);
		}
	}
swap(&arr[i+1],&arr[high]);
return (i+1);
}

void quicksort(int arr[],int low,int high){
	if(low<high){
		int pi=partitioned(arr,low,high);
			quicksort(arr,low,pi-1);
			quicksort(arr,pi+1,high);
		
	}
}

void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}


int main() {
	int num;cin >> num;
    int arr[num];
	
	for(int i=0;i<num;i++){
		int n;cin>>n;
        arr[i] = n;
	}
    // int arr[] = {10, 7, 8, 9, 1, 5};
    // int num = sizeof(arr) / sizeof(arr[0]);
	quicksort(arr,0,num-1);
	
    printArray(arr, num);
    return 0;
	
}
