import parseCode from "./parse.js";
// Simulating CommonJS-style import
import traverseImport from "./traverse.cjs";

// inspect what's actually being imported
console.log("Imported traverse:", traverseImport);
console.log("typeof traverseImport:", typeof traverseImport);

// Handle interop
const traverse = traverseImport.default
  ? traverseImport.default
  : traverseImport;

const code = `let x = 42;`;
const ast = parseCode(code);

traverse(ast, {
  enter(node) {
    if (node.type === "Identifier") {
      console.log("Found identifier:", node.name);
    }
  },
});
