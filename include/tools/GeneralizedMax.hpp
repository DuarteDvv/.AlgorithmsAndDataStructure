#ifndef GEN_MAX
#define GEN_MAX

#include <iostream>
#include <algorithm>

// Base case: When only one argument is provided, return it
template <typename T>
T max(T n)
{
   return n;
}

// Recursive case: Compare the first element with the maximum of the rest
template <typename T, typename... Args>
T max(T n, Args... args)
{
   T maxOfRest = max(args...);
   return std::max(n, maxOfRest);
}

int main()
{
   std::cout << max(1, 5, 3, 7, 2) << std::endl;  // Output: 7
   std::cout << max(10, 20, 30, 25) << std::endl; // Output: 30
   std::cout << max(7) << std::endl;              // Output: 7
   return 0;
}

#endif