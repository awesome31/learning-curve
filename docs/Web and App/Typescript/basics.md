# Basics of Typescript

**Variables**

- **`let`:** Declares a block-scoped variable. Can be reassigned.

  ```typescript
  let username = 2;
  // username = "Rohit"; // Not allowed
  ```

- **`const`:** Declares a block-scoped constant. Cannot be reassigned.
  ```typescript
  const age = 25; // Constant variable
  ```

**Literal Types**

- Define a type based on a specific value.

  ```typescript
  let humidity: 79 = 79;
  humidity = 79; // Allowed
  // humidity = 78; // Not allowed

  let x = 10 as 79; // Type assertion (not recommended)
  console.log(x);
  ```

**Type Casting**

- Explicitly change the type of a variable.
  ```typescript
  let y = new Date();
  let y2 = y as any; // Type casting
  ```

**Function Typing**

- Specify the types of parameters and the return type.
  ```typescript
  const add = (a: number, b: number): number => {
    return a + b;
  };
  // const result = add(2, "3"); // Error
  // new Promise(result); // Error
  ```

**Tips**

1. Always be explicit about function return types.
2. Catch errors at function declaration for better maintainability.

**Key Concepts**

- TypeScript helps catch errors at compile time.
- Literal types enforce strict value assignment.
- Type casting should be used judiciously.
- Clear function typing improves code readability and maintainability.
