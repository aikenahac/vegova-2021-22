const express = require('express');

const app = express();

app.get('/', (req, res) => {
  res.json({
    message: 'Hello R3C!',
  });
});

app.get('/get-r3c', (req, res) => {
  res.json({
    status: 200,
    message: 'Odgovor strežnika',
  })
});

app.listen(3000);