# Senior FE Engineer Interview Prompts

## The Prompt

Can you pretend like you are interviewer and I am interviweing for a Senior Frontend Engineer role with focus on JS and React. Ypou have to ask me 5 questions. Lets start?

## Replies

### Question1

Can you walk me through the difference between null, undefined, and NaN in JavaScript, and explain how you'd typically encounter each one in a React application?

**Answer**:

Thanks! That’s a solid start. Let me offer a quick refinement before we move to the next:

- ✅ You're correct that null is a special value often used intentionally to signal "no value."

- ⚠️ typeof null returns 'object', which is a long-standing quirk in JavaScript — but null itself is a primitive, not an object.

- ✅ undefined means a variable has been declared but not assigned a value. It’s indeed automatically assigned in many cases (e.g., missing function returns).

- ⚠️ NaN actually is a number — its type is 'number' — but it represents an invalid number (like the result of parseInt("abc")).

### Question2

How does React’s reconciliation process work, and how does the key prop influence it? Can you give an example where a bad choice of key could lead to bugs or performance issues?

**Answer**:

React's Component Lifecycle can be divided into three phases:

1. Triggering a Render: This phase is triggered during initial render or when the state updates using setState. The state updates are put in a queue and processed by the React Scheduler.
2. Rendering: React calls the component and works on state updates. It Reconciles and marks it as dirty for the commit phase. Create a new DOM node internally in the VDOM.
3. Commit: Apply Actual DOM manipultation. Runs all the effects.

Apart from a normal DOM tree, React maintains a React Fiber tree which is a tree of all the components. The reason keys are essential is that react Fiber tree created can have the same component being rendered again and again, and it can help react identify which specific compoonent needs to be updated.

### Question3

How would you decide when to use useState, useReducer, useContext, or a state management library like Redux or Zustand? Can you walk through a decision-making framework you use?

**Answer**:

State updates are one of the biggest decisions that need to be taken from the FE perspective. That being said, the way that I decide what to use is:

1. IF the state is local and contained within a specific component, I use useState.
2. If the state is a big object, I prefer to use useReducers althout useStates work just fine.
3. If there is a lot of prop drilling happening, we usually try to use useContext.

Redux and Zustand primarily are used for states that should be globally available, like user preferences or user store but can also be used to replace contexts etc.

### Question 4

Imagine a React component that renders a large list of items, and it feels laggy. How would you optimize it? Walk me through the steps you'd take to identify and fix the performance bottleneck.

**Answer**:

✅ What You Covered Well:

Component Weight & Memoization:
Spot on — components rendering large lists should be memoized using React.memo or useMemo (for computed data). Especially important if the list items are complex or receive props that frequently change.

State Update Efficiency:
Great insight about minimizing how often the full list is re-rendered — using append-only updates or tools like useRef for stable reference preservation helps.

Efficient Key Usage:
Again, solid point. Bad key choices can break React’s diffing optimizations and lead to unnecessary unmounting/mounting of list items.

🔧 Additional Optimization Techniques to Consider:

Windowing / Virtualization:
Use libraries like react-window or react-virtualized to render only the visible part of the list at any given time. This is a game-changer for massive lists.

Avoid inline functions/objects in JSX:
Inline lambdas or object literals in props can cause child components to re-render unnecessarily. Use useCallback and useMemo to keep those stable.

Throttle or debounce state updates (esp. for user typing or scroll events).

Analyze with React DevTools Profiler to actually see what’s re-rendering and why.

### Question 5

Can you explain the differences between useEffect and useLayoutEffect, and when you’d prefer one over the other?

**Answer**:

⏱ Timing Differences:

useLayoutEffect:

Runs synchronously after all DOM mutations but before the browser paints.

Can block visual updates, so it’s blocking and render-blocking.

Ideal for reading layout (e.g., measuring DOM nodes) or making synchronous visual changes (like adjusting scroll position or animations).

useEffect:

Runs asynchronously after paint.

It's non-blocking, allowing the browser to update the screen first.

Good for data fetching, subscriptions, logging, and operations that don’t affect layout.
