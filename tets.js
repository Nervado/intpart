function intPart(n) {
  var result;
  var range;
  var average_;
  var median_;
  if (n <= 1) {
    // trivial cases: enum(0) => [[0]] enum(1) => [[1]];
    range = 0;
    average_ = n;
    median_ = n;
    return (
      "Range: " +
      range.toFixed(0) +
      " Average: " +
      average_.toFixed(2) +
      " Median: " +
      median_.toFixed(2)
    );
  }
  var memoize = [];
  var pn = [0];
  var p0 = [pn];
  pn[0] = 1;
  var p1 = [pn];
  memoize.push(p0);
  memoize.push(p1);
  var order = 2;
  while (order <= n) {
    var current_partitions = [];
    var current = order - 1;
    current_partitions.push([order]);
    while (current >= 1) {
      for (var _i = 0, _a = memoize[order - current]; _i < _a.length; _i++) {
        var x = _a[_i];
        if (x[0] <= current && x[0] > 0) {
          var newPartition = [];
          newPartition.push(current);
          for (var _b = 0, x_1 = x; _b < x_1.length; _b++) {
            var el = x_1[_b];
            newPartition.push(el);
          }
          current_partitions.push(newPartition);
        }
      }
      current--;
    }
    memoize.push(current_partitions);
    order++;
  }
  var products = product(memoize[n]);
  result =
    'Range: "' +
    (products[products.length - 1] - products[0]) +
    '" Average: "' +
    average(products).toFixed(2) +
    '" Median: "' +
    median(products).toFixed(2);
  return result;
}
function sum(p) {
  var sum = 0;
  for (var _i = 0, p_1 = p; _i < p_1.length; _i++) {
    var el = p_1[_i];
    sum += el;
  }
  return sum;
}
function average(p) {
  var average = 0;
  var size = p.length;
  for (var _i = 0, p_2 = p; _i < p_2.length; _i++) {
    var x = p_2[_i];
    average += x;
  }
  return average / size;
}
function median(p) {
  var median = 0;
  var i = 0;
  if (p.length % 2 == 1) {
    i = (p.length - 1) / 2;
    return p[i];
  }
  i = p.length / 2;
  median = (p[i] + p[i - 1]) / 2.0;
  return median;
}
function sortAndRemoveDuplicates(p) {
  var sorted = [];
  var sortedAndNoDuplicates = [];
  sorted = p.sort();
  sortedAndNoDuplicates.push(sorted[0]);
  for (var i = 1; i < sorted.length; i++) {
    if (sorted[i] != sorted[i - 1]) sortedAndNoDuplicates.push(sorted[i]);
  }
  return sortedAndNoDuplicates;
}
function product(p) {
  var r = [];
  var result = [];
  for (var _i = 0, p_3 = p; _i < p_3.length; _i++) {
    var n = p_3[_i];
    var acc = 1;
    for (var _a = 0, n_1 = n; _a < n_1.length; _a++) {
      var el = n_1[_a];
      acc *= el;
    }
    r.push(acc);
  }
  result = sortAndRemoveDuplicates(r);
  return result;
}
console.log(intPart(8));
