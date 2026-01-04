# TypeScript: Type Aliases, Interfaces, and Advanced Features

## Type Aliases

Type aliases allow you to define a more meaningful name for a type, enabling better readability and reuse.

### Features of Type Aliases:

1. Define meaningful names for types.
2. Declare the shape of a type in one place and reuse it.
3. Easily import and export types.
4. Store any type, including primitives, objects, unions, or intersections.
5. Create type aliases even inside functions.

### Example:

```typescript
type Amount = {
  value: number;
  currency: string;
};

function printAmount(amount: Amount) {
  console.log(amount);
  console.log(amount.value);
  console.log(amount.currency);
}

printAmount({ value: 100, currency: "USD" });
```

### Inheritance with Type Aliases:

```typescript
type SpecialDate = Date & { getDescription: () => string };

const specialDate = Object.assign(new Date(), {
  getDescription() {
    return `The current date is ${this}`;
  },
});

console.log(specialDate.getDescription());
```

---

## Interfaces

### Features of Interfaces:

1. Interfaces cannot model all types in TypeScript (e.g., unions are not supported).
2. Interfaces are better for extension and can extend other interfaces or be implemented by classes.
3. Classes can implement interfaces to enforce structure.
4. Interfaces are **open** (can be redeclared and merged).

### Example:

```typescript
interface Animal {
  isAlive: () => boolean;
}

interface Mammal extends Animal {
  hasHair: boolean;
}

class Dog implements Animal {
  isAlive() {
    return true;
  }
}
```

### Open Nature of Interfaces:

```typescript
interface Promise<T> {
  wow: () => void;
}

new Promise(() => {}).wow();
```

---

## Recursive Types

Recursive types allow defining self-referential types.

### Example:

```typescript
type NestedNumber = number | NestedNumber[];

const val: NestedNumber = [1, [2, [3, [4]]]];
```

---

## Question: Define a Type for JSON

A valid JSON value must be one of the following:

1. Object
2. Array
3. String
4. Number
5. Boolean
6. Null

### JSONValue Type:

```typescript
type JSONValue =
  | string
  | number
  | boolean
  | null
  | JSONValue[]
  | { [key: string]: JSONValue };
```
