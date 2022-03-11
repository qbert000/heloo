#include <iostream>
using namespace std;

int ham3phan(int* a, int x, int i, int j) {
  
    if(x==a[i+(j-i)/3]) return i+(j-i)/3;
    else if(x== a[j-(j-i)/3]) return j-(j-i)/3;
    else if(x<a[i+(j-i)/3]) j = i+(j-i)/3;
    else if(x>a[j-(j-i)/3]) i = j-(j-i)/3;
    else {
      int k =i;
      i = i+(j-i)/3;
      j = j-(j-i)/3;
    }
  return ham3phan(a,x,i,j);
}


int main() {
  int n;
  cin >> n;
  int* a = new int[n];
  for(int i=0; i<n; i++) {
    cin >> a[i];
  }
int x;
  cin >> x;
  cout << ham3phan(a,x,0,n-1);
  return 0;

}