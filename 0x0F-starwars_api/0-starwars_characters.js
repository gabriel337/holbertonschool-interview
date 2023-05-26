#!/usr/bin/node

const request = require('request');
const filmNum = process.argv[2] + '/';
const filmURL = 'https://swapi-api.hbtn.io/api/films/';

request(filmURL + filmNum, async function (err, res, body) {
  if (err) {
    return console.error(err);
  }

  const parsedBody = JSON.parse(body);

  if (!parsedBody || !parsedBody.characters) {
    return console.error('Invalid response or characters key not found in the response');
  }

  const charURLList = parsedBody.characters;

  if (!Array.isArray(charURLList)) {
    return console.error('charURLList is not an array');
  }

  for (const charURL of charURLList) {
    await new Promise(function (resolve, reject) {
      request(charURL, function (err, res, body) {
        if (err) {
          console.error(err);
          return resolve();
        }
        console.log(JSON.parse(body).name);
        resolve();
      });
    });
  }
});
