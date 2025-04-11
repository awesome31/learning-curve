function hoverMeFunction() {
  //Only when this bundle is loaded, is when we can actually apply the styles dynamically.
  import("./counter.module.css").then((counterStyle) => {
    document.getElementById("counter").classList.add(counterStyle.counter);
  });

  console.log("Hovered on counter");
}

export { hoverMeFunction };
