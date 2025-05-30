/**
 * Promise.any() takes an iterable of elements (usually Promises). It returns a single promise that resolves as soon as any of the elements in the iterable fulfills, with the value of the fulfilled promise. If no promises in the iterable fulfill (if all of the given elements are rejected), then the returned promise is rejected with an AggregateError, a new subclass of Error that groups together individual errors.

If an empty iterable is passed, then the promise returned by this method is rejected synchronously. The rejected reason is an AggregateError object whose errors property is an empty array.

Source: Promise.any() - JavaScript | MDN

Let's implement our own version of Promise.any(), a promiseAny function, with the difference being the function takes in an array instead of an iterable and AggregateErrors returned just have to return an array of error reasons, the message doesn't have to be set. Refer to the AggregateError constructor examples on MDN.

Be sure to read the description carefully and implement accordingly!
 */

const promiseAnyExample = async () => {
  const p0 = new Promise((resolve, reject) => {
    setTimeout(() => {
      reject(42);
    }, 400);
  });
  const p1 = new Promise((resolve, reject) => {
    setTimeout(() => {
      reject("Err!");
    }, 100);
  });

  try {
    await promiseAny([p0, p1]);
  } catch (err) {
    console.log(err instanceof AggregateError); // true
    console.log(err.errors); // [ 42, "Err!" ]
  }
};

function promiseAny<T>(iterable: Array<T>): Promise<T> {
  return new Promise((resolve, reject) => {
    if (iterable.length === 0) {
      reject(new AggregateError([]));
    }

    let rejectedPromisesCount = 0;
    let rejectedPromiseErrors = new Array(iterable.length);

    for (let i = 0; i < iterable.length; i++) {
      Promise.resolve(iterable[i])
        .then((resp) => {
          resolve(resp);
        })
        .catch((e) => {
          rejectedPromisesCount++;
          rejectedPromiseErrors[i] = e;

          if (rejectedPromisesCount === iterable.length) {
            reject(new AggregateError(rejectedPromiseErrors));
          }
        });
    }
  });
}

promiseAnyExample();
