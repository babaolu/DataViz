import { Inter } from "next/font/google";
import "./globals.css";
import Link from "next/link";

const inter = Inter({ subsets: ["latin"] });

export const metadata = {
  title: "DataViz",
  description: "Vizualizing datasets",
};

/**
*  Specifies a uniform layout throughout all pages
*/
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

/**
* Specifies the header layout for all pages
*/
function Header() {
  return (
    <header>
      <nav><Link href="/">Home</Link></nav>
      <nav><Link href="/dashboard">Dashboard</Link></nav>
      <h1 id="appName"><Link href="/">DataViz</Link></h1>
      <nav id="login">Login</nav>
    </header>
  );
}

/**
* Specifies the footer layout for all pages
*/
function Footer() {
  return (
    <footer>
    <p>&#xA9;2024 DataViz</p>
    </footer>
  );
}
