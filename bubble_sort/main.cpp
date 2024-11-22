#include <iostream>
using namespace std;

void _swap(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}

void bubble_sort(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                _swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void selection_sort(int arr[], int size)
{
    for(int i = 0; i < size; i++)
    {
        for(int i = 0; i < size; i++)
        {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
        int min_index = i;
        for(int j = i + 1; j < size; j++)
        {
            if(arr[min_index] > arr[j])
            {
                _swap(arr[min_index], arr[j]);
            }
        }

    }
}


void quickSort(int *arr, int l, int r) {

    if (l >= r) return;

    int i = l, j = r;

    int X = arr[0];

    while (i < j) {
        while (arr[i] < X) i++;
        while (arr[j] > X) j--;
        if (i <= j) swap(arr[i++], arr[j--]);
    }
    for(int k = i; k <= r; k++) cout<<arr[k]<<" ";
    for(int h = l; h <= j; h++) cout<<arr[h]<<" "<<endl;
    quickSort(arr, i, r);
    quickSort(arr, l, j);
}



int main()
{
    int arr[12] = {240, 73, 101, 21, 13, 25, 11, 37, 89, 30, 15, 51};
    int size = sizeof(arr) / sizeof(arr[0]);
    quickSort(arr, 240, 51);

    return 0;
}
