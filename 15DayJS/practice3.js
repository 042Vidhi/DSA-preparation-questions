for (var i = 0; i < 3; i++) {
    setTimeout(function() {
      console.log(i);
    }, 1000);
  }
  //3 3 3
  // And then:
  for (let j = 0; j < 3; j++) {
    setTimeout(function() {
      console.log(j);
    }, 1000);
  }
  //0 1 2

//   -------------------------------------------
console.log('5' + 3);  // 53
console.log('5' - 3);  // 2
console.log(true + true); // 2
console.log(10 + 'px'); // 10px
console.log('10' - '2'); // 8
console.log('10' * '2'); // 20
console.log('10' / '2'); // 5


console.log(null || 'default'); // deafult
console.log(undefined && 'value'); // undefined
console.log('' || 42); // 42
console.log('NaN' && 'truthy'); // truthy
console.log(false || true && false); // false

console.log(0 == false);   // true
console.log(0 === false);  // false
console.log(null == undefined); // true
console.log(null === undefined); // false
console.log('' == false);  // true
console.log('' === false); // false

const original = { name: 'John' };
const copy = original;

copy.name = 'Doe';

console.log(original.name); // Doe
console.log(copy.name); // Doe
