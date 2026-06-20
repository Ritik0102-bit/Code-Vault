// Window Object
// The window object represents an open window in a browser. It is browser’s object (not JavaScript’s)
// & is automatically created by browser.

// It is a global object with lots of properties & methods.

// What is DOM?

// When a web page is loaded, the browser creates a Document Object Model (DOM) of the page
// The DOM is a tree-like structure that represents the elements of the web page as objects. Each element in the HTML document is represented as a node in the DOM tree, and these nodes can be accessed and manipulated using JavaScript.


// DOM Manipulation :-

// Selecting with id
// document.getElementById(“myId”)

// Selecting with class
// document.getElementsByClassName(“myClass”)

// Selecting with tag
// document.getElementsByTagName(“p”)


// Query Selector :-

// document.querySelector(“#myId / .myClass / tag”)
//returns first element

// document.querySelectorAll(“p”)



// Properties :-

// tagName : returns tag for element nodes
// innerText : returns the text content of the element and all its children
// innerHTML : returns the plain text or HTML contents in the element
// textContent : returns textual content even for hidden elements


// Attributes :- Attributes are properties of an element that provide additional information about the element. They are defined in the HTML markup and can be accessed and manipulated using JavaScript.

// id : a unique identifier for the element
// class : a space-separated list of classes for the element
// src : the URL of an image or other media element
// href : the URL of a link element
// alt : alternative text for an image element

//getAttribute(attrbitueName) : returns the value of the attribute
//setAttribute(attributeName, attributeValue) : sets the value of the attribute
//removeAttribute(attributeName) : removes the attribute from the element



// Style :-

// node.style : returns the inline style of the element as a CSSStyleDeclaration object. You can use this object to get or set individual style properties.

node.style.property // returns the value of the property
node.style.property = value // sets the value of the property


// Insert Element :-

let el = document.createElement("div")
node.append( el ) //adds at the end of node (inside)
node.prepend( el ) //adds at the start of node (inside)
node.before( el ) //adds before the node (outside)
node.after( el ) //adds after the node (outside)

// Delete Element

node.remove( ) //removes the node


// Methods :-

// createElement() : creates an element node
//createTextNode() : creates a text node
//createComment() : creates a comment node
//createDocumentFragment() : creates a document fragment node
//appendChild() : appends a node to the end of the list of children of a specified parent node
//insertBefore() : inserts a node before a reference node as a child of a specified parent node
//removeChild() : removes a child node from the DOM
//replaceChild() : replaces a child node of a specified parent node with a new node
//cloneNode() : clones a node
//contains() : returns true if the specified node is a descendant of the current node