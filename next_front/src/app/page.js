import Image from "next/image";
import Link from "next/link";

export default function Home() {
  return (
    <main>
      <h1>See a visualize representation of your data</h1>
      <h3><Link href="/dashboard/">Start plotting</Link></h3>
    </main>
  );
}
