// binary search with recursive method (binary search requires array to be sorted)

#include <iostream>
using namespace std;

void details() {
    cout << "Name: Shaaswat K Jha" << endl;
    cout << "Enrollment No: A2305221208" << endl;
}

int binarySearchWithRecursion(int array[], int x, int low, int high) {

    if (high >= low) {
    int mid = (low + high) / 2;

    if (array[mid] == x)
      return mid;

    if (array[mid] > x)
      return binarySearchWithRecursion(array, x, low, mid - 1);

    return binarySearchWithRecursion(array, x, mid + 1, high);
  }

  return -1;
}

int main()
{
    int length;
    int target;

    details();

    cout << "Enter length of array: ";
    cin >> length;
    
    cout << "Enter target element: ";
    cin >> target;

    int arr[length];

    for (int i=0; i < length; i++) {
        cout << "Enter element: ";
        cin >> arr[i];
    }
        
    int res = binarySearchWithRecursion(arr, target, 0, length);
    // Complexity: O(logn)

    if (res == -1)
    {
        cout << "Element not found!" << endl;
    } else {
        cout << "Element found at index position " << res << "." << endl;
    }
    
    return 0;   
}