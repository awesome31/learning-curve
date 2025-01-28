# Null and Undefined in TypeScript

## Key Differences

1. **Null**: Must be explicitly set to `null`.
2. **Undefined**: Set automatically at runtime when a variable has not been assigned a value.

```typescript
const Rohit = {
  name: "Rohit",
  age: null,
};

interface Person {
  name: string;
  age?: number;
}

const Shubham: Person = {
  name: "Shubham",
};

// const age: number = Shubham.age; // Error: Type 'undefined' is not assignable to type 'number'.
```

---

## Non-Null Assertion Operator

Used when we are certain a value is not `null` or `undefined`, often in unit tests or special scenarios.

```typescript
interface Grocery {
  fruits?: { name: string; quantity: number }[];
}

const grocery: Grocery = {};
grocery.fruits!.push({ name: "Rohitt", quantity: 2 }); // Error: Cannot read properties of undefined.
```

---

## Definite Assignment Assertion

The **Definite Assignment Assertion Operator** tells TypeScript that a variable will be assigned a value at runtime, even if it’s not initialized during declaration.

```typescript
let value!: number;
value = 42; // No error, TypeScript assumes this value will be assigned.
```

---

## Optional Chaining and Nullish Coalescing

### Optional Chaining (`?.`)

Used to safely access deeply nested properties without causing errors if any reference is `null` or `undefined`.

```typescript
interface Customer {
  lastPayment?: {
    paymentMethod?: string;
  };
}

const customer: Customer = {};
const method = customer.lastPayment?.paymentMethod; // undefined
```

### Nullish Coalescing Operator (`??`)

Provides a default value when the left-hand operand is `null` or `undefined`.

```typescript
const paymentMethod = customer.lastPayment?.paymentMethod ?? "Credit Card";
console.log(paymentMethod); // "Credit Card"
```
