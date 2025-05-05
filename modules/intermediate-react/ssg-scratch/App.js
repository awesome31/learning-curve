import { createElement } from "react";

const App = () => {
  return createElement("div", null, [
    createElement("h1", null, "Hello Frontend Masters"),
    createElement("p", null, "Welcome to our app!"),
  ]);
};

export default App;
