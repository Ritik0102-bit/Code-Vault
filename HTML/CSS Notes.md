# CSS

## Cascading Style Sheet

CSS is a styling language, not a programming language. It is used to describe the style of a document.

**Note:** For styling there should be some content, which is why we study HTML before CSS.

When you remove CSS from websites, you're left with plain unstyled content.

---

## Level 1

### Basics of CSS

CSS is the makeup of the web - it describes how HTML elements are displayed.

### Basic Syntax

```css
h1 {
  color: red;
}
```

- **Selector**: `h1`
- **Property**: `color`
- **Value**: `red`

The semicolon shows that one property has ended & it is important to put this even though it won't incur error.

### Including Style

#### Inline Style

Writing style directly inline on each element:

```html
<h1 style="color: red"> Apna College </h1>
```

#### Internal Style (Style Tag)

Style is added using the `<style>` element in the same document:

```html
<style>
  h1 {
    color: red;
  }
</style>
```

#### External Stylesheet (Best Way)

Writing CSS in a separate document & linking it with HTML file:

```html
<link rel="stylesheet" href="styles.css">
```

**Note:** An inline style will override external and internal styles.

### Color Property

Used to set the color of foreground text:

```css
color: red;
color: pink;
color: blue;
color: green;
```

### Background Color Property

Used to set the color of background:

```css
background-color: red;
background-color: pink;
background-color: blue;
background-color: green;
```

### Color Systems

#### RGB

```css
color: rgb(255, 0, 0);    /* Red */
color: rgb(0, 255, 0);    /* Green */
```

#### Hexadecimal (Hex)

```css
color: #ff0000;           /* Red */
color: #00ff00;           /* Green */
```

**Tip:** You don't have to think on colors on your own. Use color picker tools online or search online.

### Selectors

| Selector Type | Syntax | Example |
|---------------|--------|---------|
| Universal Selector | `*` | `* { }` |
| Element Selector | `element` | `h1 { }` |
| Id Selector | `#id` | `#myId { }` |
| Class Selector | `.class` | `.myClass { }` |

### Practice Set 1

**Q1:** Create a simple div with an id "box". Add some text content inside the div. Set its background color to blue.

**Q2:** Create 3 headings with h1, h2 & h3. Give them all a class "heading" & set color of "heading" to red.

**Q3:** Create a button & set its background color to:
- green using css stylesheet
- blue using `<style>` tag
- pink using inline style

### Text Properties

#### text-align

```css
text-align: left / right / center;
```

**Note:** Text alignment doesn't mean align according to the page; i.e. right does not mean on the page's right side but the parent's right side.

In CSS3 (latest CSS), `start` and `end` are introduced for language support like Arabic.

#### text-decoration

```css
text-decoration: underline / overline / line-through;
```

You can also add style (wavy, dotted) or color:

```css
text-decoration: underline wavy red;
```

Use `none` to remove decoration from hyperlinks.

#### font-weight

```css
font-weight: normal / bold / bolder / lighter;
font-weight: 100 to 900;  /* Numeric values */
```

Font-weight shows how dark or light our text is. Values range from 100 to 900.

#### font-family

```css
font-family: arial;
font-family: arial, roboto;  /* Fallback mechanism */
```

You can write multiple families as a fall-back mechanism.

#### line-height

```css
line-height: 2px;
line-height: 3;
line-height: normal;
```

#### text-transform

```css
text-transform: uppercase / lowercase / capitalize / none;
```

### Using Font Awesome Icons

Font Awesome is a popular icon library that provides thousands of high-quality icons.

#### Include Font Awesome via CDN (Content Delivery Network)

Add this link in the `<head>` section of your HTML file:

```html
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/7.0.1/css/all.min.css" integrity="sha512-2SwdPD6INVrV/lHTZbO2nodKhrnDdJK9/kg2XD1r9uGqPo1cUbujc+IYdlYdEErWNu69gVcYgdxlmVmzTWnetw==" crossorigin="anonymous" referrerpolicy="no-referrer" />
```

#### Using Font Awesome Icons

Once included, you can use icons by adding the appropriate classes:

```html
<i class="fas fa-heart"></i>           <!-- Solid heart icon -->
<i class="far fa-star"></i>            <!-- Regular star icon -->
<i class="fab fa-facebook"></i>        <!-- Facebook brand icon -->
```

Common Font Awesome prefixes:
- `fas` - Solid icons
- `far` - Regular icons
- `fal` - Light icons
- `fad` - Duotone icons
- `fab` - Brand icons

#### Styling Font Awesome Icons

You can style icons using CSS like any other element:

```css
i {
  color: red;
  font-size: 30px;
  margin: 10px;
}

i:hover {
  color: blue;
  transform: scale(1.5);
  transition: all 0.3s ease;
}
```

**Note:** Font Awesome icons are essentially text, so you can apply all text and CSS properties to them!

### Units in CSS

#### Absolute Units

- **pixels (px)** - Most commonly used
- 96px = 1 inch
- cm, mm, inch & others are also available but pixels is the most used

```css
font-size: 2px;
```

### Practice Set 2

**Q1:** Create a heading centred on the page with all of its text capitalized by default.

**Q2:** Set the font family of all the content in the document to "Times New Roman".

**Q3:** Create one div inside another div.
- Set id & text "outer" for the first one & "inner" for the second one
- Set the outer div text size to 25px & inner div text size to 10px

---

## Level 2

### Box Model in CSS

The CSS box model consists of:

```
┌─────────────────────────────────────┐
│           Margin                    │
│  ┌───────────────────────────────┐  │
│  │       Border                  │  │
│  │  ┌─────────────────────────┐  │  │
│  │  │    Padding              │  │  │
│  │  │  ┌─────────────────┐    │  │  │
│  │  │  │    Content      │    │  │  │
│  │  │  └─────────────────┘    │  │  │
│  │  └─────────────────────────┘  │  │
│  └───────────────────────────────┘  │
└─────────────────────────────────────┘
```

### Height

By default, it sets the content area height of the element:

```css
div {
  height: 50px;
}
```

### Width

By default, it sets the content area width of the element:

```css
div {
  width: 50px;
}
```

### Border

Used to set an element's border:

```css
border-width: 2px;
border-style: solid / dotted / dashed;
border-color: black;
```

#### Border Shorthand

```css
border: 2px solid black;
```

#### Border Radius

Used to round the corners of an element's outer border edge:

```css
border-radius: 10px;
border-radius: 50%;  /* Creates a circle */
```

### Padding

The space inside the border, around the content:

```css
padding-top: 50px;
padding-right: 50px;
padding-bottom: 50px;
padding-left: 50px;
```

#### Padding Shorthand

```css
padding: 50px;                    /* All sides */
padding: 1px 2px 3px 4px;         /* top | right | bottom | left (clockwise) */
```

### Margin

The space outside the border:

```css
margin-top: 50px;
margin-right: 50px;
margin-bottom: 50px;
margin-left: 50px;
```

#### Margin Shorthand

```css
margin: 50px;                     /* All sides */
margin: 1px 2px 3px 4px;          /* top | right | bottom | left (clockwise) */
```

### Practice Set 3

**Q1:** Create a div with height & width of 100px. Set its background color to green & the border radius to 50%.

**Q2:** Create a navbar with:
- Height: 60px
- Text size: 25px
- Background color: #f08804 (yellow)
- Anchor tags (links) with 200px gap
- Background color: #0f1111 (black)

### Display Property

```css
display: inline / block / inline-block / none;
```

- **inline** - Takes only the space required by the element (no margin/padding)
- **block** - Takes full space available in width
- **inline-block** - Similar to inline but we can set margin & padding
- **none** - Removes element from document flow

### Visibility

```css
visibility: hidden;
```

**Note:** When visibility is set to hidden, space for the element is reserved. But for display set to none, no space is reserved or blocked for the element.

### Opacity (Alpha Channel)

Values from 0 to 1:

```css
color: rgba(255, 0, 0, 0.5);    /* 50% transparent red */
color: rgba(255, 0, 0, 1);      /* Fully opaque red */
```

### Practice Set 4

**Q1:** Create a webpage layout with a header, a footer & a content area containing 3 divs. Set the height & width of divs to 100px. (add the previous navbar in the header)

**Q2:** Add borders to all the divs.

**Q3:** Add a different background color to each div with an opacity of 0.5

**Q4:** Give the content area an appropriate height.

---

## Level 3

### Relative Units

#### Percentage (%)

It is often used to define a size as relative to an element's parent object:

```css
width: 33%;
margin-left: 50%;
```

Example: Make one parent & one child div show 50% of parent for h1.

#### Em

For font size: child will be half of parent for 0.5em

For padding & margin: it's relative to the same element's font size

```css
font-size: 0.5em;
```

Show both on the same parent & div. Make a button with border & font-size, then change its border radius from pixel to ems to set a constant shape.

#### Rem (Root Em)

Similar to Em but relative to the root element's font size:

```css
font-size: 0.5rem;
```

#### Other Units

```css
vh: relative to 1% viewport height
vw: relative to 1% viewport width
```

### Position Property

The position CSS property sets how an element is positioned in a document:

```css
position: static / relative / absolute / fixed / sticky;
```

#### Position Values

- **static** - Default position (top, right, bottom, left, and z-index have no effect)
- **relative** - Element is relative to itself (top, right, bottom, left, and z-index will work)
- **absolute** - Positioned relative to its closest positioned ancestor (removed from flow)
- **fixed** - Positioned relative to browser (removed from flow)
- **sticky** - Positioned based on user's scroll position

### z-index

It decides the stack level of elements:

```css
z-index: auto;      /* Default (0) */
z-index: 1 / 2 / 3;
z-index: -1 / -2;
```

Overlapping elements with a larger z-index cover those with a smaller one.

### Background Image

Used to set an image as background:

```css
background-image: url("image.jpeg");
```

### Background Size

```css
background-size: cover / contain / auto;
```

- **cover** - Fits with no empty space
- **contain** - Fits with image fully visible
- **auto** - Original size

### Practice Set 5

**Qs:** Create the following layout using the given HTML.

```html
<p> lorem*5 </p>
<div> Love Nature </div>
<p> lorem*5 </p>
```

- Give the div a height, width & some background image
- Use the appropriate position property for the div element to place it at the right end of the page (The div should not move even on scroll)
- Use z-index to place the div on top of page

---

## Level 4

### Flexbox - Flexible Box Layout

It is a one-dimensional layout method for arranging items in rows or columns.

**First Step:** Set display property of container to flex:

```css
display: flex;
```

#### The Flex Model

```
┌────────────────────────────────┐
│  Flex Container                │
│  ┌─────────┐  ┌─────────┐      │
│  │Flex Item│  │Flex Item│──→ main axis
│  └─────────┘  └─────────┘      │
│       ↓              ↓          │
│   cross axis                    │
└────────────────────────────────┘
```

### Flex Direction

Sets how flex items are placed in the flex container, along which axis and direction:

```css
flex-direction: row;              /* Default */
flex-direction: row-reverse;
flex-direction: column;
flex-direction: column-reverse;
```

### Flex Properties for Flex Container

#### justify-content

Alignment along the main axis:

```css
justify-content: flex-start / flex-end / center / space-evenly / space-around / space-between;
```

#### flex-wrap

```css
flex-wrap: nowrap / wrap / wrap-reverse;
```

#### align-items

Alignment along the cross axis:

```css
align-items: flex-start / flex-end / center / stretch;
```

#### align-content

Alignment of space between & around the content along cross-axis:

```css
align-content: flex-start / flex-end / center / space-evenly / space-around;
```

### Flex Properties for Flex Item

#### align-self

Alignment of individual item along the cross axis. Similar to align-items but for individual element and it overrides align-items:

```css
align-self: flex-start / flex-end / center / stretch;
```

#### flex-grow

How much a flex item will grow relative to the rest of the flex items if space is available:

```css
flex-grow: 0 / 1 / 2 / 3;
/* 0 = doesn't grow at all */
```

#### flex-shrink

How much a flex item will shrink relative to the rest of the flex items if space is available:

```css
flex-shrink: 0 / 1 / 2 / 3;
```

### Practice Set 6

**Q1:** Create a navbar with 4 options in the form of anchor tags inside list items. Now, use flexbox to place them all spaced equally in a single line.

**Q2:** Use flexbox to center one div inside another div.

**Q3:** Which has higher priority - align-items or align-self?

*Answer: align-self has higher priority and overrides align-items.*

---

## Level 5

### Media Queries - Responsive Web Design

Media queries help create a responsive website. In today's world, everyone has a different device with thousands of different screen sizes.

Websites are used on:
- Laptops & big screen computers
- iPhones & small screen Android phones
- Big screen Android phones
- iPads
- Different orientations (landscape or portrait)

It's important that layout looks good on all devices, so we need design to be responsive and respond to different screen sizes & orientation.

```css
@media (width: 600px) {
  div {
    background-color: red;
  }
}

@media (min-width: 600px) {
  div {
    background-color: red;
  }
}

@media (min-width: 200px) and (max-width: 300px) {
  div {
    background-color: red;
  }
}
```

### Practice Set 7

**Qs:** Add a media query to implement the following:

- The color of a div changes to **green** for viewport width **less than 300px**
- The color of a div changes to **pink** for width **between 300px & 400px**
- The color of a div changes to **red** for width **between 400px & 600px**
- The color of a div changes to **blue** for width **above 600px**

### Transitions

Transitions enable you to define the transition between two states of an element. Add some animation to elements.

```css
transition-property: font-size;                      /* Property you want to transition */
transition-duration: 2s;                             /* How long the transition takes */
transition-timing-function: ease-in / ease-out / linear / steps;
transition-delay: 2s;                                /* Delay before transition starts */
```

**Example with hover:**

```css
div:hover {
  font-size: 40px;
  transition: font-size 2s ease-in-out;
}
```

#### Transition Shorthand

```css
transition: property duration timing-function delay;
transition: font-size 2s ease-in-out 0.2s;
```

---

## Level 6 - Advanced CSS

### CSS Transform

#### Scale

```css
transform: scale(2);                /* Scale both axes */
transform: scale(0.5);
transform: scaleX(0.5);             /* X axis only */
transform: scaleY(0.5);             /* Y axis only */
transform: scale(1, 2);             /* Separate X and Y */
```

#### Translate

```css
transform: translate(20px);         /* Both axes */
transform: translateX(20px);        /* X axis only */
transform: translateY(20px);        /* Y axis only */
transform: translate(20px, 50px);   /* Separate X and Y */
```

You can also give distance in other units like %, ems, rems. Negative values are also supported.

#### Skew

```css
transform: skew(30deg);
```

You can now make advanced 3D objects using transform if you're good at math.

### Animation

#### Keyframes

Define animation states using @keyframes:

```css
@keyframe myName {
  from { font-size: 20px; }
  to { font-size: 40px; }
}
```

#### Animation Properties

```css
animation-name: myName;
animation-duration: 2s;
animation-timing-function: linear / ease-in / ease-out;
animation-delay: 3s;
animation-iteration-count: 1 / infinite;
animation-direction: normal / reverse / alternate;
```

#### Animation Shorthand

```css
animation: myName 2s linear 3s infinite normal;
```

#### Using Percentage (%) in Animation

```css
@keyframe myName {
  0% { font-size: 20px; }
  50% { font-size: 30px; }
  100% { font-size: 40px; }
}
```

### Practice Set 8

**Qs:** Create a simple loader using CSS

**Step 1:** Create a div with circular shape & a thick border from one end (top/bottom/left/right)

**Step 2:** To make it spin, create an animation which transforms it from 0deg to 360deg

**Step 3:** Add the animation property to the loader with infinite duration

---

## Summary

These are advanced CSS concepts. While they are important to know, you may not use them extensively in practice. But it's crucial to understand them for better web development and creating engaging user interfaces.
