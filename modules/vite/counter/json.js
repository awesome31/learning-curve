import { name } from "./harry.json";

function setupHarry() {
  //Vite will treeshake all other properties of the JSON.
  console.log(name);
}

export { setupHarry };
