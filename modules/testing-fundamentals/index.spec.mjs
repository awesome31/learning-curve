import { add, Person, spiesTest } from "./index.mjs";
import { describe, it, expect, vi } from "vitest";

describe("add", () => {
  it("should add two numbers", () => {
    expect(add(1, 2)).toBe(3);
  });

  it("Testing Equality", () => {
    expect(1).toBe(1);
    expect("hello").toBe("hello");
    expect({ name: "John" }).toEqual({ name: "John" });
  });
});

describe("Person", () => {
  it("Should create a new person", () => {
    const person = new Person("John", "Doe");

    expect(person).toEqual({
      id: expect.stringContaining("person-"),
      firstName: "John",
      lastName: "Doe",
    });
  });

  describe("spiesTest", () => {
    it("should log 'What is life?'", () => {
      const logSpy = vi.spyOn(console, "log");

      spiesTest();

      expect(logSpy).toHaveBeenCalledWith("What is life?");
    });
  });
});
