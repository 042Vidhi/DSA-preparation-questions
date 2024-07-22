/*
a = 3;
console.log(a) //3
var a;
*/
// *********************************
/*
a = 3;
console.log(a) // Reference Error
let a;
*/
// ***********************************
/*
// Hoisting takes place in the local scope as well
function doSomething(){
    x = 33;
    console.log(x);//33
    var x;
  } 

doSomething()
*/
// *************************************
/*
var x;
console.log(x); // Outputs "undefined" since the initialization of "x" is not hoisted
x = 23;
*/
// ****************************************
/*
// To avoid hoisting, you can run javascript in strict mode by using “use strict” on top of the code:
"use strict";
x = 23; // Gives an error since 'x' is not declared
console.log(x)
var x;
*/
// ****************************************
// var has function scope
// let has block scope
/*
for (var i = 0; i < 3; i++) {
    setTimeout(() => console.log(i), 1); // 3 3 3
  }
  
  for (let i = 0; i < 3; i++) {
    setTimeout(() => console.log(i), 1); // 0 1 2
  }
*/
// *********************************************
/*
const shape = {
    radius: 10,
    diameter() {
      return this.radius * 2;
    },
    perimeter: () => 2 * Math.PI * this.radius,
  };
  
  console.log(shape.diameter()); // 20
  console.log(shape.perimeter()); // NaN
*/
// When we call perimeter, it doesn't refer to the shape object, but to its surrounding scope (window for example).
// Since there is no value radius in the scope of the arrow function, this.radius returns undefined which,
// when multiplied by 2 * Math.PI, results in NaN.
// *************************************************
// console.log(+true); // 1 //Boolean Coercion
// console.log(!'Heelo'); // false
// *****************************************************
/*
const bird = {
    size: 'small',
  };
  
  const mouse = {
    name: 'Mickey',
    small: true,
  };

console.log(mouse.bird);//undefined
console.log(mouse.bird.size);
*/
// ***************************************************************
//js 
// primitives are compared by their value
// objects are compared by their reference
// The two objects that we are comparing don't have that: 
// the object we passed as a parameter refers to a different location in memory 
// than the object we used in order to check equality.
/*
function checkAge(data) {
    if (data === { age: 18 }) { 
      console.log('You are an adult!');
    } else if (data == { age: 18 }) {
      console.log('You are still an adult.');
    } else {
      console.log(`Hmm.. You don't have an age I guess`);
    }
  }
  
  checkAge({ age: 18 });

*/
// ***************************************************************
/*
const sum = eval('10*10+5');
console.log(sum) //105
*/

const multiArgFunction = (a, b, c) => a + b + c;
console.log(multiArgFunction(1, 2, 3)); // 6

const curryUnaryFunction = (a) => (b) => (c) => a + b + c;
console.log(curryUnaryFunction(1)); // returns a function: b => c =>  1 + b + c
console.log(curryUnaryFunction(1)(2)); // returns a function: c => 3 + c
console.log(curryUnaryFunction(1)(2)(3)); // returns the number 6