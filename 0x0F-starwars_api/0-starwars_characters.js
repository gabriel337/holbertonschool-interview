const https = require('https');
const process = require('process');

function fetch (url) {
  return new Promise((resolve, reject) => {
    https.get(url, (response) => {
      let data = '';
      response.on('data', (chunk) => {
        data += chunk;
      });
      response.on('end', () => {
        resolve(JSON.parse(data));
      });
    }).on('error', (err) => {
      reject(err);
    });
  });
}

async function getFilmCharacters (movieId) {
  const baseURL = 'https://swapi.dev/api/films/';
  const filmData = await fetch(baseURL + movieId);

  if (!filmData.title) {
    console.log('Invalid movie ID.');
    process.exit(1);
  }

  console.log('Movie:', filmData.title);
  console.log('Characters:');

  for (const characterUrl of filmData.characters) {
    const characterData = await fetch(characterUrl);
    console.log(characterData.name);
  }
}

if (process.argv.length !== 3) {
  console.log('Usage: node script.js <movie_id>');
  process.exit(1);
}

const movieId = process.argv[2];
getFilmCharacters(movieId);
