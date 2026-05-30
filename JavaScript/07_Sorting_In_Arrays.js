const numbers = [10, 5, 2, 1];
numbers.sort(); 
console.log(numbers); // Output: [1, 10, 2, 5] (Incorrect numeric order!)

// To sort numbers accurately, you must pass a compare function as an argument.
const scores = [40, 100, 1, 5, 25];

// Ascending
scores.sort((a, b) => a - b);
console.log(scores); // [1, 5, 25, 40, 100]

// Descending
scores.sort((a, b) => b - a);
console.log(scores); // [100, 40, 25, 5, 1]

// Sorting an Array of Objects :-

const users = [
  { name: 'Alex', age: 25 },
  { name: 'Sam', age: 18 },
  { name: 'Eagle', age: 30 }
];

// Sort by age (Numeric)
users.sort((a, b) => a.age - b.age);

// Sort by name (String)
users.sort((a, b) => a.name.localeCompare(b.name));