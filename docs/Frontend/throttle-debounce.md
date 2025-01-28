---
sidebar_position: 1
title: Debounce and Throttle
---

# Debounce and Throttle in JavaScript

## Debounce

Debouncing ensures that a function is not called again until a certain amount of time has passed since the last call. It is useful for scenarios like handling frequent user input events (e.g., keypress or window resizing).

### Implementation:

```javascript
function debounce(func, wait) {
  let timeout;

  return function executedFunction(...args) {
    const later = () => {
      clearTimeout(timeout);
      func(...args);
    };
    clearTimeout(timeout);
    timeout = setTimeout(later, wait);
  };
}
```

### Example:

```javascript
const callMe = debounce(() => console.log("Hello"), 1000);

callMe();
setTimeout(() => callMe(), 500);
```

In this example:

- The `callMe` function will only log "Hello" to the console after 1000ms, as long as it is not called again within that time frame.

---

## Throttle

Throttling ensures that a function is called at most once every specified amount of time. It is useful for limiting the execution of functions that are triggered repeatedly, such as scroll or mouse move events.

### Implementation:

```javascript
function throttle(func, wait) {
  let inThrottle;
  return function executedFunction(...args) {
    if (!inThrottle) {
      func(...args);
      inThrottle = true;
      setTimeout(() => (inThrottle = false), wait);
    }
  };
}
```

### Example:

```javascript
const callMe2 = throttle(() => console.log("Hello2"), 1000);

callMe2();
callMe2();
setTimeout(() => callMe2(), 500);
```

In this example:

- The `callMe2` function will log "Hello2" to the console immediately the first time it is called.
- Subsequent calls within 1000ms are ignored, and the function will only execute again after the throttle interval has elapsed.

---

### Key Differences Between Debounce and Throttle:

| Feature          | Debounce                                                      | Throttle                       |
| ---------------- | ------------------------------------------------------------- | ------------------------------ |
| Execution Timing | Executes after the specified delay if no further calls occur. | Executes at regular intervals. |
| Use Cases        | Typing input, resizing window.                                | Scrolling, mouse movements.    |
