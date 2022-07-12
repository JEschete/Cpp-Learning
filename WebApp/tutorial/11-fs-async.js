const {readFile, writeFile, read, write} = require('fs')

console.log('Start')
// Look up callbacks, if you don't add encoding, you only get a buffer return.
readFile('./content/first.txt','utf8',(err,result)=>{
    if(err){
        console.log(err)
        return;
    }
    const first = result;
    readFile('./content/second.txt','utf8', (err,result)=>{
        if(err){
            console.log(err)
            return;
        }
        const second = result;
        writeFile(
            './content/result-async.txt',
            `Here is the result: ${first}, ${second}`,(err,result)=>{
                if(err){
                    console.log(err)
                    return;
                }
                console.log('Done with task.')
            })
    })
})
console.log('Starting next task. ')

