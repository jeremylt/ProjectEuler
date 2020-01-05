#include <math.h>
#include "utils.h"
/// @file
/// Implementation of Project Euler Problem 3
///
/// @addtogroup Problem
/// @{
// -----------------------------------------------------------------------------
/**
  @brief Find the largest prime factor of a number

  @param[in] number  number to find factor of
  @param[out] factor largest prime factor

  @return An error code: 0 - success, otherwise - failure
**/
// -----------------------------------------------------------------------------
int problem3(long number, long *factor) {
  bool prime = false;
  long bound = floor(sqrt((double)number));
  *factor = 0;

  // Find factor
  for (long i = bound; i > 1; i--) {
    // Check if factor
    if (!(number % i))
      // Check if prime
      isPrimeLong(i, &prime);

    // Save result if prime
    if (prime) {
      *factor = i;
      break;
    }
  }

  return 0;
};
// -----------------------------------------------------------------------------
/// @}
///
/// @addtogroup Interface
/// @{
// -----------------------------------------------------------------------------
/**
  @brief: Project Euler Problem 3

  The prime factors of 13195 are 5, 7, 13 and 29.

  What is the largest prime factor of the number 600851475143 ?
**/
// -----------------------------------------------------------------------------
int problem3CL(void) {
  long number, factor;

  // Get a and limit from user
  printf("    This code finds the largest prime factor of a [number].\n\n");
  getUserLong("      Enter number: ", &number);

  // Find sum of multiples
  problem3(number, &factor);

  printf("    The largest prime factor of %ld: %ld\n\n",
         number, factor);

  return 0;
};
// -----------------------------------------------------------------------------
/// @}