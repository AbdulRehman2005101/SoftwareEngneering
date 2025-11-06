const express=require("express")
const logger=require("./logger");

const app= express();

app.get('/healthcheck',(req,res)=>{
    logger.log("Someone checks health");
    res.status(200).json({"Message":"Working"})
})

app.listen(3000,()=>{
    logger.log(`Server running at port ${3000}`)
})