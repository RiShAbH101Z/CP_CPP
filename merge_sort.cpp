//merge sort O(NlogN)
#include <iostream>

using namespace std;

void merge(int arr[], int start, int mid, int end){
    int s1=(mid-start)+1, s2=(end-mid), l[s1], r[s2];
    for(int i=0; i<s1; i++) l[i]=arr[i + start];
    for(int i=0; i<s2; i++) r[i]=arr[i + mid + 1];
    int p1=0, p2=0, p3=start;
    while(p1<s1 && p2<s2)   (l[p1]<r[p2])?arr[p3++]=l[p1++]:arr[p3++]=r[p2++];
    while(p1<s1)  arr[p3++]=l[p1++];
    while(p2<s2) arr[p3++]=r[p2++];
}

void merge_sort(int arr[], int start, int end){
    if(start >= end) return;
    int mid = (start+end)/2;
    merge_sort(arr, start, mid);
    merge_sort(arr, mid+1, end);
    merge(arr, start, mid, end);
}

int main(){
    int n=10;
    int arr[n] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    merge_sort(arr, 0, n-1);
    for(int i=0; i<n; i++) cout<<arr[i]<<" ";
    return 0;
}
