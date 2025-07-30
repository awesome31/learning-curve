# State Management At Scale

At scale in frontend means the ability to iterate fast, write code without breaking any existing functionality and maintain a clean and organized codebase.


## React State Management Anti Patterns

### Deriving State

1. This is a common anti-pattern. If a state can be derived, we need not store the state. Instead of a useEffect+useState combination, we can use a useMemo hook to derive the state.

2. This is an anti pattern because, it leads to unnecessary re-renders and can cause performance issues.

### Redundant State

1. A lot of state we tie a state variable to something that should not cause a re-render. A good example of it is a timer. A timer should be stored in a ref, so that it does not cause a re-render.

2. There are cases, where we have say an array of objects in one state and then say a selected state that has the same shape as the object. (example: hotels[] and selectedHotel state.). Instead of this kind of state systems, we can actually set the selected hotel ID and then derive the hotel. The reason for doing this is, there are some cases where the hotels array might change, and that results in stale data. Its always good that states are primary keys that can derive stuff.

## State Modeling

### Core Concepts

1. Incidental Complexity: The irreducable complexity that comes from the problem statement itself.
2. Accidental Complexity: The complexity that comes from the implementation details of the system. These are avoidable and self inflicted.

We should always try to separate the incidental complexity from the accidental complexity. We should always do quick documentation to make sure the logic is easy to understand and maintain.

### Essential Modelling Diagrams

There are some diagrams that everyone should know about to understand data diagrams.

1. Entity Relationship Diagrams (ERDs): These diagrams are used to represent the relationships between entities in a database. This helps in understanding the data model and the relationships between entities. We can use ERDs in FE systems as well.

2. Sequence Diagrams: Document the flow of interactions between different parts of your system.

3. State Diagrams: Document the flow of states in your Frontend system. States have initial state, transitions and events that trigger those transitions.

## Best Practices for State Management

### Principles

1. Events are the real source of truth: Capture user intent and business logic through events, not direct state mutations. Directly chaning the state is an anti-pattern. Events help us really understand the why and how of a state change.

2. We should use pure functions and immutability for all the business logic. We should not mix side effects with the functions.

3. Framework agnostic architecture: We should not be tied to any specific framework. We should be able to switch frameworks without changing the core logic of our application. We should think of our UI in terms of state.

4. Declarative Side Effects: Separate what should happen from how/when it happens. We should declare side affects based on state, let the framework handle the execution.

### Combining Related State

1. Always try to group related data together. Instead of having multiple state slices for the same data, we should group them together (probably in a single object).

2. We also do a lot of loading, error, success screens etc. Instead of having multiple states for each TYPE of data, we can create one object called status which will have properties like loading, error, success etc. Whenever we have mutually exclusive states, we can use a union type to represent them instead of indivisual pieces of data.

3. We can use TypeState, which is a way to represent a state in typescript. TypeState uses disriminated unions to represent a state. Based on some top level key, we can enforce that another key exists. (For example: if status is success, then we can enforice that receipt data exists.). Type states are amazing becasue it enforces us to check state while setting and also prevents impossible state of your application.

### Managing FormData

1. A very commom interaction on frontend is a form. Instead of creating multiple states for form, HTML internally does a lot of state handling related to forms. We can leverage that to manage form state. We can use zod in combination with formData to validate and parse form data.

2. We can also use the new useActionState that helps us manage form state inside react/NextJS applications. With complex forms, we can use prebaked and solved version of forms like tanstack forms or react-hook-form.

### Context and useReducer

1. We can make use of Context APIs and useReducer hook to create something like redux where we have state and actions that modify the state. This helps us avoid prop drilling and making the codebase much cleaner.

### Step-Based Approach

Instead of having a status based approach, we can use a step based approach where each UI state like searching, results and success/error are steps. This helps us make a better mental model of the application. Instead of using a step based LINEAR approach, we can actually visualise the flow to be a Directed graph.

Instead of: step1->step1->step3 we can actually create a data structure like this:

```js
const formStateMachine = {
  "search": {
    "next": "loading",
    "skip": "results" // Skip loading and go directly to results
  },
  "loading": {
    "next": "results",
    "previous": "search",
    "skip": "success" // Skip results validation
  },
  "results": {
    "next": "success",
    "previous": "loading",
    "skip": "search" // Skip to start over
  },
  "success": {
    "next": "error",
    "previous": "results",
    "skip": "search" // Skip error handling
  },
  "error": {
    "next": "search",
    "previous": "success"
  }
}

```
Graphs as a better data structure to represent the flow of the application. We can visualise the graph as well using mermaid and feeding to AI applications. Also with this, we can even make certain steps skipable.

## External State Management

There are uscases where React's Built-in is not enough for state manegement at scale. At scale in FE systems means the project becoming complex and brittle and tough to maintain.

1. Prop Drilling becomes tough and Context API becomes cumbersome and has a lot of performance issues.
2. Complex State logic scattered everywhere.

## Data Normalization

Its always a good idea to flatten data structures by storing entities in separate collections with IID references. This also helps us avoid redundant data and makes it easier to update and maintain. Instead of using big objects to store your data, we can have a normalized version of it. Also with deeply nested objects, we are actually changing the WHOLE object, which results in a lot of unnecessary re-renders and performance issues.

**EVENTS ARE THE ONLY SOURCE OF TRUTH.**

## Event Driven vs Reactive Programming

When building complex UI applications, its common that multiple UI states depend on each other. A naive approach is to have multiple useEffects trigger one after the other. Cascading useEffect is a VERY common problem statement.

The solution: Think about *why* the data is changing as ooposed to *when* the data is changing. All side effects, then can happen in a single useEffect.

## Advanced State Management

1. URLs are a great way for us to manage state. A lot of times, in browsers, there is a loss of state when the user reloads the page etc.
We can use a great librabry called nuqs, to manage the URL state.

2. For API calls, we can use of react-query instead of doing any API calls manually. This is by far the best way to manage API calls in React applications.
