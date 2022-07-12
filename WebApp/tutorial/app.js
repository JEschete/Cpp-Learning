const http = require('http');

//req is the request from the browser, res is the response to send data back. 
const server = http.createServer((req,res)=>{
    if(req.url === '/'){
        res.end(
            `<h1>Welcome to the Jungle, Weve got fun and games</h>
            <p><a href="/about">About Us</a></p>
            <p><a href="/contacts">Contact Us</a></p>`)
    }
    if(req.url === '/about'){
        res.end('We have everything you want')
    }
    res.end(
        `<h1>Oops</h1>
        <p>Seems we don't have that...</p>
        <a href="/"> Where do we go now?</a>
        `
    )
})

server.listen(5000)