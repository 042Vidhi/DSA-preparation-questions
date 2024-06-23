var createHelloWorld = function(){
    return function(...args){
        return "Hello World";
    }
}

console.log(createHelloWorld)
//[Function: createHelloWorld]
console.log(createHelloWorld())
//[Function (anonymous)]
const f = createHelloWorld();
console.log(f());
// Hello World