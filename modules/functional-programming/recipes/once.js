/**
 * Once recipe is used to ensure a function is only called once.
 */

const add = (a, b) => a + b;

//Self Implementation
const once = (fn) => {
  let done = false;

  return function (...args) {
    if(done) {
      return void 0;
    } else {
      done = true;
      return fn.call(this, ...args);
    }
  }

}
const callOnce = once(add);

console.log(callOnce(1, 2));
console.log(callOnce(1, 2));
