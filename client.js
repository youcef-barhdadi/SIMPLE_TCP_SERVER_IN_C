const Net = require("net");


const host = 'localhost';
const port = 1337;




const client = new Net.Socket();

client.connect({port: port, host: host}, () => {

	console.log("conniction established ");

	client.write("hello mother fucker");
});

