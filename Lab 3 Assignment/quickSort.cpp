#include<bits/stdc++.h>
#include<stdlib.h>
using namespace std;

int num[100];

void quickSort(int f , int l)
{
    if(f < l)
    {
        int i , j;
        i = f+1;
        j = l;
        while (num[i] < num[f])
        {
            i++;
        }
        while(num[j] > num[f])
        {
            j--;
        }
        while(i < j)
        {
            swap(num[i] , num[j]);
            while (num[i] < num[f])
            {
                i++;
            }
            //j = l;
            while(num[j] > num[f])
            {
                j--;
            }
        }
        swap(num[j] , num[f]);
        quickSort(f , j-1);
        quickSort(j+1 , l);
    }
}
int main()
{
    int n;
    cout << "Enter the number of numbers to sort : ";
    cin >> n;

    for(int i = 0 ; i < n ; i++)
        num[i] = rand()%1000;

    cout << "The Unsorted Numbers : ";
    for(int i = 0 ; i < n ; i++)
        cout << num[i] << " ";

    cout << endl;

    quickSort(0 , n-1);

    cout << "The Sorted Numbers : ";
    for(int i = 0 ; i < n ; i++)
        cout << num[i] << " ";


}


