"use server";
import { AsyncDatabase } from "promised-sqlite3";

export default async function postNote(formData) {
  console.log("postNote called", formData);

  const from = formData.get("from_user");
  const to = formData.get("to_user");
  const note = formData.get("note");

  if (!from || !to || !note) {
    throw new Error("All fields are required");
  }

  const db = await AsyncDatabase.open("./notes.db");
  await db.run(
    "INSERT INTO notes (from_user, to_user, note) VALUES (?, ?, ?)",
    [from, to, note]
  );
}
