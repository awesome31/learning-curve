import Link from "next/link";
import "doodle.css/doodle.css";
import "./globals.css";

export const metadata = {
  title: "Note Passer",
  description: "Example app",
};

export default async function RootLayout({ children }) {
  return (
    <html lang="en">
      <body className="doodle">
        <nav>
          <h1>
            <Link href="/">Note Passer</Link>
          </h1>
        </nav>
        {children}
      </body>
    </html>
  );
}
