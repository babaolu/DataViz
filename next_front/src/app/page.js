import Image from "next/image";
import "./main.css";
import Link from "next/link";
import frontCover from "/public/images/Cover1.jpg";

export default function Home() {
  return (
    <main>
      <div className="landing"></div>
      <div className="describe">
      <h1>Get a visualized representation of your data</h1>
      <h3>Either with your file...</h3>
      <h4>Or you Generate it.</h4>
      <h2><Link href="/dashboard/">Start plotting!</Link></h2>
      <Image
        src={frontCover}
	width={560}
	height={360}
	alt="Example plot"
	className="coverImage"
	/>
      </div>
    </main>
  );
}
