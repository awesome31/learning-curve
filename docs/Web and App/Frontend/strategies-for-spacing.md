# Strategies for Spacing

## Understanding Regular Flow

In regular flow of HTML Elements, every block scoped element has a margin attached to it. Also the margins are collapsible and are defined using em instead of rem. The idea of em is that it is relative to the font size of the parent element. If there is heavy text content, em is a better unit to use as it is relative to the font size of the parent element.

If we have 2 margins that are touching each other, they become collapsible. If we use flex or grid, we create a new formatting context and this collapsibility is lost.

1. For things which are text heavy, regular flow of HTML elements is a good strategy to use.
2. For cards, we can use flex or grid to create a new formatting context and avoid the collapsibility issue and have consistent spacing.
