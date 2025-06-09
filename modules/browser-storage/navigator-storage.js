async function checkNavigatorStorage() {
  if (
    navigator &&
    navigator.storage &&
    !(await navigator.storage.persisted())
  ) {
    const result = await navigator.storage.persist();

    console.log(result);

    if (result) {
      console.log("Storage persistent is enabled.");
    } else {
      console.log("Storage persistent is disabled.");
    }
  }
}

export { checkNavigatorStorage };
