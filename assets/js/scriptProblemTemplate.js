let editor;

document.addEventListener('DOMContentLoaded', function () {
    const urlParams = new URLSearchParams(window.location.search);
    const problemName = urlParams.get('name');
    const problemLink = urlParams.get('link');

    const problemElement = document.getElementById('problem-name');
    problemElement.innerHTML = `Problem: <a href="${problemLink}" target="_blank">${problemName}</a>`;

    const linkShown = document.getElementById('problem-link');
    linkShown.innerHTML = `PROBLEM LINK FOR SUBMISSION: <a href="${problemLink}" target="_blank">${problemLink}</a>`;

    const problemInput = document.getElementById('user-input');
    const userInputValue = urlParams.get('input');
    problemInput.value = userInputValue ? userInputValue : 'Input not set. Please paste from problem statement link.';


    editor = CodeMirror.fromTextArea(document.getElementById('code'), {
        mode: 'text/x-c++src',
        lineNumbers: true,
        theme: 'dracula',
        indentUnit: 4,
        autofocus: true,
        lineWrapping: true,
        viewportMargin: Infinity
    });
    editor.setSize('100%', 750);

    fetch(`programmingFiles/files/${problemName}.cpp`)
        .then(response => {
            if (!response.ok) {
                throw new Error('File not found');
            }
            return response.text();
        })
        .then(data => {
            editor.setValue(data);
        })
        .catch(error => {
            console.error('Error fetching the file:', error);
            editor.setValue('Error loading code.');
        });
});

async function runCode() {
    const code = editor.getValue();
    const outputElement = document.getElementById('output');
    const userInput = document.getElementById('user-input').value;
    outputElement.textContent = 'Running...';

    try {
        const response = await fetch('https://emkc.org/api/v2/piston/execute', {
            method: 'POST',
            headers: { 'Content-Type': 'application/json' },
            body: JSON.stringify({
                language: 'cpp',
                version: '10.2.0',
                files: [{ content: code }],
                stdin: userInput
            })
        });

        const result = await response.json();

        if (result.run.output) {
            outputElement.textContent = result.run.output;
        } else {
            outputElement.textContent = 'No output.';
        }
    } catch (error) {
        outputElement.textContent = 'Error: ' + error.message;
    }
}
