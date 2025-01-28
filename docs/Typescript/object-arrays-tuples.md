# Object, Arrays and Tuples

## 1. Optional Types in Objects

You can define optional types in an object using the `?` operator.

```ts
type Person = {
  name: string;
  age: number;
  hasPet?: boolean;
};
```

## 2. Index Signatures

We can also use index signatures on top of explicit properties. This allows us to have dynamic keys in objects.

```ts
type IndexSignature = {
  [key: string]: string;
};

const helpMe: IndexSignature = {
  name: "John", // OK
  // name: 1, // Error: Type 'number' is not assignable to type 'string'.
};
```

## 3. Array Types

In TypeScript, you can define arrays with specific types:

```ts
const arr: string[] = ["Rohit", "John", "Doe"];
```

## 4. Tuple Types

Tuples are not a default type in JavaScript, so TypeScript is used to enforce the tuple types.

```ts
const myCar2 = [2020, "Ford", "Fiesta"];
const [year, make, model] = myCar2;
```

To explicitly define a tuple type in TypeScript:

```ts
const myCar3: [number, string, string] = [2002, "Toyota", "Corolla"];
```

However, you can still push more elements to the tuple, which TypeScript doesn't prevent:

```ts
console.log(myCar3.length); // 3
myCar3.push("new value");
console.log(myCar3.length);
```

### The Better Way: `readonly`

The `readonly` keyword ensures that the tuple is immutable.

```ts
const myCar4: readonly [number, string, string] = [2002, "Toyota", "Corolla"];
// myCar4.push(2) // Error: Property 'push' does not exist on type 'readonly [number, string, string]'.
```

## 5. Structural vs Nominal Typing

### Type Checking Models

- **Nominal Typing**: This is used in languages like Java and C#, where type checking happens based on the name of the type at compile time.
- **Structural Typing**: TypeScript uses structural typing, meaning that the structure of the variable is more important than the name of the type.

```ts
type BaseWidgetData<T> = {
  id: string;
  type: string;
  styles: object;
  widgetData: T;
};

export type HeaderProps = BaseWidgetData<{
  text: string;
  prescriptionCTA: string;
}>;
```
