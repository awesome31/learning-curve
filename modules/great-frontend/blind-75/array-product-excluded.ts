/**
 * Given an array of integers numbers, return a new array result where each element result[i] represents the product of all the elements in numbers except for numbers[i]. We can have negative numbers and 0 as well.
 */

function arrayProductExcludingCurrent(numbers: number[]): number[] {
  if (numbers.length === 0) {
    return [];
  } else if (numbers.length === 1) {
    return numbers;
  }

  const prefixArray = [numbers[0]];

  for (let i = 1; i < numbers.length; i++) {
    prefixArray[i] = prefixArray[i - 1] * numbers[i];
  }

  numbers.reverse();
  const suffixArray = [numbers[0]];

  for (let i = 1; i < numbers.length; i++) {
    suffixArray[i] = suffixArray[i - 1] * numbers[i];
  }

  suffixArray.reverse();

  const finalResult = new Array(numbers.length);

  for (let i = 0; i < numbers.length; i++) {
    if (prefixArray[i - 1] !== undefined && suffixArray[i + 1] !== undefined) {
      finalResult[i] = prefixArray[i - 1] * suffixArray[i + 1];
    } else if (
      prefixArray[i - 1] === undefined &&
      suffixArray[i + 1] !== undefined
    ) {
      finalResult[i] = suffixArray[i + 1];
    } else if (
      prefixArray[i - 1] !== undefined &&
      suffixArray[i + 1] === undefined
    ) {
      finalResult[i] = prefixArray[i - 1];
    }
  }

  return finalResult.map((r) => (Object.is(r, -0) ? 0 : r));
}

console.log(arrayProductExcludingCurrent([1, 2, 3]));
console.log(arrayProductExcludingCurrent([2, 0, 3]));
console.log(arrayProductExcludingCurrent([0, 0, -1, 1]));
