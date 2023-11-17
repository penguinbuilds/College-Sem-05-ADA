// binary search with iterative method (binary search requires array to be sorted)

#include <iostream>
using namespace std;

void details() {
    cout << "Name: Shaaswat K Jha" << endl;
    cout << "Enrollment No: A2305221208" << endl;
}

int binarySearch(int array[], int x, int low, int high) {
  
    while (low <= high) {
    int mid = (low + high) / 2;

    if (array[mid] == x)
        return mid;

    if (array[mid] < x)
        low = mid + 1;

    else
        high = mid - 1;
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
        
    int res = binarySearch(arr, target, 0, length); 
    // Complexity: O(logn)

    if (res == -1)
    {
        cout << "Element not found!" << endl;
    } else {
        cout << "Element found at index position " << res << "." << endl;
    }
    
    return 0;   
}