# Understanding React in Depth

## React Render Modes

1. Client-Side React: Here we send the entire JS bundle to the client and let the client render the UI. This is the most common way to render React applications. You should not Nextify all the things that you build.

2. Static Site Generation (SSG): Here we generate the HTML at build time and send it to the client. [Sample example of how we can create an SSG Page.](https://github.com/awesome31/learning-curve/tree/main/modules/intermediate-react/ssg-scratch). Frameworks like Astro and Next.js support SSG and should be used.

3. Server-Side Rendering (SSR): In CSR, the user requests the page, and the server responds with index.html along with the JS that needs to be executed. The browser parses and executes the JS and hydrates the HTML, making it interactive. In SSR, the server generates a pre-rendered HTML and sends it to the client. So the time at which the user SEES the app becomes faster, but interaction still remains the same. We need to measure before we opt for SSR. SSR and then client side hydration is extremely sensitive to white spaces. [Sample example of how we can create an SSR Page.](https://github.com/awesome31/learning-curve/tree/main/modules/intermediate-react/ssr-scratch)

## React Server Components

React Server Components are NOT SSR 2.0. SSR is used to just make the initial page load visibly faster. When SSR is done, the client side react comes in and takes over. `They are components that are only rendered on the server`. A server component just returns a string of HTML.

RSCs were introduced based on the assumption that there are some parts of our web application which are not interactive. React Flight Protocol is used to send Markup in a way that react can read.

### Steps to creating it by Hand

I don't think anyone should be writing RSC by hand. I am just highlighting the steps that I have done:

1. We created a fastify server and created a route called `react-preflight` which returns a new kind of stream response that react can read.
2. In our Client.tsx file we use `createFromFetch` function given by react-server which converts the stream that we get from the server into a react element.
3. We then first build the client side code, and then using the built client side code we create a new stream response and send it to the client.

[Do check this repo out](https://github.com/awesome31/learning-curve/tree/main/modules/intermediate-react/rsc-scratch)

### RSCs with Next JS

- We need to use the 'use server' directive when creating a function that is going to be run on the server. This is used to disambiguate that for React.
- Form actions are functions that are run on the server.
- All Client components can be used in Server components, but Server components cannot be used in Client components.
- We can still have a server component, that does the API call and then it can import client component, that actually has stuff like polling etc.

There are some limitiations of RSCs:

- As mentioned above, we cannot use Server components in Client components.

[Do check this repo out](https://github.com/awesome31/learning-curve/tree/main/modules/intermediate-react/rsc-notes-app)

## Performance Optimisations

In most cases, React out of the Box works very well and is performant enough. But knowing the tools to optimise on the performance can be very helpful.

1. React.memo => This HOC is used to prevent re-rendering of a component when its props haven't changed.
2. useMemo => This hook is used to prevent re-computation of a value when its dependencies haven't changed.
3. useCallback => This hook is used to prevent re-creation of a function when its dependencies haven't changed.

With these 3 tools, we can prevent unnecessary re-renders and re-computations, which can improve the performance of our application. We need to use tools, ONLY and ONLY if the performance is an issue.

Why do we have useMemo and useCallback as 2 different things? They should not have been ideally.

```js
const render = useCallback(() => {
  console.log("a");
}, []);

const memoRender = useMemo(
  () => () => {
    console.log("a");
  },
  []
);


These 2 above are effectively the same thing. useCallback makes it easier to read.
```

For numbers and strings, we can avoid using useMemo. React Compiler is going to do a lot of heavylifting for us in the future. React compiler runs at build time.

## Perceived Performance

These tools are not going to improve the performance of our application. They are going to improve the perceived performance of our application.

### Transitions

Transitions are used to animate the changes in the UI when the state changes. We want to keep the UI responsive when I am doing something larger under the hood.

### Optimistic Values

Optimistic values are used to show the UI as if the state has changed, before the actual state has changed. This can improve the perceived performance of our application.
