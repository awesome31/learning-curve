/**
 * Partial Application means, if we have a function that takes multiple arguments, we partially apply it.
 */

import * as R from 'ramda';

const greet = (me, you) => `Hi ${you}, my name is ${me}`;

//Self Implementation
const callFirst = (fn, larg) =>
  function (...rest) {
    return fn.call(this, larg, ...rest);
  };

const rohitSaysHi = callFirst(greet, "Rohit");
console.log(rohitSaysHi("Aman"));

//Using ramda
const rohanSaysHi = R.partial(greet, ["Rohan"]);
console.log(rohanSaysHi("Aman"));
