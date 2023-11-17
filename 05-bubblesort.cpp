// bubblesort

#include <iostream>
using namespace std;

void details() {
    cout << "Name: Shaaswat K Jha" << endl;
    cout << "Enrollment No: A2305221208" << endl;
}

void bubbleSort(int array[], int length) {

  for (int i = 0; i < length; i++) {
      
    for (int j = 0; j < length - i; j++) {

      if (array[j] > array[j + 1]) {

        int temp = array[j];
        array[j] = array[j + 1];
        array[j + 1] = temp;
      }
    }
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

    bubbleSort(arr, length);

    cout << "Sorted Array:" << endl;

    for (int i = 0; i < length; i++)
    {
        cout << arr[i] << " ";
    }
    
    cout << endl;
    
    return 0;
}