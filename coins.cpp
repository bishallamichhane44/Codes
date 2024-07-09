#include <iostream>
#include <vector>

int countCombos(int target, const std::vector<int>& denoms) {
  std::vector<int> combos(target + 1, 0);
  combos[0] = 1; // One way to make 0: no coins

  for (int denom : denoms) {
    for (int curr = denom; curr <= target; ++curr) {
      combos[curr] += combos[curr - denom];
    }
  }

  return combos[target];
}

int main() {
  int targetPence = 200; // £2 in pence
  std::vector<int> denoms = {1, 2, 5, 10, 20, 50, 100, 200};

  int numCombos = countCombos(targetPence, denoms);

  std::cout << "Number of ways to make 2 pound : " << numCombos << std::endl;

  return 0;
}
