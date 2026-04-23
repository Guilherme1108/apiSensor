/****************************************************************************************
 * Objetivo: Arquivo responsavel pelas requisições da API sensor de temperatura.
 * Data: 06/04/2026
 * Autor: Guilherme Moreira
 * Versão: 1.0
*****************************************************************************************/

const express = require("express");
const app = express()

let dados = []; //armazenamento em memória

app.get("/sensor", (req, res) => {
    const { temp, hum } = req.query;

    if (!temp || !hum) {
        return res.status(400).send("dados inválidos");
    }

    const leitura = {
        temperatura: temp,
        umidade: hum,
        data: new Date()
    };

    dados.push(leitura);

    console.log(leitura);

    res.send("OK")
});

app.get("/dados", (req, res) => {
    res.json(dados);
})

const PORT = process.env.PORT || 3000;

app.listen(PORT, () => {
    console.log(`Servidor rodando na porta ${PORT}`);
});