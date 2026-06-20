// Events in JS :-
// The change in the state of an object is known as an Event

// Mouse events (click, double click etc.)
// Keyboard events (keypress, keyup, keydown)
// Form events (submit etc.)
// Print event & many more


node.event = ( ) => {
//handle here
}

const btn = document.getElementById("myBtn");
btn.onclick = ( ) => {
console.log("Button clicked!");
}

// Event Object :-
// It is a special object that has details about the event.

node.event = (e) => {
//handle here
}

// e.target, e.type, e.clientX, e.clientY, e.offsetX, e.offsetY


// Event Listeners :-

// node.addEventListener( event, callback )
// node.removeEventListener( event, callback )

// *Note : the callback reference should be same to remove the event

const button = document.getElementById("myButton");
button.addEventListener("click", function() {
    alert("Button clicked!");
});