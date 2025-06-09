import { openDB } from "idb";

async function setupIndexedDB() {
  const db = await openDB("myDb", 1, {
    upgrade(db) {
      console.log("This was created?");

      db.createObjectStore("order");
    },
  });

  return db;
}

async function checkIndexedDB() {
  const db = await setupIndexedDB();

  db.put("order", { id: 1, name: "John Doe", price: 100 }, "cart");
}

export { checkIndexedDB };
