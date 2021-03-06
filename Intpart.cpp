#include <math.h>
#include <iostream>
#include <vector>
#include "Intpart.hpp"

using namespace std;

string IntPart::part(long long n)
{
  string result;
  long long range;
  float average;
  float median;

  if (n <= 1) // trivial cases: enum(0) => [[0]] enum(1) => [[1]];
  {
    range = 0;
    average = n;
    median = n;

    return "Range: " + to_string(range) + " Average: " + to_string(average).substr(0, 4) + " Median: " + to_string(average).substr(0, 4);
    std::cout.precision(5);
  }

  vector<partitions> memoize;
  partition_n pn(1, 0);
  partitions p0(1, pn);
  pn[0] = 1;
  partitions p1(1, pn);

  memoize.push_back(p0); // memoise enum(1) => [[1]]
  memoize.push_back(p1); // memoise enum(1) => [[1]]

  long long order = 2;

  while (order <= n)
  {
    partitions current_partitions;
    long long current = order - 1;
    current_partitions.push_back(partition_n(1, order));
    while (current >= 1)
    {
      for (partition_n x : memoize[order - current])
      {
        if (x[0] <= current & x[0] > 0)
        {
          partition_n newPartition;
          newPartition.push_back(current);
          for (long long el : x)
            newPartition.push_back(el);
          current_partitions.push_back(newPartition);
        }
      }
      current--;
    }
    memoize.push_back(current_partitions);
    order++;
  }

  partition_n products = product(memoize[n]);
  result = "Range: " + to_string(products[products.size() - 1] - products[0]) + " Average: " + to_string(IntPart::average(products)).substr(0, 4) + " Median: " + to_string(IntPart::median(products)).substr(0, 4);
  return result;
}

long long IntPart::sum(partition_n p)
{
  long long sum = 0;
  for (long long el : p)
  {
    sum += el;
  }
  return sum;
}

double IntPart::average(std::vector<long long> v)
{
  double average = 0;
  double size = v.size();
  for (long long x : v)
  {
    average += x;
  }
  return average / size;
}

double IntPart::median(std::vector<long long> v)
{
  double median = 0;
  long long i = 0;
  if (v.size() % 2 == 1)
  {
    i = (v.size() - 1) / 2;
    return v[i];
  }
  i = v.size() / 2;
  median = (v[i] + v[i - 1]) / 2.0;
  return median;
}

partition_n IntPart::sortAndRemoveDuplicates(partition_n p)
{
  partition_n sorted;
  partition_n sortedAndNoDuplicates;

  sort(p.begin(), p.end());

  sortedAndNoDuplicates.push_back(p[0]);

  for (long long i = 1; i < p.size(); i++)
  {
    if (p[i] != p[i - 1])
      sortedAndNoDuplicates.push_back(p[i]);
  }
  return partition_n(sortedAndNoDuplicates.begin(), sortedAndNoDuplicates.end());
}

void IntPart::printArray(partition_n p)
{
  long long k = 0;
  cout << "{ ";
  while (k < p.size())
  {
    cout << p[k];
    k++;

    if (k < p.size())
    {
      cout << " , ";
    }
  }
  cout << " }";
}

partition_n IntPart::product(partitions p)
{
  partition_n r;
  partition_n result;

  for (partition_n n : p)
  {
    long long acc = 1;
    for (long long el : n)
    {
      acc *= el;
    }
    r.push_back(acc);
  }

  result = sortAndRemoveDuplicates(r);
  return partition_n(result.begin(), result.end());
}

partitions IntPart::enumerate(long long n)
{
  string result;
  long long range;
  float average;
  float median;

  if (n <= 1) // trivial cases: enum(0) => [[0]] enum(1) => [[1]];
  {
    partition_n p(1, n);
    return partitions(1, p);
  }

  vector<partitions> memoize;
  partition_n pn(1, 0);
  partitions p0(1, pn);
  pn[0] = 1;
  partitions p1(1, pn);

  memoize.push_back(p0); // memoise enum(1) => [[1]]
  memoize.push_back(p1); // memoise enum(1) => [[1]]

  long long order = 2;

  while (order <= n)
  {
    partitions current_partitions;
    long long current = order - 1;
    current_partitions.push_back(partition_n(1, order));
    while (current >= 1)
    {
      for (partition_n x : memoize[order - current])
      {
        if (x[0] <= current & x[0] > 0)
        {
          partition_n newPartition;
          newPartition.push_back(current);
          for (long long el : x)
            newPartition.push_back(el);
          current_partitions.push_back(newPartition);
        }
      }
      current--;
    }
    memoize.push_back(current_partitions);
    order++;
  }

  partition_n products = product(memoize[n]);

  return partitions(memoize[n].begin(), memoize[n].end());
}
