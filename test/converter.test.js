const {
  localAlphabetToCupangAlphabet,
  cupangAlphabetToLocalAlphabet,
} = require("../src/converter.js");

describe("converter.js", () => {
  describe("localAlphabetToCupangAlphabet", () => {
    it("converts a single character", () => {
      expect(localAlphabetToCupangAlphabet("A")).toBe("BLUK");
    });

    it("converts a sentence", () => {
      expect(localAlphabetToCupangAlphabet("HELLO WORLD")).toBe(
        "BLUKBLUB BLUKBLUK BULBLUB BULBLUB BULKBULK | BLUKBLUKBULK BULKBULK BLUBBUL BULBLUB BLUB"
      );
    });

    it("handles unknown characters", () => {
      expect(localAlphabetToCupangAlphabet("!")).toBe("<check-your-spelling>");
    });
  });

  describe("cupangAlphabetToLocalAlphabet", () => {
    it("converts a single character", () => {
      expect(cupangAlphabetToLocalAlphabet("BUL")).toBe("B");
    });

    it("converts a sentence", () => {
      expect(
        cupangAlphabetToLocalAlphabet(
          "BLUKBLUB BLUKBLUK BULBLUB BULBLUB BULKBULK | BLUKBLUKBULK BULKBULK BLUBBUL BULBLUB BLUB"
        )
      ).toBe("HELLO WORLD");
    });

    it("handles unknown characters", () => {
      expect(cupangAlphabetToLocalAlphabet("!!!")).toBe(
        "<check-your-spelling>"
      );
    });

    it("handles unknown characters with | character as separator", () => {
      expect(cupangAlphabetToLocalAlphabet("! | ! | !")).toBe(
        "<check-your-spelling> <check-your-spelling> <check-your-spelling>"
      );
    });
  });
});
