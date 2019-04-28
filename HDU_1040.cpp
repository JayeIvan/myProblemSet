#include <iostream>
#include <cstdlib>
#include <algorithm>

using namespace std;

int main(){
    int t,n;
    int *arr;
    cin >> t;
    while(t--){
        cin >> n;
        arr = (int *)malloc(n*sizeof(int));

        for(int i=0;i<n;i++)
            cin >> arr[i];

        sort(arr,arr+n);

        for(int i=0;i<n-1;i++)
            cout << arr[i] << " ";

        cout << arr[n-1];
        cout << endl;
    }
    return 0;
}
