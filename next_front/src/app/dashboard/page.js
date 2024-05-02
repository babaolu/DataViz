'use client';

import { useState } from 'react';
import Papa from 'papaparse';
import Image from 'next/image';
import App from '@/app/plotapi/plotfile'
import ctoj from '@/app/utilapi/csvtojson'

export default function Dashboard() {
  return (
    <main>
      <div className="view-pane">
      </div>
      <section>
        <InputSection/>
      </section>
    </main>
  );
}

function InputSection() {
  const [data, setData] = useState();
  const [col, setCol] = useState(null);

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
      console.log(data.type, col);
    };
    /*try {
      const response = await fetch('/api/upload', {
        method: 'POST',
        body: file
      });
      // Handle response if needed
    } catch (error) {
      console.error('Error uploading file:', error);
    }*/
  };

  const submitFormula = (event) => {
    event.preventDefault();
    const reader = new FileReader();
    reader.readAsText(data);
    
    console.log(reader.result);

    /*try {
      const response = await fetch('/api/upload', {
        method: 'POST',
        body: file
      });
      // Handle response if needed
    } catch (error) {
      console.error('Error uploading file:', error);
    }*/
  };


  return (
    <div>
    { col ? <App data={col} /> : '' }
    <form method="post" encType="multipart/form-data">
      <label htmlFor="file-input">Input File</label>
      <input id="file" type="file" name="file-input" accept=".csv,.json"
        onChange={(event) => setData(event.target.files[0])}/>
      <button type="button" onClick={(event) => submitFile(event)}>Plot File</button>
      <br/>
      <label htmlFor="formula-input">Type Formula</label>
      <input id="formula" type="text"name="formula-input" />
      <button type="button" onClick={submitFormula}>Plot</button>
    </form>
    </div>
  );
}
