// linear search

#include <iostream>
using namespace std;

void details() {
    cout << "Name: Shaaswat K Jha" << endl;
    cout << "Enrollment No: A2305221208" << endl;
}

int linearSearch(int array[], int target) {
    for (int i = 0; i < 10; i++)
    {
        if (array[i] == target)
        {
            return i;
        }    
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

    int res = linearSearch(arr, target);
    // Complexity: O(n)

    if (res == -1)
    {
        cout << "Element not found!" << endl;
    } else {
        cout << "Element found at index position " << res << "." << endl;
    }
    
    return 0;
}