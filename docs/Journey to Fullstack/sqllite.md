# SQLite

SQLite is by far the most used database in the world. It requires so little setup that it can used literally in any system that requires a database.

Unlike other databases, SQLite is a file-based database. This means that it stores all of its data in a single file on the file system instead of a server and sharing data over a network. Yes we can use SQLite in production, but this database is INTENTIONALLY a small.

SQL is a defined language for databases and is agreed upon by all databases.

## Working With SQLite

We can install SQLite using Homebrew or use Docker to run SQLite. SQLite has a concept of . commands, where using _.help or .tables_ we can get the list of tables in the database.

### SELECT

1. `select * from artist`: Selects all rows from the artist table.Its always a good practice to select only specific columns instead of using \*.
2. `select * from artist where artistid = 174`: Filters the rows based on the condition.
3. Single quotes means a string literal and double quotes means a column name in SQL.
