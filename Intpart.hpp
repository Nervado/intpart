#ifndef INTPART_HPP
#define INTPART_HPP

typedef std::vector<long long> partition_n;
typedef std::vector<partition_n> partitions;

class IntPart
{
public:
  static std::string part(long long n);
  static double median(std::vector<long long> v);
  static double average(std::vector<long long> v);
  static partitions enumerate(long long n);
  static void printArray(partition_n p);
  static partition_n product(partitions p);
  static long long sum(partition_n p);
  static partition_n sortAndRemoveDuplicates(partition_n p);
  IntPart() {}
};

#endif /* INTPART_HPP */