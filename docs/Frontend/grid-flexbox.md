# Grid and Flexbox Fundamentals

## Guiding Principles For Responsive Design

1. CSS Grid Based Layout should be the starting point. Sometimes flexbox.
2. Use images that resize. Use the `picture` element.
3. Use CSS media queries to target specific screen sizes.

Just remember, that CSS grids were made for the web to work correctly.

## Introduction to Grid

What is Grid best for?

1. A series of boxes that are of the same width.
2. Layouts that span across rows and or columns.
3. Siblings that need to cover each other.

Games to learn:

1. https://cssgridgarden.com/
2. https://codingfantasy.com/games/css-grid-attack
3. https://gridcritters.com/

## Responsive Web Design

There are two approaches to responsive web design:

1. Mobile First: Build your mobile styles outside the media queries and use min-width media queries.
2. Desktop First: Build your desktop styles inside the media queries and use max-width media queries.

Mobile First is a better approach but it depends on the project.

## CodePens for each section

1. [Introduction to Grid](https://codepen.io/awesome31-the-selector/pen/OPJErKJ)
2. [Introduction to Grid 2](https://codepen.io/awesome31-the-selector/pen/zxYaeWm)
3. [Grid Span and Repeat](https://codepen.io/awesome31-the-selector/pen/PwoBqoY)
4. [Grid Area](https://codepen.io/awesome31-the-selector/pen/MYWBwev)
5. [Media Queries with Grid Layout: Desktop First](https://codepen.io/awesome31-the-selector/pen/emYjNWV)
6. [Media Queries with Grid Layout: Mobile First](https://codepen.io/awesome31-the-selector/pen/WbNKrrW)
7. [Overlapping Grid Cells](https://codepen.io/awesome31-the-selector/pen/GgRBBVy)
8. [Overlapping Grid Cells Art ](https://codepen.io/awesome31-the-selector/pen/pvoZOJm?editors=1100)

## Understanding Grid Concepts

1. If your gaps are bigger than expected in a Grid, think that the element inside a cell has a margin.
2. `minmax()` is a function that returns the minimum and maximum values.
3. `auto-fit` and `auto-fill` are keywords that are used with the `grid-template-columns` and `grid-template-rows` properties. This can help grid behave like flexbox.
4. 1fr is defined by the tallest section if the height or width is auto.

## Where to Use Flexbox?

1. A series of boxes that are not the same size.
2. A series of boxes that are not in an event sized.
3. Flexbox was not designed to be locked down for layouts.
