/**
 * Given an array of integers numbers and a number k, find the k most frequent numbers in the array. Here, k represents the number of elements that should be returned, which are the ones that appear the most frequently. The order of the result does not matter.
 */

function mostCommonElements(numbers: number[], k: number): number[] {
  const countMap = {};

  for (let i = 0; i < numbers.length; i++) {
    if (countMap[numbers[i]]) {
      countMap[numbers[i]]++;
    } else {
      countMap[numbers[i]] = 1;
    }
  }

  const sortedMap = [
    ...Object.entries(countMap).sort((a: any, b: any) => b[1] - a[1]),
  ];

  let result = [];

  for (let i = 0; i < k; i++) {
    result.push(Number(sortedMap[i][0]));
  }

  return result;
}

console.log(mostCommonElements([4, 4, 4, 6, 6, 6, 6, 5, 5, 5], 2));
