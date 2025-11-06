class Logger{
    constructor(){
        if(Logger.instance){
            console.log("Using existing logger");
        }
        console.log("making a new instance");
        Logger.instance= this
    }

    log(message){
        const Time=new Date().toISOString();
        console.log(`${Time} ${message}`);
    }
}

module.exports = new Logger();