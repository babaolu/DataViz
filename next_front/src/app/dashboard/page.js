'use client';

import { useState } from 'react';
import Papa from 'papaparse';
import Image from 'next/image';
import App from '@/app/plotapi/plotfile';
import ctoj from '@/app/utilapi/csvtojson';
import "../main.css";

export default function Dashboard() {
  const [data, setData] = useState();
  const [col, setCol] = useState(null);
  const [xaxis, setXaxis] = useState(null);
  const [yaxis, setYaxis] = useState(null);

  const submitFile = (event) => {
    event.preventDefault(); 
    const reader = new FileReader();
    reader.readAsText(data);
    reader.onload = () => {
      if (data.type === 'text/csv')
      {
        const { data: cval, errors } = Papa.parse(reader.result);
	if (errors.length === 0)
	  setCol(ctoj(cval));
      } else
        setCol(JSON.parse(reader.result));

      if (!xaxis)
        setXaxis(Object.keys(JSON.parse(reader.result)[0])[0])
      if (!yaxis)
        setYaxis(Object.keys(JSON.parse(reader.result)[0])[1])
      console.log(data.type, col);
    };
  };

  async function submitFormula(event) {
    event.preventDefault();

    try {
      const formData = new FormData(event.currentTarget);
      const formObj = {};
      formData.forEach((value, key) => formObj[key] = value);

      const response = await fetch("http://localhost:8080/backspring/gen_pdata", {
        method: 'POST',
	mode: "cors",
	headers: {
	  "Content-Type": "application/json",
	  "Accept": "application/json"
	},
        body: JSON.stringify(formObj),
      });
     // const response = await fetch("http://127.0.0.1:8080/First-spring/gen_data");

      const result = await response.json();
      setCol(result);
      console.log(result);
      setXaxis(Object.keys(result[0])[0]);
      setYaxis(Object.keys(result[0])[1]);
      // Handle response if needed
    } catch (error) {
      console.error('Error uploading formula:', error);
    }
  };


  return (
    <main>
      <div id="view-pane">
        { col ? <App data={[col, xaxis, yaxis]} /> : '' }
      </div>
      <section id="input-section">
        <form method="post" encType="multipart/form-data"
	  onSubmit={submitFile}>
          <label htmlFor="file">Input File</label>
          <input id="file" type="file" name="file-input" accept=".csv,.json"
            onChange={(event) => setData(event.target.files[0])}/>
	  <br />
          <label htmlFor="x">X-axis label</label>
          <input id="x" type="text" name="x-legend"
	    onChange={(event) => setXaxis(event.target.value)}/>
	  <br />
          <label htmlFor="y">Y-axis label</label>
          <input id="y" type="text" name="y-legend"
	    onChange={(event) => setYaxis(event.target.value)}/>
	  <br />
          <button type="submit">Plot File</button>
        </form>
        <br/>
        <form method="post" encType="multipart/form-data"
	  onSubmit={submitFormula}>
          <label htmlFor="formula">Type Formula</label>
          <input id="formula" type="text"name="formula_input" />
	  <br />
          <label htmlFor="size">Size</label>
          <input id="size" type="text"name="sample_size" />
	  <br />
          <label htmlFor="start">Start Point</label>
          <input id="start" type="text"name="start_point" />
	  <br />
          <label htmlFor="interval">Interval</label>
          <input id="interval" type="text"name="sample_interval" />
	  <br />
          <button type="submit" id="push">Plot Formula</button>
        </form>
      </section>
    </main>
  );
}
