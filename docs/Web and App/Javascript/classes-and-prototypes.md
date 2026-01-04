---
sidebar_position: 2
title: Classes and Prototypes
---

# Classes and Prototypes

## Key Points

1. **Classes** are templates for creating objects.
2. When a class is instantiated:
   - Properties defined in the constructor are specific to each instance.
   - Methods are defined on the prototype.
3. JavaScript resolves method calls by:
   - First checking if the method exists on the instance.
   - If not found, it checks the prototype.

---

### Example Code

```typescript
/**
 * Example class definition: Dog
 */
class Dog {
  name: string;
  wagTail: () => string;

  constructor(name: string) {
    this.name = name;
    this.wagTail = () => "Wagging Tail";
  }

  bark() {
    return "Barking";
  }
}

const dog1 = new Dog("Tommy");
const dog2 = new Dog("Spike");

console.log(dog1.wagTail() === dog2.wagTail()); // false
console.log(dog1.bark === dog2.bark); // true
console.log(dog1.bark === Dog.prototype.bark); // true
console.log(dog1.wagTail === Dog.prototype.wagTail); // false
console.log(dog1.wagTail === dog2.wagTail); // false

export { Dog };
```

---

### Explanation

- **`wagTail` Property:**

  - It is defined as a function inside the constructor, so each instance has its own unique version of `wagTail`.
  - This is why `dog1.wagTail === dog2.wagTail` evaluates to `false`.

- **`bark` Method:**
  - It is defined as part of the prototype, shared across all instances of the class.
  - This is why `dog1.bark === dog2.bark` and `dog1.bark === Dog.prototype.bark` both evaluate to `true`.

---
