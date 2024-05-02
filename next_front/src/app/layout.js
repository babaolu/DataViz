import { Inter } from "next/font/google";
import "./globals.css";
import Link from "next/link";

const inter = Inter({ subsets: ["latin"] });

export const metadata = {
  title: "DataViz",
  description: "Vizualizing datasets",
};

export default function RootLayout({ children }) {
  return (
    <html lang="en">
      <body className={inter.className}>
        <Header />
        {children}
	<Footer />
      </body>
    </html>
  );
}

function Header() {
  return (
    <header>
      <nav><Link href="/">Home</Link></nav>
      <nav><Link href="/dashboard">Dashboard</Link></nav>
      <h1 id="appName"><Link href="/">DataViz</Link></h1>
      <nav>Login</nav>
    </header>
  );
}

function Footer() {
  return (
    <footer>
    <p>&#xA9;2024 DataViz</p>
    </footer>
  );
}
