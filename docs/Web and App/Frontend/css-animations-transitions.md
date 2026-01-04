# CSS Animations and Transitions

CSS Animations help us create dynamic and engaging user interfaces. They allow us to animate elements and create smooth, fluid movements that enhance the user experience. User experience makes users trust the applications more.

## Fundamentals

Why should we animate? There are 2 main reasons for that: _Guidance and Clarification_ and _Style and Branding_.

1. Duration: How long an _iteration_ of an animation takes to complete.
2. Delay: How long the animation should wait before starting.
3. Timing Function: The easing of an animation. How the animation accelerates or decelerates over time.

```
cubic-bezier(0.4, 0, 0.2, 1)
```

We can have certain CSS variables defined that we can use in our animations.

```
    :root {
        --duration: 1s;
    }

    .thing {
        animation-duration: var(--duration, 2s);
    }
```

CSS Variables are scoped to their own descendants.

### What to Animate?

1. Best: transform and opacity
2. Good: Color and Background
3. Bad: Height, width, left, right etc

The reason for transform and opacity is that they are rendered using the Graphic Tree. Height and width are rendered using the Layout Tree.

## CSS Transitions

Transitions are a way to animate changes to CSS properties. They are a way to animate the transition between two states of a property.

[CodePen for Transitions](https://codepen.io/awesome31-the-selector/pen/wBvNeQB)

## Keyframes

Keyframes, unlike Transitions, are a way to animate the transition between two states of a property. They are a way to animate the transition between two states of a property.

When we define keyframe animations, we define the states of the property at different points in time relative to its original state.

1. animation-fill-mode: This property defines the state of the element before and after the animation.
2. animation-play-state: This property defines the state of the animation. Can be paused or running.
3. animation-iteration-count: This property defines the number of times the animation should run.
