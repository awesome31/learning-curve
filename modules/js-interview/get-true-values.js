/**
 * input = [1, “Hello”, null, false, 0, { abc: {}, def: false, cd: 0}, [“mno”, {x:1}}]]
 output = [1, “Hello”, abc, mno, x]
 */

 /**
  *
  * @param {any} inp
  */
function checkTruthValues(inp, keyPushed) {
  let result = [];

  if(Array.isArray(inp)) {
    inp.forEach((val) => {
      result = [...result, ...checkTruthValues(val)]
    })
  } else if(typeof inp === 'object' && inp) {
    Object.keys(inp).forEach((key) => {
      if(inp[key]) {
        result.push(key)

        result = [...result, ...checkTruthValues(inp[key], true)]
              }
    })
  } else if(inp && !keyPushed) {
    result.push(inp)
  }

  return result;
}

console.log(checkTruthValues([1, "Hello", null, false, 0, { abc: {x: false, whatever: true}, def: false, cd: 0}, ["mno", {x:1}]], false))
//OP: [ 1, 'Hello', 'abc', 'whatever', 'mno', 'x' ]
