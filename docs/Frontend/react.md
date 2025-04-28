# React

This page contains all the things that we will be learning about React. We will talk about react 18 and 19.

## Basics

1. We have 2 packages, react and react-dom. react is the universal package that can be used in any environment. react-dom is the package that is used for the browser environment.
2. createElement has 3 main parameters: element name, properties and children.

```js
React.createElement("h1", null, "Kake da Pizza");
```

3. The building block of React is components. A component is an encapsulated piece of UI that given the properties, returns the UI.
4. ESLINT Configuration has changed from .eslintrc.js to eslint.config.mjs
5. eslint --debug helps us debug the eslint configuration.
6. Vite is currently the best build tool for Frontend systems. We will be using it for our React applications.
7. JSX is a syntax extension for JavaScript that allows us to write HTML in JavaScript. JSX is not valid JavaScript, but it is transformed into valid JavaScript by Babel. Vite transforms JSX into valid JavaScript. JSX is bascially the markup that you mean to generate and hence is a better way to expressing the UI.
8. import React from "react" is not required in React 18 and above. React is now a global object.
9. We can use Vite to proxy requests running on any other port to run from the same port

```js
 server: {
    proxy: {
      "/api": {
        target: "http://localhost:3000",
        changeOrigin: true,
      },
      "/public": {
        target: "http://localhost:3000",
        changeOrigin: true,
      },
    },
  },
```

10. Hooks are functions that allow you to use state and other React features in functional components. Hooks are functions that start with the word `use`.

    - You cannot use hooks in conditionals or loops.
    - `useState` is a hook that allows you to use state in a functional component. State is the data that is used to render the UI.
    - `useEffect` is a hook that allows you to use side effects in a functional component. Side effects are the actions that are performed outside of my component's render cycle. The reason useEffect does not take an async function is because async function returns a promise and useEffect does not return a promise.

11. Keys are used to identify which items have changed, are added, or are removed. Keys should be given to the elements inside the array to give the elements a stable identity.
12. StrictMode renders effects twice.
13. Custom Hooks are a way to encapsulate the logic into one separate place. They make testing indivisual pieces of code very easy instead of tying our effects and state inside the component itself. You have to use `use` in front of the hook.
14. Form onSubmit is better than onClick for submitting forms. We get the accessibility and functionality for free.
15. Portals are a way to render a component into a different part of the DOM. They still are a child of the component that is rendering them.
16. Error Boundaries are a way to catch errors in the component tree.
