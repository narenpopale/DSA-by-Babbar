// Search an Element k in a Sorted & Rotated array using Binary Search

#include <iostream>
using namespace std;

int main()
{

    int n, k;

    cin >> n >> k;

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int s = 0,e = n-1;

    int mid = s + (e - s)/2;

    while (s<e)
    {
        if(arr[0] <= arr[mid]){
            s = mid+1;
        }

        if (arr[mid] <= arr[n-1])
        {
            e = mid;
        }

        mid = s + (e - s)/2;
        
    }
    
    int pivot = s;

    if (arr[pivot] <= k && k <= arr[n-1])
    {
        s = pivot,e = n-1;

        mid = s + (e - s)/2;

        while (s<=e)
        {
            if(arr[mid] == k){
                cout << mid <<endl;
                break;
            }
            else if(arr[mid] > k){
                e = mid - 1;
            }
            else{
                s = mid + 1;
            }

            mid = s + (e - s)/2;
        }
        
    }
    else{
        s = 0,e = pivot-1;

        mid = s + (e - s)/2;

        while (s<=e)
        {
            if(arr[mid] == k){
                cout << mid <<endl;
                break;
            }
            else if(arr[mid] > k){
                e = mid - 1;
            }
            else{
                s = mid + 1;
            }

            mid = s + (e - s)/2;
        }
    }
    

    return 0;
}