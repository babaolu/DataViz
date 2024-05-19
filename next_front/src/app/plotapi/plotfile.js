import React from 'react';
import * as Plot from "@observablehq/plot";

class Document {
  constructor() {
    this.documentElement = new Element(this, "html");
  }
  createElementNS(namespace, tagName) {
    return new Element(this, tagName);
  }
              
  createElement(tagName) {
    return new Element(this, tagName);
  }
              
  createTextNode(value) {
    return new TextNode(this, value);
  }
              
  querySelector() {
    return null;
  }
              
  querySelectorAll() {
    return [];
  }
}

class Style {
  static empty = new Style();
  setProperty() {}
  removeProperty() {}
}

class Element {
  constructor(ownerDocument, tagName) {
    this.ownerDocument = ownerDocument;
    this.tagName = tagName;
    this.attributes = {};
    this.children = [];
    this.parentNode = null;
  }
  setAttribute(name, value) {
    this.attributes[name] = String(value);
  }
  setAttributeNS(namespace, name, value) {
    this.setAttribute(name, value);
  }
  getAttribute(name) {
    return this.attributes[name];
  }
  getAttributeNS(name) {
    return this.getAttribute(name);
  }
  hasAttribute(name) {
    return name in this.attributes;
  }
  hasAttributeNS(name) {
    return this.hasAttribute(name);
  }
  removeAttribute(name) {
    delete this.attributes[name];
  }
  removeAttributeNS(namespace, name) {
    this.removeAttribute(name);
  }
  addEventListener() {
    // ignored; interaction needs real DOM
  }
  removeEventListener() {
    // ignored; interaction needs real DOM
  }
  dispatchEvent() {
    // ignored; interaction needs real DOM
  }
  append(...children) {
    for (const child of children) {
      this.appendChild(
        child?.ownerDocument ? child : this.ownerDocument.createTextNode(child)
      );
    }
  }
  appendChild(child) {
    this.children.push(child);
    child.parentNode = this;
    return child;
  }
  insertBefore(child, after) {
    if (after == null) {
      this.children.push(child);
    } else {
      const i = this.children.indexOf(after);
      if (i < 0) throw new Error("insertBefore reference node not found");
      this.children.splice(i, 0, child);
    }
    child.parentNode = this;
    return child;
  }
  querySelector() {
    return null;
  }
  querySelectorAll() {
    return [];
  }
  set textContent(value) {
    this.children = [this.ownerDocument.createTextNode(value)];
  }
  set style(value) {
    this.attributes.style = value;
  }
  get style() {
    return Style.empty;
  }
  toHyperScript() {
    return React.createElement(
      this.tagName,
      this.attributes,
      this.children.map((c) => c.toHyperScript())
    );
  }
}

class TextNode {
  constructor(ownerDocument, nodeValue) {
    this.ownerDocument = ownerDocument;
    this.nodeValue = String(nodeValue);
  }
  toHyperScript() {
    return this.nodeValue;
  }
}
                        
function PlotFigure({options}) {
  return Plot.plot({ ...options, document: new Document() }).toHyperScript();
}

export default function App({data}) {
  const plotValues = {x: data[1], y: data[2]};
  const plotOptions = {grid: true};
  if (data[4]) {  // Setting properties only if the category is specified
    plotValues["stroke"] = data[4];
    plotOptions["color"] = {legend: true};
  }

  const plotStyles = (data[1]) ? {  // Saving plot or text graph
    area:  Plot.areaY(data[0], plotValues),
    bar:  Plot.barY(data[0], plotValues),
    dot:  Plot.dot(data[0], plotValues),
    line: Plot.lineY(data[0], plotValues)
  } : {
    text: Plot.text([data[0]], {frameAnchor: "middle"})
  };
 
  // Isolating the selected plotstyles
  const collectedPlots = (data[1]) ? data[3].map((x) => plotStyles[x]): [plotStyles["text"]];
  plotOptions["marks"] = [Plot.frame(), ...collectedPlots];
  return (
    <PlotFigure
      options = {plotOptions}/>
  );
}            
