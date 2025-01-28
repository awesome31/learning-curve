# Declaration Merging in TypeScript

## What is Declaration Merging?

Declaration Merging is a feature in TypeScript that allows us to combine multiple declarations with the same name into a single definition. This is particularly useful when we want to merge types and values.

If we hover over the `Fruit` export in the example, we can observe that it is both a function and a type. This is an example of declaration merging.

---

## Example: Merging Types and Values

### Fruit Interface

```typescript
interface Fruit {
  name: string;
  mass: number;
  color: string;
}

const banana: Fruit = {
  name: "banana",
  mass: 0.2,
  color: "yellow",
};
```

### Fruit Function

```typescript
function Fruit(kind: string) {
  if (kind === "banana") {
    return banana;
  } else {
    throw new Error("Fruit not found");
  }
}
```

Here, `Fruit` serves both as a type and a function, demonstrating declaration merging.

---

## Namespaces in TypeScript

Namespaces are a feature in TypeScript used to group related code. They:

1. Are values in TypeScript.
2. Do not create a new scope.

### Example:

```typescript
namespace Fruits {
  export const banana: Fruit = {
    name: "banana",
    mass: 0.2,
    color: "yellow",
  };
}

console.log(Fruits.banana);
```

---

## Practical Example: Declaration Merging with Classes

Declaration merging can also be applied to the `class` keyword for extending functionality.

### Example:

```typescript
class NewFruit {
  name?: string;
  mass?: number;
  color?: string;
}

const apple = new NewFruit();
const banana2: NewFruit = {} as any;
```

Here, the `NewFruit` class can be used as a type or an instance, allowing flexibility in TypeScript projects.

---

### Exports

```typescript
export { banana, Fruit };
```
