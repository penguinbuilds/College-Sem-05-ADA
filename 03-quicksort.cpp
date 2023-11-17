// quicksort

#include <iostream>
using namespace std;

void details() {
    cout << "Name: Shaaswat K Jha" << endl;
    cout << "Enrollment No: A2305221208" << endl;
}

void swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}

void printArray(int array[], int size) {
  int i;
  for (i = 0; i < size; i++)
    cout << array[i] << " ";
  cout << endl;
}

int partition(int array[], int low, int high) {
    
  int pivot = array[high];
  
  int i = (low - 1);

  for (int j = low; j < high; j++) {
    if (array[j] <= pivot) {
      i++;
      
      swap(&array[i], &array[j]);
    }
  }
  
  swap(&array[i + 1], &array[high]);
  
  return (i + 1);
}

void quickSort(int array[], int low, int high) {
  if (low < high) {

    int pi = partition(array, low, high);

    quickSort(array, low, pi - 1);

    quickSort(array, pi + 1, high);
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

    quickSort(arr, 0, length - 1);

    cout << "Sorted Array:" << endl;

    for (int i = 0; i < length; i++)
    {
        cout << arr[i] << " ";
    }
    
    cout << endl;
    
    return 0;
}