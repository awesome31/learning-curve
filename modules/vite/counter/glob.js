function setupGlob() {
  for (const [path, module] of Object.entries(
    import.meta.glob("../glob/*.png")
  )) {
    module().then((img) => console.log(img.default));
  }
}

function setupGlobEager() {
  console.log(import.meta.glob("../glob/*.png", { eager: true }));
}

export { setupGlob, setupGlobEager };
