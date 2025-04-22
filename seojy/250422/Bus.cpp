#include <iostream>

int main()
{
  bool negCycle = false;
  for (auto &e : edges) 
  {
    if (dist[e.u] != INF && dist[e.u] + e.w < dist[e.v]) {
      negCycle = true;
      break;
    }
  }
}
