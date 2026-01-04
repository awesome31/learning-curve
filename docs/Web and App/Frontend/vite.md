# Vite

Vite is a frontend build tool that is a fast and modern frontend build tool.

## Codebase for all the examples

https://github.com/awesome31/learning-curve/tree/main/modules/vite

## Things to remember

1. We can use relative paths in our script tags and vite will resolve them.
2. We can use dynamic imports to load modules on demand.
3. Each file created while building has a SHA assigned to it. The SHA changes only if the contents of the file changes.
4. We can use module scoped CSS files. This will be scoped to the specific module that actually uses it. It is done using .module.css syntax.
5. Typescript is supported out of the box. Vite does not check types though. We need to use tsc to check types.
6. We can use framework specific templates, like vue, react, svelte, etc.
7. We can add static assets to the public directory.
8. I can even import images from my JS file, and vite will automatically handle it.
9. We can use plugins to add additional functionality. For example: imagetools.

```
    import image from "./MindfulEating.png?h=200&w=200";

    function setupImage() {
    const imageDiv = document.getElementById("image");
    const newImage = document.createElement("img");
    newImage.src = image;
    imageDiv.appendChild(newImage);
    }

    export { setupImage };
```

10. We can do JSON named exports and imports using Vite by default. Not only that, we can also pull a specific property of a JSON in our bundle instead of the whole JSON file.
11. We can do Glob imports to import multiple files at once instead of one.
