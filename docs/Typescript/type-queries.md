# Type queries and indexed access types

## 1. Type Queries

### `keyof` Operator

The `keyof` operator is used to get the type of the keys of an object.

```ts
type DatePropertyNames = keyof Date; // This will return all the properties of Date type.
```

### `typeof` Operator

The `typeof` operator is used to get the type of a variable or property. It will always return a `string`.

```ts
async function main() {
  const response = await Promise.all([
    fetch("https://jsonplaceholder.typicode.com/todos/1"),
    Promise.resolve(10),
  ]);

  type Response = typeof response; // This will return the type of response variable.
}
```

## 2. Indexed Access Types

Indexed access types are used to get the type of a property within an object.

```ts
const person = {
  name: "John",
  age: 30,
  color: {
    primary: "red",
    secondary: "blue",
  },
};

type ColorType = (typeof person)["color"]; // This will return the type of color property of person object.
```

## 3. Type Registry Pattern

The Type Registry Pattern allows you to define reusable and type-safe objects, but we'll need more details to explain this pattern further. The concept can be extended to various use cases.
