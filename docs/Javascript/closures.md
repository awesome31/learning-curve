---
sidebar_position: 5
title: JavaScript Scopes and Closures
---

# JavaScript Scopes and Closures

## Scopes in JavaScript

JavaScript has three types of scopes:

1. **Global Scope**
2. **Function Scope**
3. **Block Scope**

---

## Closures

A **closure** is the combination of a function bundled together (enclosed) with references to its surrounding state (the lexical environment). In other words, a closure gives you access to an outer function’s scope from an inner function.

### Example:

```javascript
const add = (x) => (y) => x + y;
const add2 = add(2);
console.log(add2(3)); // 5
```

---

## Questions

### Question 1:

```javascript
const outerFunc = () => {
  let count = 0;
  return () => ++count;
};

const counter = outerFunc();
console.log(counter()); // 1
console.log(counter()); // 2
```

### Question 2:

```javascript
function createCounter() {
  let globalCount = 0;

  function incrementCounter() {
    let incrementedValue = ++globalCount;
    return incrementedValue;
  }

  return {
    incrementCounter,
  };
}

const counter2 = createCounter();
console.log(counter2.incrementCounter()); // 1
console.log(counter2.incrementCounter()); // 2
console.log(createCounter().incrementCounter()); // 1
```

### Question 3:

```javascript
function createUserManager() {
  let user = null;

  return function (name) {
    "use strict";
    user = { name, createdAt: new Date() };

    return user;
  };
}

const createUser = createUserManager();
console.log(createUser("John Doe") === createUser("Jane Doe")); // false
```

---

## Phases of JavaScript Execution

JavaScript execution happens in two phases:

1. **Creation Phase**:

   - The JavaScript engine creates the global object, sets up the outer environment, and hoists variables and function declarations.
   - With `const` and `let` keywords, we have a **Temporal Dead Zone (TDZ)** where we can't access the variables before their declaration.
   - For `var` keyword, `import` statements, and `function` keywords, we have **hoisting**, allowing access to variables before their declaration.

2. **Execution Phase**:
   - The JavaScript engine executes the code line by line.

### Example:

```javascript
console.log("%cOrange", "color: #FFFFFF;");
```
