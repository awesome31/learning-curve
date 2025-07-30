/**
 * Arrays are ordered collections of things, and ordered collections are a fundametal abstraction for making sense of reality.
 * Array literals are expressions and reference types.
 */
console.log([])
console.log([] == [])

const oneTwoThree = [1, 2, 3]
console.log(oneTwoThree[0], oneTwoThree[1], oneTwoThree[2]);

//Arrays always store references to other values.
const a = []
const b = [a];
console.log(a === b[0])

//Destructing is a way to get elements from arrays. Since it closely resembles the syntax for array literals, it is a valuable coding style.
const [first, second, third] = oneTwoThree;
console.log(first, second, third);

//We can gather array items as well
const [newFirst, ...rest] = oneTwoThree;
console.log(newFirst, rest);

//Function parameters can also be destructured. Gathering is the opposite of destructuring.
function sum(...args) {
    return args.reduce((acc, curr) => acc + curr, 0);
}
console.log(sum(1, 2, 3, 4))

//Get the length of an array without using the length operator.
function getLength(array) {
  const [first, ...rest] = array;

  if(first === undefined)
    return 0;

  return 1 + getLength(rest);
}

console.log(getLength([1, 2, 3, 4]))
