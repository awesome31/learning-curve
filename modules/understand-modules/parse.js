import { parse } from "@babel/parser";

export default function parseCode(code) {
  return parse(code, { sourceType: "module" });
}
