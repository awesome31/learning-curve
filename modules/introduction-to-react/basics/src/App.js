const Pizza = (props) => {
  return React.createElement("div", null, [
    React.createElement("h2", null, props.name),
    React.createElement("p", null, props.description),
  ]);
};

const App = () => {
  return React.createElement("div", null, [
    React.createElement("h1", null, "Kake da Pizza"),
    React.createElement(Pizza, {
      name: "Makke da Pizza",
      description: "Maka, Pizza",
    }),
    React.createElement(Pizza, {
      name: "Sarso da Pizza",
      description: "Sarso, Pizza",
    }),
  ]);
};

const container = document.getElementById("root");

ReactDOM.createRoot(container).render(React.createElement(App));
