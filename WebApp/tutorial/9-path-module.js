const path = require('path')

//prints the seperator symbol for current OS
console.log(path.sep)

//Joins the text strings into a file path. 
const filepath = path.join('/content','subfolder','test.exe')
console.log(filepath)

const base = path.basename(filepath)
console.log(base)

const absolute = path.resolve(__dirname,'content','subfolder','test.txt')
console.log(absolute)

