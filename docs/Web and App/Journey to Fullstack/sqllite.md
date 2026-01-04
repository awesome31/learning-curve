# SQLite

SQLite is by far the most used database in the world. It requires so little setup that it can used literally in any system that requires a database.

Unlike other databases, SQLite is a file-based database. This means that it stores all of its data in a single file on the file system instead of a server and sharing data over a network. Yes we can use SQLite in production, but this database is INTENTIONALLY a small.

SQL is a defined language for databases and is agreed upon by all databases.

## Working With SQLite

We can install SQLite using Homebrew or use Docker to run SQLite. SQLite has a concept of . commands, where using _.help or .tables_ we can get the list of tables in the database.

### Select

1. `select * from artist`: Selects all rows from the artist table.Its always a good practice to select only specific columns instead of using \*.
2. `select * from artist where artistid = 174`: Filters the rows based on the condition.
3. Single quotes means a string literal and double quotes means a column name in SQL.
4. `select artistid from artist where name LIKE '%Postal Service'`: The LIKE operator is used to search for a specified pattern in a column.
5. `select * from artist limit 5 offset 5;`: The LIMIT and OFFSET keywords are used to paginate the results.
6. `select * from artist order by name`: The ORDER BY keyword is used to sort the results.

### Insert and Delete

1. `insert into artist (name) values ('Whatever')`: Inserts a new row into the artist table.
2. `delete from artist where artistid = 276`: Deletes a row from the artist table.
3. `update artist set name = 'Radiohead' where artistid = 276 returning *`: Updates a row in the artist table.

### Tables

There are only 5 types of columns in SQLite: Integer, Real, Text, Blob, NULL. It coarces the data to the type of the column. That kind of sucks for a database.

1. `create table bandmember (id integer primary key, name text unique not null, role text varchar)`: Creates a table with 3 columns. The id column is the primary key and is auto-incremented. The name column is unique and not null. The role column is a varchar.
2. `insert into bandmember (name, role) values ('John', 'Guitarist')`: Inserts a new row into the bandmember table.

### Relational Data and JOIN

We have different types of relations:

1. One to One: For example, a user has one profile picture and a profile picture belongs to one user. This is a one to one relationship.
2. One to Many: For example, a user can have many posts.
3. Many to Many: For example, a student can be enrolled in many courses and a course can have many students.

### JOIN

1. `select artist.name, album.title from album join artist on album.artistid = artist.artistid limit 3`: This is an inner join. It returns the rows that have a match in both tables.
2. `select artist.name, album.title from album left join artist on album.artistid = artist.artistid limit 3`: This is a left join. It returns all the rows from the left table and the matched rows from the right table.
3. `select artist.name, album.title from album right join artist on album.artistid = artist.artistid where artist.name = 'The Postal Service';`: This is a right join. It returns all the rows from the right table and the matched rows from the left table.
4. `select artist.name, track.name, album.title from album join artist on album.artistid = artist.artistid join track on track.albumid = album.albumid where album.title = 'IV'`: Multiple JOINs.

### Foreign Keys

Foreign keys are used to enforce referential integrity. For example, we can add a foreign key constraint to the album table to ensure that the artistid column references a valid artistid in the artist table.

**SQLite DOES NOT RESPECT FOREIGN KEY CONSTRAINTS BY DEFAULT.**
SQLLite is aggresively backward compatible. And that sucks.

`PRAGMA foreign_keys=on`: Enables foreign key constraints. BUT THIS is per connection basis. Pragmas are connection specific and are policies that are set for the connection.

### Aggregations

1. `select count(*) from album`: Returns the number of rows in the album table.

We can use GROUP BY to group the rows by a column and then apply an aggregation function to each group. HAVING is used to filter the groups.

## SQLite Features, Performance, and Security

1. SQLite is not strict about types. It will coerce the data to the type of the column. It is flexible and allows you to store any type of data in any column.
2. SQLite has some limitations which are not as bad as people think:
   - 1GB per row limit
   - 2000 columns per table limit
   - 281 TB per database limit

SQLite can scale in terms of database.

### Views

```
CREATE VIEW
  easy_tracks
AS

SELECT
  t.TrackId as id,
  ar.Name as artist,
  al.Title as album,
  t.Name as track
FROM
  Track t

JOIN
  Album al
ON
  t.AlbumId = al.AlbumId

JOIN
  Artist ar
ON
  ar.ArtistId = al.ArtistId;
```

SQLite cannot do materialized views, i.e. views that are stored in the database and are not just a query.

### Explain

1. `explain select * from track where name = 'Black Dog';`
2. `explain query plan select * from track where name = 'Black Dog'`

### Indexes

1. `PRAGMA index_list('track')`: Lists all the indexes in the track table. By default foreign keys are indexed.
2. ` create index index_track_name on Track (name)`: Creates an index on the name column of the track table.

Usually on a high write table, we should be careful about indexes as they can slow down the write operations.

### Full Text Search

`CREATE VIRTUAL TABLE track_search USING FTS5(content="easy_tracks", content_rowid='id', track, album, artist);`

This creates a virtual table that is a full-text search table. Next we can insert data into this table.

`insert into track_search select * from easy_tracks`

Now we can search for tracks using the full-text search.

`select * from track_search where track_search match 'Black Dog'`

## SQLite Extensions

There are a bunch of extensions that we can load to extend the functionality of SQLite.
