// selectionsort

#include <iostream>
using namespace std;

void details() {
    cout << "Name: Shaaswat K Jha" << endl;
    cout << "Enrollment No: A2305221208" << endl;
}

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void selectionSort(int array[], int length) {
  for (int i = 0; i < length - 1; i++) {
    int min_idx = i;
    for (int j = i + 1; j < length; j++) {

      if (array[j] < array[min_idx])
        min_idx = j;
    }

    swap(&array[min_idx], &array[i]);
  }
}

int main()
{
    int length;
    int target;

    details();

    cout << "Enter length of array: ";
    cin >> length;

    int arr[length];

    for (int i=0; i < length; i++) {
        cout << "Enter element: ";
        cin >> arr[i];
    }

    selectionSort(arr, length);

    cout << "Sorted Array:" << endl;

    for (int i = 0; i < length; i++)
    {
        cout << arr[i] << " ";
    }
    
    cout << endl;
    
    return 0;
}