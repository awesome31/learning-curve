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
