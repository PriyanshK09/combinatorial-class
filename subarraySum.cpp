#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    int sum;
    cin >> sum;
    int i=0, j=0, st=-1, en=-1, s=0;
    while(j<n && s+arr[j]<=sum){
        s += arr[j];
        j++;
    }
    if(s==sum){
        cout << i+1 << " " << j << endl;
        return 0;
    }
    while(j<n){
        s += arr[j];
        while(s>sum){
            s -= arr[i];
            i++;
        }
        if(s==sum){
            st = i+1;
            en = j+1;
            break;
        }
        j++;
    }
    cout << st << " " << en << endl;
    return 0;
}
