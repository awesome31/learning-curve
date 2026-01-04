---
sidebar_position: 3
title: Generators and Iterables
---

# Generators and Iterables

## Generators

Generators are functions that can be paused and resumed. They are created using the `function*` syntax.

### Generator Methods and Properties

1. **`next()`**: Returns an object with:

   - `value`: The yielded value.
   - `done`: A boolean indicating if the generator is done.

2. **`state`**: Returns the current state of the generator.

3. **`return(value)`**: Returns the given value and finishes the generator.

4. **`throw(error)`**: Throws an error into the generator.

### Example

```javascript
function* genFunction() {
  yield 1;
  yield 2;
  yield 3;

  return 4;
}

const genObj = genFunction();

console.log(genObj.next()); // { value: 1, done: false }
console.log(genObj.return(5)); // { value: 5, done: true }

console.log([...genFunction()]); // [1, 2, 3]
```

---

## Making Objects Iterable

We can make any object iterable by adding a `Symbol.iterator` method to it.

### Example

```javascript
const range = {
  from: 1,
  to: 5,
  [Symbol.iterator]() {
    return {
      current: this.from,
      last: this.to,
      next() {
        if (this.current <= this.last) {
          return { done: false, value: this.current++ };
        } else {
          return { done: true };
        }
      },
    };
  },
};

console.log([...range]); // [1, 2, 3, 4, 5]
```
