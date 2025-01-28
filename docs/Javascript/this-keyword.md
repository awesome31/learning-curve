---
sidebar_position: 6
title: this Keyword in JavaScript
---

# `this` Keyword in JavaScript

The `this` keyword in JavaScript depends on the context where it is used:

1. **Global Context**:
   - Refers to the global object (`window` in the browser, `global` in Node.js).
2. **Regular Function**:
   - Refers to the object that calls the function.
3. **Arrow Function**:
   - Defined by the lexical context.
4. **Classes**:
   - Refers to the instance of the class.
5. **Strict Mode**:
   - `this` is `undefined` in the global context and functions.
6. **Event Handlers**:
   - Refers to the element that triggered the event.

---

## Example

```javascript
function logThis() {
  console.log(this);
}

const obj = {
  logThis,
  logthis2() {
    return logThis();
  },
  logThis3() {
    return obj.logThis();
  },
};

obj.logThis();
obj.logthis2();
obj.logThis3();
```
