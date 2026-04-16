const express = require("express");

let dados = []; //armazenamento em memória

app.get("/sensor", (req, res) => {
    const { temp, hum } = req.query;

    if (!temp || !hum) {
        return res.status(400).send("dados inválidos");
    }


    const leitura = {
        temperatura: temp,
        umidade: hum,
        data: new Data()
    };

    dados.push(leitura);

    console.log(leitura);

    res.send("OK");
});