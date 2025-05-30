/**
 * Given an array of integers numbers, determine whether the array contains any duplicate values. A duplicate is defined as any number that appears more than once in the array.
 */

function findDuplicates(numbers: number[]): boolean {
  const seenMap = new Map();

  for (let i of numbers) {
    if (seenMap.has(i)) {
      return true;
    } else {
      seenMap.set(i, true);
    }
  }

  return false;
}
