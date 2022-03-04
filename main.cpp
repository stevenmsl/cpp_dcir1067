#include <iostream>
#include <tuple>
#include <vector>
#include <string>
#include "solution.h"
#include "util.h"

using namespace std;
using namespace sol1067;

/*
Example 1:
Input: d = 1, low = 1, high = 13
Output: 6
*/
tuple<int, int, int, int>
testFixture1()
{
  return make_tuple(1, 1, 13, 6);
}

/*
Example 2:
Input: d = 3, low = 100, high = 250
Output: 35
Explanation:
The digit d=3 occurs 35 times in 103,113,123,130,131,…,238,239,243.
*/
tuple<int, int, int, int>
testFixture2()
{
  return make_tuple(3, 100, 250, 35);
}

void test1()
{
  auto f = testFixture1();
  cout << "Test 1 - exepct to see " << to_string(get<3>(f)) << endl;
  Solution sol;
  auto result = sol.countDigits(get<0>(f), get<1>(f), get<2>(f));
  cout << "result: " << result << endl;
}

void test2()
{
  auto f = testFixture2();
  cout << "Test 2 - exepct to see " << to_string(get<3>(f)) << endl;
  Solution sol;
  auto result = sol.countDigits(get<0>(f), get<1>(f), get<2>(f));
  cout << "result: " << result << endl;
}

/*
  - calling a function (print) inside a function (loop)
    will confuse the debugger when using F10 to
    debug the code even though the result is
    correct
*/
void testWired()
{
  auto limit = 1;
  auto upper = 5;
  auto print = []()
  {
    cout << "printed!";
  };
  auto loop = [&]()
  {
    for (auto i = 0; i <= upper; i++)
    {
      if (i == upper && limit)
      {
        cout << "reach upper";
        print();
      }
      else
      {
        cout << to_string(i);
        print();
      }
    }
  };

  loop();
}

void test250()
{
  for (auto i = 1; i < 250; i++)
  {
    
  }
}

main()
{
  // test1();
  test2();
  //   testWired();
  return 0;
}