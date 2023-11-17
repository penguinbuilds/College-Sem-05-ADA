// insertionsort

#include <iostream>
using namespace std;

void details() {
    cout << "Name: Shaaswat K Jha" << endl;
    cout << "Enrollment No: A2305221208" << endl;
}

void insertionSort(int array[], int length) {
  for (int i = 1; i < length; i++) {
    int key = array[i];
    int j = i - 1;

    while (key < array[j] && j >= 0) {
      array[j + 1] = array[j];
      --j;
    }
    array[j + 1] = key;
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

    insertionSort(arr, length);

    cout << "Sorted Array:" << endl;

    for (int i = 0; i < length; i++)
    {
        cout << arr[i] << " ";
    }
    
    cout << endl;
    
    return 0;
}