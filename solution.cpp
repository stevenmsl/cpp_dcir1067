#include "solution.h"
#include "util.h"
#include <queue>
#include <map>
#include <algorithm>
#include <string>
#include <queue>
#include <sstream>
#include <functional>
#include <math.h>

using namespace sol1067;
using namespace std;

/*takeaways
  - let see how many 3's from 1..250
    - step 1: 25|0
      - if the very last digit is 3, how many
        combinations can we generate?
      - we can produce the following numbers:
        3,13,23,33...243 - should be 25 of them
      - you can look at it this way
        [0]3,[1]3,[2]3,...[24]3
      - so you are picking a number from this
        range [0..24] and place it before 3
      - there are 25 different ways to pick
        a number
    - step 2: 2|50
      - if the second to the last digit is 3
      - before the digit you have [0..1] to choose
        from. After the digit you have [0..9] to
        choose from. In total the number of
        combinations is 2x10 = 20
      - the numbers produced are
        30,31,32,33...,39,130,131,132,133...139
      - or [0]3[0],[0]3[1],[0]3[2],[0]3[3]...,[0]3[9],[1]3[0],[1]3[1],[1]3[2],[1]3[3]...[1]3[9]
        to show how the combinations are generated
      - you might notice that 33 and 133 both are a duplicate from before. This is
        fine as we need to count them twice as there are two 3's in them.
      - so what are still missing?
      - we are missing 230,231,232,233...239. 10 in total, which are not covered
        in step 1!
      - if the number is 234 instead of 250, then the numbers are
        230,231,232,233,234
      - so that's why the total number for this part is define as
        min (50-3x10 + 1, 10) = 10 in the case of 250
        or
        min (34-3x10 +1, 10) = 5 in the case of 250

  - let see how many 0's from 1..250
    - step 1 (the very last digit is 0)
      - 00,20,30...250
      - total combinations are 25-1=24 as we need to rule out 0
    - step 2 (second to the last digit is 0)
      - 000,001,002...009 should not be included
      - 100,101...109 are fine
      - so total combinations = 2x10 - 10 = 10
      - the number of leftover combinations should be 10 as well:
        200,201...209
*/

int Solution::countDigits(int d, int low, int high)
{
  function<int(int)> visit = [&](int n)
  {
    int count = 0;

    /*
      - start from the very last digit. If the very
        last digit is '3' for example, check how many
        combinations we can generate.
      - then move on to the second to the last digit
        and assume it's 3
    */
    for (int pow10 = 1; pow10 <= n; pow10 *= 10)
    {
      const int divisor = pow10 * 10;
      const int quotient = n / divisor;
      const int remainder = n % divisor;

      if (quotient > 0)
        count += quotient * pow10;
      /* to remove the cases like [0]0
         or [0]0[0],[0]0[1],[0]0[2]
      */
      if (d == 0)
        count -= pow10;
      /*
        - example 250, d=3
        - these are the leftover between [230..239]
          when the 3 is on the second to the last
          digit
      */
      if (remainder >= d * pow10)
        count += min(remainder - d * pow10 + 1, pow10);
    }

    return count;
  };

  return visit(high) - visit(low - 1);
}