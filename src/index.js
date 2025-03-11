const {
  localAlphabetToCupangAlphabet,
  cupangAlphabetToLocalAlphabet,
} = require("./converter");

const args = process.argv.slice(2);
const mode = args[0];
const input = args[1];

if (!mode || !input) {
  console.log("Usage: node index.js <mode> <sentence>");
  console.log("Modes: local-to-cupang or cupang-to-local");
  process.exit(1);
}

if (mode === "local-to-cupang") {
  console.log(localAlphabetToCupangAlphabet(input));
} else if (mode === "cupang-to-local") {
  console.log(cupangAlphabetToLocalAlphabet(input));
} else {
  console.log("Invalid mode. Use 'local-to-cupang' or 'cupang-to-local'");
  process.exit(1);
}
