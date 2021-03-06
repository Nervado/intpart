## IntPart

This is a simple c++ project do calculate all partitions for a given interger N.

- Partition: https://en.wikipedia.org/wiki/Partition_(number_theory)

We use memoization to reduce the time of calculation.

All used methods are declare in the same haeader file.

To compile and run you must using some command like:

- Compile: <you_make_path>/bin/cmake --build <your_path>/intpart/build --config Release --target all -- -j 10

- Run: <path_to_bin>/intpart/build/test/IntPartTests

The tests are made using googletest lib. So to try it you must install https://github.com/google/googletest.


