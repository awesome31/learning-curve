function add(x, y) {
  return x + y;
}

class Person {
  constructor(firstName, lastName) {
    this.id = "person-" + Math.random();
    this.firstName = firstName;
    this.lastName = lastName;
  }

  get fullName() {
    return `${this.firstName} ${this.lastName}`;
  }
}

function spiesTest() {
  console.log("What is life?");
}

export { add, Person, spiesTest };
