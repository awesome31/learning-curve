/**
 * Given an array of integers numbers where each element in the array represents the maximum number of positions that can be moved forward from that index; it is acceptable to move by fewer positions.

Determine whether it is possible to reach the last index of the array by starting from the first index. Return true if it can be reached and false otherwise.
 */

function arrayReachableEnd(numbers: number[]): boolean {
  const filteredNumbers = numbers.filter((n) => n > 0);

  if (filteredNumbers === numbers) {
    return true;
  }

  let contigousZeroCount = 0;
  let startPointer = 0;

  for (let i = 0; i < numbers.length; i++) {
    if (numbers[i] === 0) {
      contigousZeroCount++;
    } else if (numbers[i] !== 0 && contigousZeroCount > 0) {
      console.log(numbers[i], contigousZeroCount);
      startPointer = Math.max(i - 2 * contigousZeroCount, 0);

      console.log(startPointer, "start");

      let canSkipZeros = false;
      while (startPointer < i) {
        if (numbers[startPointer] > contigousZeroCount) {
          canSkipZeros = true;
          break;
        }

        startPointer++;
      }

      contigousZeroCount = 0;

      if (!canSkipZeros) {
        return false;
      }
    }
  }

  if (contigousZeroCount > 0) {
    startPointer = Math.max(numbers.length - 1 - 2 * contigousZeroCount, 0);

    let canSkipZeros = false;
    while (startPointer < numbers.length - 1) {
      if (numbers[startPointer] > contigousZeroCount) {
        canSkipZeros = true;
        break;
      }

      startPointer++;
    }

    if (!canSkipZeros) {
      return false;
    }
  }

  return true;
}

console.log(arrayReachableEnd([4, 1, 0, 0, 2, 3]));
console.log(arrayReachableEnd([1, 0, 0, 0]));
console.log(arrayReachableEnd([2, 3, 1, 1, 4]));
