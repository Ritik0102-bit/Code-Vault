# HTML

## Hyper Text Markup Language

HTML is the code that is used to structure a web page and its content.

The component used to design the structure of websites are called HTML tags.

### First HTML File

**index.html**

It is the default name for a website's homepage

### HTML Tag

A container for some content or other HTML tags

```html
<p> This is a paragraph</p>
```

**Element**: Content

### Basic HTML Page

```html
<!DOCTYPE html>

<html>

<head>

<title>My First Page</title>

</head>

<body>

<p>hello world</p>

</body>

</html>
```

- tells browser you are using HTML5
- root of an html document
- container for metadata
- contains all data rendered by the browser
- page title
- paragraph tag

### Quick Points

- Html tag is parent of head & body tag
- Most of html elements have opening & closing tags with content in between
- Some tags have no content in between, eg - `<br>`
- We can use inspect element/view page source to edit html

### Comments in HTML

```html
<!-- This is an HTML Comment -->
```

This is part of code that should not be parsed.

- **HTML is NOT case sensitive**
  - `<p>` = `<P>`
  - `<html>` = `<HTML>`
  - `<head>` = `<HEAD>`
  - `<body>` = `<BODY>`

---

## Level 2

### Basic HTML Tags

**Attributes** are used to add more information to the tag

#### HTML Attributes

```html
<html lang="en">
```

### Heading Tag

Used to display headings in HTML

- `h1` (most important)
- `h2`
- `h3`
- `h4`
- `h5`
- `h6` (least important)

### Paragraph Tag

Used to add paragraphs in HTML

```html
<p> This is a sample paragraph </p>
```

### Anchor Tag

Used to add links to your page

```html
<a href="https://google.com"> Google </a>
```

### Image Tag

Used to add images to your page

```html
<img src="/image.png" alt="Random Image">
```

(relative url)

### Br Tag

Used to add next line (line breaks) to your page

```html
<br>
```

### Bold, Italic & Underline Tags

Used to highlight text in your page

```html
<b> Bold </b>

<i> Italic </i>

<u> Underline </u>
```

### Big & Small Tags

Used to display big & small text on your page

```html
<big> Big </big>

<small> Small </small>
```

### Hr Tag

Used to display a horizontal ruler, used to separate content

```html
<hr>
```

### Subscript & Superscript Tag

Used to display subscript and superscript content

```html
<sub> subscript </sub>

<sup> superscript </sup>
```

Example: H₂O, A + B^n

### Pre Tag

Used to display text as it is (without ignoring spaces & next line)

```html
<pre> This

is a sample

text.

</pre>
```

---

## Level 3

### Page Layout Techniques

#### Using Semantic Tags for Layout

```html
<header>

<main>

<footer>
```

#### Using the Right Tags

##### Inside Main Tag

**Section Tag**

```html
<section>
```

For a section on your page

**Article Tag**

```html
<article>
```

For an article on your page

**Aside Tag**

```html
<aside>
```

For content aside main content (ads)

### Revisiting Anchor Tag

```html
<a href="https://google.com" target="_blank"> Google </a>
```

(for new tab)

```html
<a href="https://google.com"> <img src="link"> </a>
```

(clickable pic)

### Revisiting Image Tag

```html
<img src="link" height="50px">
```

(set height)

```html
<img src="link" width="50px">
```

(set width)

### Div Tag

Div is a container used for other HTML elements

**Block Element** (takes full width)

List of Block Elements:
- `<address>`
- `<article>`
- `<aside>`
- `<blockquote>`
- `<canvas>`
- `<dd>`
- `<div>`
- `<dl>`
- `<dt>`
- `<fieldset>`
- `<figcaption>`
- `<figure>`
- `<footer>`
- `<form>`
- `<h1>-<h6>`
- `<header>`
- `<hr>`
- `<li>`
- `<main>`
- `<nav>`
- `<noscript>`
- `<ol>`
- `<p>`
- `<pre>`
- `<section>`
- `<table>`
- `<tfoot>`
- `<ul>`
- `<video>`

### Span Tag

Span is also a container used for other HTML elements

**Inline Element** (takes width as per size)

List of Inline Elements:
- `<a>`
- `<abbr>`
- `<acronym>`
- `<b>`
- `<bdo>`
- `<big>`
- `<br>`
- `<button>`
- `<cite>`
- `<code>`
- `<dfn>`
- `<em>`
- `<i>`
- `<img>`
- `<input>`
- `<kbd>`
- `<label>`
- `<map>`
- `<object>`
- `<tt>`
- `<var>`
- `<output>`
- `<q>`
- `<samp>`
- `<script>`
- `<select>`
- `<small>`
- `<span>`
- `<strong>`
- `<sub>`
- `<sup>`
- `<textarea>`
- `<time>`

---

## Level Pro

### List in HTML

Lists are used to represent real life list data.

#### Unordered List

```html
<ul>
  <li> Apple </li>
  <li> Mango </li>
</ul>
```

#### Ordered List

```html
<ol>
  <li> Apple </li>
  <li> Mango </li>
</ol>
```

### Tables in HTML

Tables are used to represent real life table data.

- `<tr>` - used to display table row
- `<td>` - used to display table data
- `<th>` - used to display table header

#### Example Table

```html
<table>
  <tr>
    <th> Roll No </th>
    <th> Name </th>
  </tr>
  <tr>
    <td> 1664 </td>
    <td> Shradha </td>
  </tr>
</table>
```

| Roll No | Name    |
|---------|---------|
| 1664    | Shradha |

### Caption in Tables

```html
<caption> Student Data </caption>
```

| Name    | Roll No |
|---------|---------|
| Shradha | 1664    |

*Student Data*

### thead & tbody in Tables

```html
<thead> <!-- to wrap table head -->
<tbody> <!-- to wrap table body -->
```

### colspan Attribute

```html
colspan="n"
```

Used to create cells which spans over multiple columns

### Form in HTML

Forms are used to collect data from the user

Examples: sign up/login/help requests/contact me

```html
<form>
  form content
</form>
```

### Action in Form

```html
<form action="/action.php">
```

Action attribute is used to define what action needs to be performed when a form is submitted

### Form Element: Input

```html
<input type="text" placeholder="Enter Name">
```

### Label

```html
<input type="radio" value="class X" name="class" id="id1">
<label for="id1"> Class X </label>

<input type="radio" value="class Y" name="class" id="id2">
<label for="id2"> Class Y </label>
```

### Class & Id

```html
<div id="id1" class="group1">
</div>

<div id="id2" class="group1">
</div>
```

### Checkbox

```html
<input type="checkbox" value="class X" name="class" id="id1">
<label for="id1"> Class X </label>

<input type="checkbox" value="class Y" name="class" id="id2">
<label for="id2"> Class Y </label>
```

### Textarea

```html
<textarea name="feedback" id="feedback" placeholder="Please add Feedback">
</textarea>
```

### Select

```html
<select name="city" id="city">
  <option value="Delhi"> Delhi </option>
  <option value="Mumbai"> Mumbai </option>
  <option value="Bangalore"> Bangalore </option>
</select>
```

### Iframe Tag

Website inside website

```html
<iframe src="link"> Link </iframe>
```

### Video Tag

```html
<video src="myVid.mp4"> My Video </video>
```

#### Attributes

- `controls`
- `height`
- `width`
- `loop`
- `autoplay`

