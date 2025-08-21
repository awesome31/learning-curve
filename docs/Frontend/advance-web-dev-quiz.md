# Advance Web Development

In this, we will understand some advance web development topics.

## Async and Defer questions

1. A regular script, that does not have async or defer, it blocks the HTML parsing to fetch and execute the script, and then continues with the HTML parasing. It is render blocking.
2. When I do `<script async>` it means, download the script parallel to the HTML parsing BUT execute the script only when the script is donwload. There is no gurantee of execution.
3. When we do `<script defer>` it means that download the script parallel to HTML parsing and execute the script ONCE the HTML parsing is done. Guarantees the execution of the scripts.

## Rendering Pipeline and Composting

1. First the browser, parses the HTML and creates a DOM tree, which is a tree representation of the markup. Along with the HTML, if there are any CSS files in the markup then a CSSOM tree is created.
2. Using the DOM tree and CSSOM tree, a render tree is created. Render tree consists of all the VISUAL elements that are there on the screen.
3. Post that the layout process kicks in. It takes the render tree and figures out the geometry and layout of each element.
4. After that it paints it on the screen.
5. After paint it performs the compositing process. Compositing process takes help of the GPU and if the styles are absolutely or relatively positioned, it takes that into account and repaints. Stacking Context decides where to render stuff.

## Resolving Domain Requests

This is how the browser resolved domain requests:

1. Browser sends request to Recursive DNS Resolver.
2. Recursive DNS Resolver queries the Root Name Server.
3. Root Server responsds with Top Level Domain Name Server's IP address.
4. TLDNS responsds with Authoratative Name Serve's IP address.
5. ReDNS queries ANS.
6. ANS responds with the website's IP address.

## Call Stack and Event Loop

The JS processor has the following components:

- Call Stack: It keeps a stack of all the execution contexts
- Web API: All the Web API like timers, dom manipulations etc.
- Microtask queue
- Macrostask queue
- Event Loop: Checks for the queues to see what needs to be finished first

## Resource Hints

These are hints that we add to our resources to modify the behaviour of fetching the resource:

1. dns-prefetch: performs domain name resolution in the background.
2. preconnect: proactively performs DNS resolution and TCP/TLS handshake.
3. prefetch: Requets non critical resources in the background. They can be skipped by the browser.
4. preload: Prioritizes fetching of critcal resources needed for the current navigation.

Whenever we send a request, its not just the HTTP request and response times, but also DNS resoltion and TCL, TLS handshake.

## Object Reference and Destructure

Whenever we use the spread operator for an object, only the top level keys are copied. Everything else is referenced back to the original object.

## PeformanceNavigationTimings

We use the PeformanceNavigationTimings API to get detailed information around the different performance metrics. Let us go through the basic events that we can capture:

1. domainLookupStart -> DNS Resolution started
2. domainLookupEnd -> DNS Resolution ended
3. connectStart -> TCP Handshake started
4. secureConnectionStart -> TLS check started
5. connectEnd -> TCP and TLS has ended
6. requestStart -> HTTP Request has started
7. responseStart -> Response start
8. responseEnd -> Response ended
9. domLoading -> Time it takes for the document to load
10. domInteractive -> Time where HTML parsing is done
11. domContentLoadedEventStart -> When the deferred and async scripts run
12. domComplete -> DOM Done
13. loadEventStart -> Loaded
14. loadEventEnd -> When all listeners have finished

## Cache Directives

- no-cache:
