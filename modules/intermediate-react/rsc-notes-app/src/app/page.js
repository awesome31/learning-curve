import Link from "next/link";

export default function Home() {
  return (
    <div>
      <ul>
        <li>
          <Link href="/my">My Notes</Link>
        </li>
        <li>
          <Link href="/write">Write a Note</Link>
        </li>
        <li>
          <Link href="/teacher">Secret Teacher Feed</Link>
        </li>
      </ul>
    </div>
  );
}
