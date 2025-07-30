/**
 * Tap is a recipe, where we can use it to perform side effects on a value without modifying it.
 * tap is a traditional name borrowed from various Unix shell commands. It takes a value and returns
 a function that always returns the value, but if you pass it a function, it executes the function for
 side-effects.
 */

import * as R from 'ramda';

//Self Implemtation
const tap = (value) => (fn) => (
  typeof(fn) === 'function' && fn(value),
  value
)

tap(3)((value) => {
  console.log(`what is life ${value}`)
})

//Ramda Implemtation
const retruned = R.tap((value) => {
  console.log(`What is life2 ${value}`)
})(20)

console.log(retruned)
