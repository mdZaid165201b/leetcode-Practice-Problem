#include <iostream>
using namespace std;

int reverseInteger(int n){
  int value = 0;
  int rem;
  while(n != 0) {
    rem = n % 10;
    value = value * 10 + rem;
    n /= 10;
  }
}

int main() {

  cout << "Reversed Number : "<<reverseInteger(12345);

  return 0;
}
