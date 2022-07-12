const num1 = 5;
const num2 = 10; 

function addValues(){
    console.log(`the sum is : ${num1 + num2}`)
}
 
// Functions defined and invoked inside of a module will run even if not assigned in the main file. 
addValues()