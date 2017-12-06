#include<bits/stdc++.h>
using namespace std;

void divide(int arr[] , int low , int high);
void mergeArray(int arr[] , int low , int mid , int high);

int main()
{
    int n;

    cin >> n;
    int arr[n];
    for(int i = 0 ; i < n ; i++)
        arr[i] = rand()%100;
        //cin >> arr[i];
    cout << "Given Array : ";
    for(int i = 0 ; i < n ; i++)
    {
        cout << arr[i] << " ";
    }

    divide(arr , 0 , n-1);
    cout << endl;
    cout << "Sorted Array : ";
    for(int i = 0 ; i < n ; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}

void divide(int arr[] , int low , int high)
{
    /// if element is more than 1 no need to divide
    if(low < high)
    {
        int mid = (low+high)/2;
        divide(arr , low , mid);
        divide(arr , mid+1 , high);
        ///merge the array with sorting
        mergeArray(arr , low , mid , high);
    }
}

void mergeArray(int arr[] , int low , int mid , int high)
{
    int i = low;
    int j = mid+1;
    int k = 0;
    int temp[high - low];
    while( i<= mid && j <= high)
    {
        if(arr[i]<arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }

    ///For copying the rest of the array we dont know for
    ///which condition it ended so we copied both with condition for which only one will be coppied
    while(i<=mid)
        temp[k++] = arr[i++];
    while(j<=high)
        temp[k++] = arr[j++];


    ///we took low as we want to work on the particular part of the array
    /// 2 -1 3 -5
    /// 0 1     2 3
    /// low high low high
    for(int i = 0 ; i < k ; i++)
        arr[low++] = temp[i];
}
