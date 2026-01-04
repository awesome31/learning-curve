---
sidebar_position: 3
title: JavaScript Runtime Environment
---

# JavaScript Runtime Environment

## Components of a JavaScript Runtime Environment

1. **Call Stack**
2. **Web APIs**
3. **Macro Task Queue (Task Queue)**
4. **Micro Task Queue (Job Queue)**
5. **Event Loop**

### Key Note

- The **Micro Task Queue (Job Queue)** has a higher priority than the **Macro Task Queue (Task Queue)**.

---

### Common Examples of Micro Tasks

```javascript
queueMicrotask(() => console.log("Micro Task 1")); // We can create a micro task using queueMicrotask() function.

Promise.resolve().then(() => console.log("Micro Task 2")); // We can create a micro task using Promise.

async function asyncFunction() {
  await console.log("Micro Task 3");
}

asyncFunction();
```

---

## Question 1

### Execution Order

**Explanation:**

1. The body of the async function or a new promise constructor is executed synchronously.
2. The **Micro Task Queue** is executed.
3. The Event Loop checks the **Micro Task Queue** and executes the micro tasks.
4. The **Macro Task Queue** is executed.
5. The Event Loop checks the **Macro Task Queue** and executes the macro tasks.

**Answer:** `4, 5, 6, 1, 3`

```javascript
Promise.resolve().then(() => {
  console.log("1");
});

setTimeout(() => console.log(3), 0);

console.log(4);

new Promise(() => console.log(5));

(async () => console.log(6))();
```

---

## Question 2

**Answer:** `4, 5, 1, 2, 8, 7, 6, 3`

```javascript
async function someFunction() {
  console.log("1");
  new Promise(() => console.log("2"));

  await new Promise((res) => {
    setTimeout(() => console.log(3), 0);
    res(1);
  });
}

new Promise((res) => {
  console.log("4");

  (async () => {
    console.log("5");
    await someFunction();
    console.log("6");
  })();

  res(2);
}).then(() => console.log(7));

console.log(8);
```
