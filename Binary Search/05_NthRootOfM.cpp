#include <cmath>

int power(int mid, int n, int m){
  long long ans = 1;
  for(int i=1; i<=n; i++){
    ans = ans * mid;
    if(ans > m) return 2;
  }
  if(ans == m) return 1;
  return 0;
}

int NthRoot(int n, int m) {
  int low = 1;
  int high = m;

  while(low <= high){
    int mid = (high + low)/2;
    int ans = power(mid, n, m);
    if(ans == 1){
      return mid;
    }
    else if(ans == 0){
      low = mid + 1;
    }
    else{
      high = mid - 1;
    }
  }
  return -1;
}