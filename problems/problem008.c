#include <math.h>
#include <string.h>
#include "utils.h"
/// @file
/// Implementation of Project Euler Problem 8
///
/// @addtogroup Problem
/// @{
// -----------------------------------------------------------------------------
/**
  @brief Find the greatest product of n consecutive digits in the 1000 digit
           number

  @param[in] n         number of consecutive digits
  @param[out] product  greatest product of n consecutive digits

  @return An error code: 0 - success, otherwise - failure
**/
// -----------------------------------------------------------------------------
int problem008(int n, long *product) {
  FILE *stream;
  long bestProd = 0;
  char oneKdigits[1001];

  // Open file
  stream = fopen("data/1000digit.txt", "r");

  // Get number from file
  if(stream != NULL) {
    fgets(oneKdigits, sizeof(oneKdigits), stream);

    // Close
    fclose(stream);
  } else {
    // LCOV_EXCL_START
    return 1;
    // LCOV_EXCL_STOP
  }

  // Check products of consecutive numbers
  for (int i = 0; i < 1000 - n; i++) {
    // Find product
    long prod = 1;
    for (int j = 0; j < n; j++) {
      int nextDigit = oneKdigits[i+j] - '0'; 
      prod *= nextDigit;
    }

    // Compare
    if (prod >= bestProd)
      bestProd = prod;
  }

  // Save result
  *product = bestProd;

  return 0;
};
// -----------------------------------------------------------------------------
/// @}
///
/// @addtogroup Interface
/// @{
// -----------------------------------------------------------------------------
/**
  @brief: Project Euler Problem 8

  The four adjacent digits in the 1000-digit number that have the greatest
    product are 9 × 9 × 8 × 9 = 5832.

  Find the thirteen adjacent digits in the 1000-digit number that have the
    greatest product. What is the value of this product?
**/
// -----------------------------------------------------------------------------
int problem008CL(FILE *stream) {
  int n;
  long product;

  // Get a and limit from user
  printf("    This code finds the greatest product of [n] adjacent digits in\n"
         "      the 1000 digit number in data/1000digit.txt\n\n");
  getValidUserInt("      Enter n: ", stream, 1, 1000, &n);

  // Find lcm
  problem008(n, &product);

  printf("    The greatest product of %d consecutive digits is: %ld\n\n",
         n, product);

  return 0;
};
// -----------------------------------------------------------------------------
/// @}
