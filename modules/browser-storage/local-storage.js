function checkLocalStorage() {
  if (localStorage) {
    localStorage.setItem("test", JSON.stringify({ name: "test" }));
    console.log(
      "I have not removed yet: ",
      JSON.parse(localStorage.getItem("test"))
    );
    localStorage.removeItem("test");
    console.log("I have removed: ", localStorage.getItem("test"));
  }
}

export { checkLocalStorage };
