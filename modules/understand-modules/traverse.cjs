const traverse = function (ast, visitors) {
  console.log("Traversing AST...");
  // Fake traversal
  visitors.enter && visitors.enter({ type: "Identifier", name: "x" });
};

module.exports = traverse;
