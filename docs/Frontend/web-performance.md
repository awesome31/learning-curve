# Web Performance

## Importance of Web Performance

### User experience

How well your website meets or exceeds the expectations of the user. For an effective communication, any request should be responded within 2 seconds.

### Search Engine Optimization (SEO)

SEO is the process of making your site searchable and findable by search engines. This involves optimizing the site for search engines and ensuring that it meets the search engine's search algorithms. This is primarily for public web pages. You need to be fast to rank well.

### Online Advertising

This is specific for ecommerce stores.

## Legacy Metrics

To understand optimisations of any web application that we have built, we need to understanding what measuring web performance means. There are multiple ways through which we can measure web performance. In the below sections we will talk about each one by one.

### Reading Waterfall Charts

Each color in the waterfall chart represents a different aspect of the page load process. The colors are as follows:

- Blue: HTML Document
- Purple: CSS
- Yellow: JavaScript
- Green: Images
- Light Blue: Fonts
- Grey: Fetch/Other

Waterfalls charts help us in understaning the sequence of events that occur during the page load process.

### DOMContentLoaded Event

DOMContentLoaded is a legacy metric that was used to see the performance of a webpage. This event is fired when the HTML and the deffered Javascript have completed loading. The structure of the page is done.

### Load Event

The HTML and all **known** resources have been downloaded and rendered. The load event is fired when the loader in the browser stops.

**_The problem with the above two legacy metrics was that load meant that the document is ready. But with client side rendering, the document is always ready but JS needs to be executed._**

## Core Web Vitals

Core Web Vitals are a set of metrics that tracks:

1. How fast your site visibly loads?
2. How smooth things load?
3. How quickly users can interact?

### Largest Contentful Paint (LCP)

The question that LCP metric tries to answer and reason about is: **How fast does the MOST Important thing on the page load?**

Now the question comes, what is the Largest or the Most important element? It can be one of the following:

1. img
2. video
3. text element
4. css: background image

The rules are opacity > 0, Size < 100% and low entropy element. Entropy refers to the bits per pixel. For example, if we have a 3.9MB image that we are displaying in 2800x1200 pixel then the entropy is 31M/3.3M = 9.39. Entropy measures the amount of information in the image.

Largest element on the page is the number of pixels that are calculated. More often then not, it is the hero image. It stops after first user interaction. For google to consider LCP good, it needs to be 2.5s or less.

### Cumulative Layout Shift (CLS)

The question that CLS metric tries to answer and reason about is: **How smooth and predictably elements load into the page?**

CLS is calculated using Impact Fraction x Distance Fraction. Lets assume the viewport height is 768px, the impact size is 708px. Therefore, the impact fraction is 708/768 = 0.91. Distance fraction is 180px/768px = 0.23. Therefore, the CLS is 0.91 \* 0.23 = 0.21. **_CLS applies to both width and height._**

CLS is a sum of all the individual layout shifts that occur during the page load process. 0.1 is a good score for CLS.

### Flame Charts

Flame charts are used to understand the execution of tasks and functions when running a web application. Flame charts are important to understand becuase there is only 1 MAIN thread that is responsible for handling user events, layouts, paint and running Javascript.

### Interaction to Next Paint

This metric tries to answer the question: **How Interactable is the site?**

Interactions can be clicks, typing, dragging. Scrolling is not an interaction. INP measures all the interactions that happen throughout a session and sees how long it takes for the next paint. A good score is 200ms.

### Legacy Metrics

- First Input Delay (FID): It measured the time between the first interaction and the first paint.
- Time to First Byte (TTFB): It measured the time between the first byte of the response and the first paint. 800ms.
- First Contentful Paint (FCP): How fast your site visibly loads the something.

## Capturing Performance

### Performance API in browser

All performance metrics are available in the browser through APIs.

```
performance.now()
performance.mark()
performance.measure()

/**
 * Page Navigation
 * Resource Navigation
 Performance events
 Custom events
 */

performance.getEntries()
```

We also have a performance obersever that gives us the data WHEN the main thread is not doing anything. We have a package from google, **web-vitals**, that helps us in capturing performance metrics. Not all browsers support all the metrics. LCP, CLS and INP are not supported on any Webkit related browser. (iOS)

## Tests and Tools

Now that we know what metrics we need to capture, let us try and understand what tools one can use for the same. There are 3 ways of collecting data: Lab Data, Synthetic Data and Field Data.

### Statistics

It is important to understand a few terms in statistics to really understand the tools that are there for measuring web performance. Lab Data is Diagnostic whereas field data is experience.

- Average: Sum of all the score by the total number of scores. Average is not the best way to understand the metrics correctly.
- Percentiles: Percentiles are the values that divide the data into 100 equal parts. 90th percentile is the value that is greater than 90% of the data. Usually people calculate the p95 or p99.

### Google Lighthouse

Lighthouse is a tool that helps you measure the performance of your website. It is widely used and is the most common way to measure performance metrics.

1. You can create your own custom device size to emulate the most common users.
2. You can create your own network profile, instead of the common ones like 3G, 4G, Slow 4G.
3. You can run lighthouse using the dev tools environment.

With lighthouse score and the performance tab, we can diagnose performance issues.

### Chrome User Experience Report (CRUX)

Chrome User Experience Report is a tool that helps you measure the performance of your website. It is a free service provided by Google.

- It represents field data.
- Any logged in Chrome user's data is sent back to the Google services and reported.
- 28 day rolling average. It is stored in Google Big Query.

Good resource to get the chrome user experience report are:

1. https://requestmetrics.com/resources/tools/crux/
2. https://pagespeed.web.dev/
3. https://www.webpagetest.org/: This tool helps you configure a lot of parameters.

## Setting Performance Goals

The raw numbers and the percieved performance can be way different. There is a psychological aspect to it.

1. People want to START.
2. Bored waits feel slower.
3. Anxious waits feel slower.
4. Unexplained waits feel slower.
5. Uncertain waits feel slower.
6. People wait for value.

### Who gets to decide whats fast?

1. User Experience: Bounce Rates, Session Time, Add-to-Cart Rate, Conversion Rate. We should map the business metrics with the performance metrics.
2. Competitors: You need to be 20% faster than your competitors. The number 20 comes from Weber's Law.
3. SEO PageRank

### Who are the Users?

Mobile users are 62% of the total users. So mobile users are the primary users. 71% of people are on Android, 29% are on iOS.

## Improving Performance

Always focus on the easiest fixes for your worst metric from real user data.

### Time to First Byte (TTFB)

TTFB is how long it takes your host to respond back to the request.

- Check your RUM or cRUX data for TTFB.
- **Compress HTTP Responses**: Reduce the size of plain text HTML, CSS, and JavaScript. We can use gzip or brotli. The client sends a header called `Accept-Encoding` to the server. The server responds with `Content-Encoding`: br or gzip.
- **Efficient Protocols**: With HTTP1, we have a connection per request. With HTTP2, we have a connection per domain. With HTTP3, we have a connection per origin. HTTP3 uses QUIC instead of TCP. Requires HTTPS for HTTP2/3.
- **Host Capacity and Proximity**: Right-Size your host for your workload. We can also have a CDN.

100% operations works. We did not change any code or content.

### First Contentful Paint (FCP)

FCP depends on TTFB too. FCP checks for the time it takes to render the first content on the page.

- Check your RUM or cRUX data for FCP.
- **Remove Sequence Chains**: CSS and Fonts are Render Blocking. They prevent the page from rendering until complete. CSS @import is a sequence chain. JS and CSS both chains can happen. The way to fix it to use a module bundlers. Instead of the browser resolving the dependencies, the module bundler does it.
- **Preloading Resources**: Start critical path resources as soon as possible. link rel="preload" is a way to do it. We can reload style, script, image, font, fetch. (CORS supported for font and fetch)
- **Lazy Loading Resources**: Non-Critical path resources can be loaded later.

```
    <script>: Downloads and executes the script
    <script defer>: Downloads the script and executes after the DOM is ready
    <script async>: Downloads the script and executes as soon as it is available
```

We should almost always use `defer`. Execution order is guaranteed.

### Largest Contentful Paint (LCP)

How fast does the largest contentful paint happen? By improving TTFB and FCP, we can improve LCP.

- Check your RUM or cRUX data for LCP.
- Lazy Loading Images: loading='lazy' can be done for non-critical images.
- Eager Loading Images: fetchpriority='high' can be done for critical images.
- Image Optimization: We can use different image formats for different use cases. WebP is a good format for images.

```
    <picture class="image">
        <source srcset="/image.webp?width=600" media = "(max-width: 600px)">
        <img src="image.jpg" alt="Image">
    </picture>
```

- Caching: Server caching can be done using CDN. We can also use browser response caching. The Cache-Control header is used for this. The server can set this cache control heder.

### Cumulative Layout Shift (CLS)

- Check your RUM or cRUX data for CLS.
- **Layout Size Hints**: We can use layout size hints to prevent CLS.

### Interaction to Next Paint (INP)

- Check your RUM or cRUX data for INP.
- **Yield the Main Thread**: We can use yield the main thread to prevent INP. All we need to do is schedule the code to run in the future. Allow other work to run. requestAnimationFrame schedules code to run just before the next paint.
