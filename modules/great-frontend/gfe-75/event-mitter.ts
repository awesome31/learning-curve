/**
 * In the observer pattern (also commonly known as the publish-subscribe model), we can observe/subscribe to events emitted by publishers and execute code whenever an event happens.

Implement an EventEmitter class similar to the one in Node.js that follows such an observer pattern.

Example usage of the EventEmitter class:
 */

interface IEventEmitter {
  on(eventName: string, listener: Function): IEventEmitter;
  off(eventName: string, listener: Function): IEventEmitter;
  emit(eventName: string, ...args: Array<any>): boolean;
}

class EventEmitter implements IEventEmitter {
  listeners: { [eventName: string]: Function[] };

  constructor() {
    this.listeners = {};
  }

  on(eventName: string, listener: Function): IEventEmitter {
    if (this.listeners[eventName]) {
      this.listeners[eventName] = [...this.listeners[eventName], listener];
    } else {
      this.listeners[eventName] = [listener];
    }

    return this;
  }

  off(eventName: string, listener: Function): IEventEmitter {
    if (this.listeners[eventName]) {
      const firstListener = this.listeners[eventName].findIndex(
        (l) => l === listener
      );

      if (firstListener >= 0) {
        this.listeners[eventName].splice(firstListener, 1);
      }
    }

    return this;
  }

  emit(eventName: string, ...args: Array<any>): boolean {
    if (this.listeners[eventName] && this.listeners[eventName].length > 0) {
      for (let i of this.listeners[eventName]) {
        i.apply(this, args);
      }

      return true;
    }

    return false;
  }
}

const emitter = new EventEmitter();

function addTwoNumbers(a: number, b: number) {
  console.log(`The sum is ${a + b}`);
}

emitter.on("foo", addTwoNumbers);
emitter.emit("foo", 2, 5);
// > "The sum is 7"

emitter.on("foo", (a: number, b: number) =>
  console.log(`The product is ${a * b}`)
);
emitter.emit("foo", 4, 5);
// > "The sum is 9"
// > "The product is 20"

emitter.off("foo", addTwoNumbers);
emitter.emit("foo", -3, 9);
