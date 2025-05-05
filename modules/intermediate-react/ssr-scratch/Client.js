import { hydrateRoot } from "react-dom/client";
import { createElement } from "react";
import App from "./App";

hydrateRoot(document.getElementById("root"), createElement(App));
