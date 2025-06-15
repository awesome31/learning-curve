# Enterprise UI Development: Testing and Code Quality

The idea is to understand how we can leverage testing to improve code quality and maintainability, specifically for larger codebases.

## What is Enterprise UI Development?

The question that I get asked a lot is: What does a Frontend Architect do? Unlike Backend systems, where things scaling can be measured, frontend systems size is tough to measure. A large codebase almost always tries to lean towards high entropy, which is not a good thing. The idea of a maintaible codebase is that you are able to make changes CONFIDENTLY.

### Components of a Well Architected UI Application

1. **Testing**: Unit tests, Integration Tests, End to End Tests and Smoke Tests.
2. **Static Analysis**: Linters, Code Quality Tools, and Security Scans.
3. **Build Processes**: Automatically keeps a check for the above.
4. **Seperation of Concerns**: Clear demarcation between business logic and presentation logic.

Typescript solves for a lot of problems nowadays. To create a scalable frontend system:

1. First have the systems setup.
2. Then have the processes setup.
3. Last have patterns setup.

## Testing Basics

The idea of testing is: am I comfortable enough to refactor my code?

### Anatomy of a Test

A test essentially has 3 parts:

1. **Setup**: Any setup code that needs to run before the test.
2. **Assertion**: The thing you would ideally like to be true and throw an error if it is not.
3. **Teardown**: Any teardown code that needs to run after the test.

### Testing Guidelines

1. Writing tests isnt hard. But, some code is hard to test.
2. Your tests pass because they did not fail, not because your code works.
3. Someone is always testing your code.
4. Test for Invalid Input or edge cases.

When things break, three outcomes are possible:

- Fail gracefully.
- Flip a table and throw an error.
- Let things play out as they will.

### Testing Equality

1. toBe: this checks for exact equality.
2. toEqual: This checks for object properties.
3. toStrictEqual: This checks for object properties and also checks for the type of the object.

### Testing Randomness

There are some cases where we need to test randomness. For example, if we are testing a random string generator using uuid, then we can either mock the uuid and make it return a fixed value.

```
describe("Person", () => {
  it("Should create a new person", () => {
    const person = new Person("John", "Doe");

    expect(person).toEqual({
      id: expect.stringContaining("person-"),
      firstName: "John",
      lastName: "Doe",
    });
  });
});
```

- We can use stuff like `expect.any(Number)` to check for types instead of the exact value.
- beforeEach() and afterEach() are used to run code before and after each test.
- We usually can use async and await now in tests.

### Testing the DOM

Currently, if we run tests, thet are running in NodeJS Environment. NodeJS does not have any browser APIs. We need to use a library like jsdom or HappyDOM to simulate the DOM. We can use any testing-libraries like @testing-library/react or @testing-library/vue to test the DOM.

## Stubs, Mocks and Spies

In testing you cannot control the environment. Sometimes you want to test that a built-in function was called with the correct arguments or not. The idea of tha above 3 concepts is to fake the behavior of the function.

### Mocks

Mocks are used to fake the behavior of a function. Instead of using the actual function, we can use a mock function to fake the behavior of the function.

### Spies

Spies are used to see if a function was called or not.
