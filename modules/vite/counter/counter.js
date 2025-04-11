let counter = 0;

function setupInitialCounter() {
  document.getElementById("counter").textContent = counter;
}

function setupIncrementButton() {
  document.getElementById("increment").addEventListener("click", () => {
    counter++;
    document.getElementById("counter").textContent = counter;
  });
}

function setupDecrementButton() {
  document.getElementById("decrement").addEventListener("click", () => {
    counter--;
    document.getElementById("counter").textContent = counter;
  });
}

function setupHoverOnCounter() {
  document.getElementById("counter").addEventListener("mouseover", () => {
    /**
     * This will be dynamically imported when the counter element is hovered over.
     * If you see the dist folder, you will see that hover.js is a separate file instead of inside index.js
     */
    import("./hover.js").then(({ hoverMeFunction }) => {
      hoverMeFunction();
    });
  });
}

export {
  setupInitialCounter,
  setupIncrementButton,
  setupDecrementButton,
  setupHoverOnCounter,
};
