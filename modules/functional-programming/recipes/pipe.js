/**
 * Pipe recipe means that we compose functions together from left to right. Its the opposite of the compose recipe.
 */

import * as R from 'ramda';

const addOne = (x) => x + 1;
const multiplyByTwo = (x) => x * 2;

//Self Implementation
const pipeline = (...fns) =>
(value) =>
fns.reduce((acc, fn) => fn(acc), value);

console.log(pipeline(addOne, multiplyByTwo)(3));

//Ramda Implementation
console.log(R.pipe(addOne, multiplyByTwo)(4))
