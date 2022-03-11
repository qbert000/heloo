#include <iostream>
using namespace std;

void print(int* a, int n) {
  for(int i=0; i<n; i++) {
    cout << a[i] << " " ;
  }
  cout << endl;
}

int binaryinsert(int a[], int item, int low, int high) {
  if(high == low) {
    return (a[high] > item ) ? high: high +1;
  }
  int mid = (low + high+1) /2;
  if(item > a[mid]) {
    return binaryinsert(a,item, mid, high);
    }
  else if(item == a[mid]) {
    return mid +1 ;
    }
  return binaryinsert(a, item, low, mid -1);
}

void sort(int* a,int n) {
  int lock, pop;
  for(int i =1; i<n; i++) {
    int j =i;
    pop = a[i];
    lock = binaryinsert(a,a[i], 0, i-1);
    while(j>lock) {
      a[j] = a[j-1];
      j--;
    }
    a[lock] = pop;
    print(a,n);
  }
}

int main() {
    int n;
    cin >> n;
    int* a = new int[n];
    for(int i=0; i<n; i++ ) {
        cin >> a[i];
    }
    sort(a,n);
    return 0;
}