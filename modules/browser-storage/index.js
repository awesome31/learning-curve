import { checkIndexedDB } from "./indexeddb-storage";
import { checkLocalStorage } from "./local-storage";
import { checkNavigatorStorage } from "./navigator-storage";

function run() {
  checkLocalStorage();
  checkNavigatorStorage();
  checkIndexedDB();
}

document.addEventListener("DOMContentLoaded", run);
