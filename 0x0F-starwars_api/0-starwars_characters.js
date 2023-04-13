#!/usr/bin/node
const request = require('request');
const process = require('process');
const movie = process.argv[2];
request.get(`https://swapi-api.hbtn.io/api/films/${movie}/`, async (error, response, body) => {
  if (error) {
    return console.log(error);
  }
  const charsURL = JSON.parse(body).characters;
  for (const charURL of charsURL) {
    await new Promise((resolve, reject) => {
      request.get(charURL, (error, response, body) => {
        if (error) {
          return console.log(error);
        }
        console.log(JSON.parse(body).name);
        resolve();
      });
    });
  }
});
