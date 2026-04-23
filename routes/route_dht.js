const express = require("express");
const app = express()

let dados = []; //armazenamento em memória

app.get("/sensor", (req, res) => {
    const { temp, hum } = req.query;

    if (!temp || !hum) {
        return res.status(400).send("dados inválidos");
    }

    console.log(`Temp: ${temp} | Umidade ${hum}`);

    res.send("OK")
});

const PORT = process.env.PORT || 3000;

app.listen(PORT, () => {scrollX
    console.log("Servidor rodando");
});