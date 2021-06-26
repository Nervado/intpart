export function part (n: number) {

  let result: string;
  let range: number;
  let average_: number = 0;
  let median_: number = 0;

  if (n <= 1) {
    range = 0;
    average_ = n;
    median_ = n;

    return "Range: " + range.toFixed(0) + " Average: " + average_.toFixed(2) + " Median: " + median_.toFixed(2);

  } else {

    let memoize: number[][][] = [];
    let pn = [0];
    let p0 = [pn];
    pn[0] = 1;
    let p1 = [pn];

    memoize.push(p0);

    memoize.push(p1);



    let order = 2;

    while (order <= n) {
      let current_partitions: number[][] = [];
      let current = order - 1;
      current_partitions.push([order]);
      while (current >= 1) {
        for (let x of memoize[order - current]) {
          if (x[0] <= current && x[0] > 0) {
            let newPartition = [];
            newPartition.push(current);
            for (let el of x)
              newPartition.push(el);
            current_partitions.push(newPartition);
          }
        }
        current--;
      }
      memoize.push(current_partitions);
      order++;
    }

    let products = product(memoize[n]);

    result = "Range: " + (products[products.length - 1] - products[0]) + " Average: " + average(products).toFixed(2) + " Median: " + median(products).toFixed(2);


    return result;
  }
}




function sum (p: number[]): number {
  let sum: number = 0;

  for (let el of p) {
    sum += el;
  }

  return sum;
}

function average (p: number[]): number {
  let average: number = 0;
  let size: number = p.length;
  for (let x of p) {
    average += x;
  }
  return average / size;
}

function median (p: number[]): number {
  let median = 0;
  let i = 0;
  if (p.length % 2 == 1) {
    i = (p.length - 1) / 2;
    return p[i];
  }
  i = p.length / 2;
  median = (p[i] + p[i - 1]) / 2.0;
  return median;
}


function sortAndRemoveDuplicates (p: number[]) {
  let sorted: number[] = [];
  let sortedAndNoDuplicates: number[] = [];

  sorted = p.sort((n1, n2) => n1 - n2);

  sortedAndNoDuplicates.push(sorted[0]);

  for (let i = 1; i < sorted.length; i++) {
    if (sorted[i] != sorted[i - 1])
      sortedAndNoDuplicates.push(sorted[i]);
  }
  return sortedAndNoDuplicates;
}


function product (p: number[][]): number[] {
  let r: number[] = [];
  let result: number[] = [];

  for (let n of p) {
    let acc = 1;
    for (let el of n) {
      acc *= el;
    }
    r.push(acc);
  }

  result = sortAndRemoveDuplicates(r);
  return result;
}
