//call
/*
var person = {
    age: 23,
    getAge: function(){
      return this.age;
    }
  }        
  var person2 = {age:  54};
console.log(person.getAge.call(person2));   //54
*/
// ***************************************************
/*
function saySomething(message){
    return this.name + " is " + message;
  }     
  var person4 = {name:  "John"};     
console.log(saySomething.call(person4, "awesome"));  //John is awesome
*/
// ******************************************************
// The apply method is similar to the call() method. The only difference is that,
// call() method takes arguments separately whereas, apply() method takes arguments as an array.
/*
function saySomething(message){
    return this.name + " is " + message;
  }        
  var person4 = {name:  "John"};
console.log(saySomething.apply(person4, ["awesome"])); // John is awesome
*/
// **********************************************************
/*
var person = {
    age: 23,
    getAge: function(){
      return this.age;
    }
  }        
  var person2 = {age:  54};
console.log(person.getAge.bind(person2));   //[Function: bound getAge]
*/
// What is currying in JavaScript?
// Currying is an advanced technique to transform a function of arguments n, to n functions of one or fewer arguments.
// By using the currying technique, we do not change the functionality of a function, we just change the way it is invoked.
// function add (a) {
//     return function(b){
//       return a + b;
//     }
//   }
  
// console.log(add(3)(4)) 

// Explain Closures in JavaScript.
// Closures are an ability of a function to remember the variables and functions that are declared in its outer scope.

// 4. What is the rest parameter and spread operator?
// Both rest parameter and spread operator were introduced in the ES6 version of javascript.

// Rest parameter ( … ):
// It provides an improved way of handling the parameters of a function.
// Using the rest parameter syntax, we can create functions that can take a variable number of arguments.
// Any number of arguments will be converted into an array using the rest parameter.
// It also helps in extracting all or some parts of the arguments.
// Rest parameters can be used by applying three dots (...) before the parameters.
// Rest parameter should always be used at the last parameter of a function:
// / Incorrect way to use rest parameter
// function randomFunc(a,...args,c){
// //Do something
// }

// // Correct way to use rest parameter
// function randomFunc2(a,b,...args){
// //Do something
// }

// Spread operator (…): Although the syntax of the spread operator is exactly the same as the rest parameter, the spread operator is used to spreading an array, and object literals.
//  We also use spread operators where one or more arguments are expected in a function call.

// Key differences between rest parameter and spread operator:

// Rest parameter is used to take a variable number of arguments and turns them into an array while the spread operator takes an array or an object and spreads it
// Rest parameter is used in function declaration whereas the spread operator is used in function calls.