# Browser Storage

## Why Browser Data Storage

- Improved User Experience
- Increased Performance
- Offline Support
- We can store
  - User Generated Content
  - App's State
  - Cached assets
  - Authentication Tokens
  - Analytics

Browsers manage the implementation and security details and we can use JS to access this data. We should always treat this data as temporary.

## Data Storage APIs Comparison

Just to understand data storage better, we need to understand what an origin is. An origin is a combination of protocol, host, and port. Only the JS code running in the same origin can access the data stored in the browser.

- **Cookies**: These are small pieces of data stored in the browser. They are sent to the server with every request. In terms of browser storage, they are not a good option.
- **Web Storage**: These are key-value pairs stored in the browser. It has localStorage and sessionStorage APIs:
  - It can only store strings.
- **IndexedDB**: This is a database stored in the browser.
  - It can store JS objects and binary data.
- **Cache Storage**: Its a good API to store data.
  - It stores HTTP responses.
  - The key is the HTTP Request.
- **FileSystem Access API**: Not fully compatible with all browsers.
  - It allows us to access the file system.

All Browser Storage APIs are public to the user.

## Quotas and Persistence

- There is One Quote for all Storage APIs per origin. This includes the browser storage as well as service workers.
- Quotas do not include cookies, sessionStorage files created using file system API.
- Usually the storage is not persistent ie it can be cleared by the browser itself under storage pressure. To make sure the data is persistent, we should explicitly check the persistence of the storage and request permissions if necessary.
- We can use the navigator.storage.estimate() method to get an estimation of the usage and the total quota. Only available on some browsers.

## Web Storage

There are 2 types of web storage:

- **localStorage**: This is a key-value pair storage that is available across browser sessions.
- **sessionStorage**: This is a key-value pair storage that is available only for the current browser session.

1. The quota is 5MB per origin.
2. The concept of session in a mobile is not clear and hence sessionStorage is becoming a little ambiguous.
3. WebStorage APIs are synchronous and the use the UI thread while accessing the data. This can cause the UI to freeze if the data is large.

## IndexedDB

- NoSQL data store
- Can store JS Objects or bytes with key-based entries
- Features asynchronous API that doesn't block the UI thread
- Available on windows, workers, and service workers
- Original API is event-based, with Promise-based wrappers commonly used
- Supports transactions
- One origin can have multiple database, and each database can have multiple object stores.
- Whatever we clone, we can store in IndexedDB.

## Cache Storage

- We can store HTTP responses in cache storage. The key is the HTTP Request.
- We can cache assets, API responses, etc.
