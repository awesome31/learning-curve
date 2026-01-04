# Top Bottom Types

## 1. Top Types

### `any` Type

- `any` is the top type in TypeScript, representing any JavaScript value.
- `any` types are useful when the type of the variable is unknown. However, they should be avoided as much as possible.
- `any` types are not inherently bad; they are useful in certain cases.

```ts
let flexible: any = 1;
console.log(setTimeout, 1, "String");
```

### `unknown` Type

- `unknown` is the type-safe counterpart of `any`. It represents any JavaScript value.
- The difference is that you can't do anything with the `unknown` type unless you first check its type using type guards.

```ts
let myUnknown: unknown = 1;

if (typeof myUnknown === "string") {
  myUnknown.toUpperCase();
} else if (typeof myUnknown === "number") {
  myUnknown.toFixed();
} else {
}
```

#### Useful Use Case for `unknown`

- A common use case for `unknown` is when catching errors. You can enforce the use of `unknown` type in the catch block using the `useUnknownInCatchVariables` TypeScript error.

```ts
function doSomething() {
  if (Math.random() > 0.5) return "Ok";
  else if (Math.random() > 0.5) throw "Error";
  else throw new Error("Error");
}

function errorMe() {
  try {
    doSomething();
  } catch (e: unknown) {
    if (e instanceof Error) {
      console.log(e.message);
    } else {
      console.log(e);
    }
  }
}
```

## 2. Object Type

- The `object` type in TypeScript accepts all values except primitive types.
- It's better to use an interface to represent an object type than the `object` type.
- The `strictNullChecks` tsconfig setting will not allow `null` or `undefined` to be assigned to an `object` type.

```ts
let obj: object = { key: "value" };
// obj = '' Throws an error
// obj =  1 Throws an error
obj = []; // Does not throw an error
```

## 3. Bottom Types

The bottom type in TypeScript is the `never` type. It represents a value that never occurs. Here is an example that illustrates the `never` type.

```ts
class Truck {
  tow() {
    console.log("Towing");
  }
}

class Car {
  drive() {
    console.log("Driving");
  }
}

type Vehicle = Truck | Car;

class UnreachableaError extends Error {
  constructor(val: never, message: string) {
    super(message);
  }
}

function moveVehicle(vehicle: Vehicle) {
  if (vehicle instanceof Truck) {
    vehicle.tow();
  } else if (vehicle instanceof Car) {
    vehicle.drive();
  } else {
    new UnreachableaError(vehicle, "Unknown vehicle");
  }
}
```

## 4. Unit Types

The `void` type is used when a function does not return anything.

```ts
let myVoid: void = undefined;
```
