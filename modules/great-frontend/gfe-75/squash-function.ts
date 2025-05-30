/**
 * Implement a function that returns a new object after squashing the input object into a single level of depth where nested keys are "squashed" together with a period delimiter (.).
 */

function squashObject(obj: Object): Object {
  const finalResult = {};

  Object.keys(obj).forEach((key) => {
    if (typeof obj[key] === "object" && obj[key] !== null) {
      const squashedSub = squashObject(obj[key]);

      Object.keys(squashedSub).forEach((nKey) => {
        if (key) {
          finalResult[`${key}${nKey ? `.${nKey}` : ""}`] = squashedSub[nKey];
        } else {
          finalResult[`${nKey}`] = squashedSub[nKey];
        }
      });
    } else {
      finalResult[key] = obj[key];
    }
  });

  return finalResult;
}

const object = {
  a: 5,
  b: 6,
  c: {
    f: 9,
    g: {
      m: 17,
      n: 3,
    },
  },
};

const object2 = {
  foo: {
    "": { "": 1, bar: 2 },
  },
};

const object3 = { a: { b: [1, 2, 3], c: ["foo"] } };

console.log("final", squashObject(object)); // { a: 5, b: 6, 'c.f': 9, 'c.g.m': 17, 'c.g.n': 3 }
console.log(squashObject(object2)); // { foo: 1, 'foo.bar': 2 }
console.log(squashObject(object3)); // { 'a.b.0': 1, 'a.b.1': 2, 'a.b.2': 3, 'a.c.0': 'foo' }
