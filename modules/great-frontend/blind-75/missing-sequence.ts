/**
 * Given an array numbers of size n storing n different integers which fall within the range [0, n], implement a function to identify the missing element in the array. All numbers except one are present in the array. Find the missing number.
 */

//[1, 3, 0, Infinity]
//[1, -3, 0, Infinity]
//[1, -3, 0, -Infinity]
//[-1, -3, 0, -Infinity]

function findMissingNumberInSequence(numbers: number[]): number {
  const newNumbers = [...numbers, Infinity];

  for (let i = 0; i < newNumbers.length; i++) {
    if (newNumbers[Math.abs(newNumbers[i])] !== undefined) {
      newNumbers[Math.abs(newNumbers[i])] =
        -newNumbers[Math.abs(newNumbers[i])];
    }
  }

  for (let i = 0; i < newNumbers.length; i++) {
    if (Object.is(newNumbers[i], 0)) {
      return i;
    }

    if (newNumbers[i] > 0) {
      return i;
    }
  }

  return 0;
}

console.log(findMissingNumberInSequence([1, 3, 0]));
console.log(findMissingNumberInSequence([1]));
console.log(findMissingNumberInSequence([3, 0, 4, 2, 1]));
