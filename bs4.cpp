// Find square root of a given number n using binary search.

#include<iostream>
using namespace std;

// function for finding the square root of a number without precision

int findSqrt(int n){
    int s = 0,e = n,ans = 0;

    int mid = s + (e-s)/2;

    while (s<=e)
    {
        if (mid*mid == n)
        {
            return mid; 
        }

        if (mid*mid < n)
        {
            ans = mid;
            s = mid + 1;
        }
        
        if (mid*mid > n)
        {
            e = mid - 1;
        }

        mid = s + (e-s)/2;        
    }
    
    return ans;
}

// function for finding the square root of a number with precision

double morePrecision(int n, int precision, int tempSol) {
    
    double factor = 1;
    double ans = tempSol;

    for(int i=0; i<precision; i++) {
        factor = factor/10;

        for(double j=ans; j*j<n; j= j+factor ){
            ans = j;
        }
    }
    return ans;
}

int main() {
    int n;
    cout <<" Enter the number " << endl;
    cin >> n;

    int tempSol = sqrtInteger(n);
    cout <<" Answer is " << morePrecision(n, 3, tempSol) << endl;

    return 0;
}
