# Union and Intersection Types

## Union Types

- **Concept:** Define a set of allowed values using the pipe (|) operator.
- **Mental Model:** Think of a set where a variable can hold one of the specified values.
- **Example:**
  ```typescript
  type OneThroughFive = 1 | 2 | 3 | 4 | 5;
  let evenNumber: 2 | 4 | 6 | 8 = 4; // Allowed
  ```

## Discriminated Unions

- **Concept:** Combine union types with a common property to differentiate them at runtime.
- **Example:**

  ```typescript
  type Result =
    | ["success", { name: string; email: string }]
    | ["failure", Error];

  function getData(): Result {
    // ... (implementation using flipACoin)
  }

  let result = getData();
  const [resultStatus, data] = result;

  if (data instanceof Error) {
    console.error(data.message);
  } else if (typeof data === "object") {
    console.log(data.name, data.email);
  }

  if (resultStatus === "success") {
    // Handle success case
  }
  ```

## Intersection Types

- **Concept:** Combine two types to create a new type that has the properties of both.
- **Example:**
  ```typescript
  type FullName = { name: string } & { age: number };
  let person: FullName = { name: "Alice", age: 30 };
  ```

## Type Guards

- **Concept:** Functions that help narrow down the type of a variable based on runtime checks.
- **Example:** (see Discriminated Unions example)

## Key Considerations When Using TypeScript

1. **Value Sets:** Define clear sets of allowed values for your variables.
2. **Guarantees:** Understand the guarantees associated with each type.
3. **Union vs. Intersection:** Choose the appropriate type based on whether you want an "OR" or "AND" relationship.
4. **Discriminated Unions:** Enhance type safety with a common property for runtime checks.
5. **Type Guards:** Use type guards to refine types based on runtime information.

## Additional Concepts

### Tuples

- **Definition:** Fixed-length arrays with specific types for each element.
  ```typescript
  const coordinates: [number, number] = [10, 20];
  ```

### Generics

- **Definition:** Create reusable components that work with different data types.
  ```typescript
  function identity<T>(arg: T): T {
    return arg;
  }
  ```

## Benefits of TypeScript

- **Improved Code Quality:** Catches errors early in the development process.
- **Better Maintainability:** Enhances code readability and understanding.
- **Increased Developer Confidence:** Provides type safety and guarantees.

## Learning Resources

- Explore the official TypeScript documentation for a deeper dive.
- Utilize online tutorials and courses to gain practical experience.
