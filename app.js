/****************************************************************************************
 * Objetivo: Arquivo responsavel pelas requisições da API sensor de temperatura.
 * Data: 06/04/2026
 * Autor: Guilherme Moreira
 * Versão: 1.0
*****************************************************************************************/

//Import das dependencias da API
const express       = require('express')

const app = express()

//porta
const PORT = process.PORT || 8080

const dhtRoutes = require('./routes/route_dht')

app.use(dhtRoutes)