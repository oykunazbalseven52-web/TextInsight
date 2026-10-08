const analyzeButton = document.getElementById("analyzeButton");
const textInput = document.getElementById("textInput");

analyzeButton.addEventListener("click", async function () {
    const text = textInput.value;

    if (text.trim() === "") {
        alert("Please enter some text.");
        return;
    }

    analyzeButton.disabled = true;

    try {
        const response = await fetch("/analyze", {
            method: "POST",
            headers: {
                "Content-Type": "text/plain; charset=UTF-8"
            },
            body: text
        });

        if (!response.ok) {
            throw new Error("Analysis request failed.");
        }

        const result = await response.json();

        document.getElementById("characterCount").textContent =
            result.characterCount;

        document.getElementById("wordCount").textContent =
            result.wordCount;

        document.getElementById("characterCountWithoutSpaces").textContent =
            result.characterCountWithoutSpaces;

        document.getElementById("sentenceCount").textContent =
            result.sentenceCount;
    } catch (error) {
        alert("Could not analyze the text. Please try again.");
        console.error(error);
    } finally {
        analyzeButton.disabled = false;
    }
});