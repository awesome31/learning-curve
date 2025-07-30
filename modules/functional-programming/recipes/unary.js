/**
 * This is an application of the unary function recipe. Unary recipe means a function that has multiple arguments, being converted into a single argument.
 */

//This gives the wrong result because parseInt is called with two arguments, the first one is the element and the second one is the index.

import * as R from 'ramda';

console.log([1, 2, 3].map(parseInt))

//Self Implementation
const unary = (fn) => fn.length === 1? fn : function(something) {
  return fn.call(this, something)
}
console.log([1, 2, 3].map(unary(parseInt)))

//Ramda Implementation
console.log([1, 2, 3].map(R.unary(parseInt)))
