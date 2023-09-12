// Online C compiler to run C program online
#include <stdio.h>
#include <assert.h>

struct CountsBySoH {
  int healthy;
  int exchange;
  int failed;
};

// assuming all batteries have rated capacity of 120(given)
float ratedCapacity = 120.0; 

int healthyLimit = 80;
int exchangeLimit = 63;

float getSOH(int presentCapacity) {
    return 100.0*((float)presentCapacity/ratedCapacity);
}

struct CountsBySoH countBatteriesByHealth(const int* presentCapacities, int nBatteries) {
  struct CountsBySoH counts = {0, 0, 0};
  
  for(int i = 0; i < nBatteries; i++) {
      float soh = getSOH(presentCapacities[i]);
      
      // classification based on given criteria
      if(soh >= healthyLimit) {
          counts.healthy++;
      } else if(soh >= exchangeLimit) {
          counts.exchange++;
      } else {
          counts.failed++;
      }
  } 
  
  return counts;
}

void testBucketingByHealth() {
  const int presentCapacities[] = {115, 118, 80, 95, 91, 72};
  const int numberOfBatteries = sizeof(presentCapacities) / sizeof(presentCapacities[0]);
  
  // capacities cant be negative and more than rated capacity;
  for(int i = 0; i < numberOfBatteries; i++) {
      assert(presentCapacities[i] >= 0 && presentCapacities[i] <= ratedCapacity); 
  }
  
  printf("Counting batteries by SoH...\n");
  struct CountsBySoH counts = countBatteriesByHealth(presentCapacities, numberOfBatteries);
  assert(counts.healthy == 2);
  assert(counts.exchange == 3);
  assert(counts.failed == 1);
  printf("Done counting :)\n");
}

int main() {
  testBucketingByHealth();
  return 0;
}
