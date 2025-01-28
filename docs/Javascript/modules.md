---
sidebar_position: 3
title: Javascript Module Systems
---

# JavaScript Module Systems

## Overview

Understanding JavaScript's module systems is essential for organizing and managing code effectively. Below are the major module systems used in JavaScript:

---

## CommonJS (CJS)

1. Modules are loaded **synchronously**, typically used on the server side.
2. Uses `require` for imports and `module.exports` for exports.
3. Requires bundling and transpiling to use in the browser.
4. Very common in Node.js environments.

### Syntax:

```javascript
const module = require("module");
module.exports = value;
```

---

## AMD (Asynchronous Module Definition)

1. Modules and their dependencies are loaded **asynchronously**.
2. Modules can be loaded at runtime when they are required.
3. Uses `define` for defining a module and `require` for importing.
4. Mostly used in the browser.

### Syntax:

```javascript
define(["dependency"], function (dependency) {
  return module;
});
```

---

## UMD (Universal Module Definition)

1. Works with both client-side and server-side environments.
2. Ideal for libraries intended to work in both environments.

---

## ESM (ECMAScript Modules)

1. Standardized module system introduced in **ES6**.
2. Uses `import` and `export` keywords.
3. Can be used in the browser with the `type="module"` attribute.
4. Can be used in Node.js with the `.mjs` extension or by setting `"type": "module"` in `package.json`.
5. Allows for **tree shaking**, static analysis, and more efficient bundling.

### Syntax:

```javascript
// Exporting
export const value = 42;
export default function () {}

// Importing
import value from "./module.js";
import { namedExport } from "./module.js";
```

---

## Things to Remember

1. **`import` statements** get hoisted to the top of the file.
2. If using a top-level `await`, the module loading is deferred until the promise resolves.
3. **`import` statements** are synchronous, whereas **`import()` functions** are asynchronous.

---

## Example Function

```javascript
function getRohit() {
  if (true) {
    // Add functionality here
  }
}

getRohit();
```
