#include <message.h>
#include <stdio.h>
#include "again.h"

#define MASTER_NODE 0
#define SENDING_DONE -1
#define LARGE_PRIME 1000000007

int main() {
  if (MyNodeId() == MASTER_NODE) {
    long long result = 0;
    for (int node = 1; node < NumberOfNodes(); ++node) {
      while (true) {
        Receive(node);
        long long value = GetLL(node);
        if (value == SENDING_DONE) {
          break;
        } else {
          result = (result + value) % LARGE_PRIME;
        }
      }
    }
    printf("%lld\n", result);
    return 0;
  } else {
    long long res = 0;
    long long NUM=NumberOfNodes(), MY=MyNodeId(), N=GetN();

    for (long long i = 0; i < N; ++i) {
      long long idx;
      if(i%NUM<=MY) idx=MY-i%NUM;
      else idx = (NUM+MY-i%NUM)%NUM;
      for (long long j = idx; j < N; j+=NUM) {
        long long value = GetA(i) * GetB(j);
        if ((i + j) % NUM == MY) {
          res += value;
        }
      }
    }
    PutLL(MASTER_NODE, res);
    Send(MASTER_NODE);
    PutLL(MASTER_NODE, SENDING_DONE);
    Send(MASTER_NODE);
  }
  return 0;
}
