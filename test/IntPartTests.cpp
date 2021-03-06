#include <gtest/gtest.h>
#include "../Intpart.hpp"

TEST(ExampleTests__IntPart_Part, IntPart)
{
  EXPECT_EQ(IntPart::part(1), "Range: 0 Average: 1.00 Median: 1.00");
  EXPECT_EQ(IntPart::part(2), "Range: 1 Average: 1.50 Median: 1.50");
  EXPECT_EQ(IntPart::part(3), "Range: 2 Average: 2.00 Median: 2.00");
  EXPECT_EQ(IntPart::part(4), "Range: 3 Average: 2.50 Median: 2.50");
  EXPECT_EQ(IntPart::part(8), "Range: 17 Average: 8.29 Median: 7.50");
  EXPECT_EQ(IntPart::part(50), "Range: 86093441 Average: 1552 Median: 1209");
}

TEST(ExampleTests__Intpar__Enumerate, IntPart)
{
  std::vector<std::vector<long long>> partitions{{4}, {3, 1}, {2, 2}, {2, 1, 1}, {1, 1, 1, 1}};
  EXPECT_EQ(IntPart::enumerate(4), partitions);
}

TEST(ExampleTests__Intpar__Enumerate_5, IntPart)
{
  std::vector<std::vector<long long>> partitions{{5}, {4, 1}, {3, 2}, {3, 1, 1}, {2, 2, 1}, {2, 1, 1, 1}, {1, 1, 1, 1, 1}};
  EXPECT_EQ(IntPart::enumerate(5), partitions);
}

TEST(ExampleTests__Intpar__Enumerate_6, IntPart)
{
  std::vector<std::vector<long long>> partitions{{6}, {5, 1}, {4, 2}, {4, 1, 1}, {3, 3}, {3, 2, 1}, {3, 1, 1, 1}, {2, 2, 2}, {2, 2, 1, 1}, {2, 1, 1, 1, 1}, {1, 1, 1, 1, 1, 1}};
  EXPECT_EQ(IntPart::enumerate(6), partitions);
}