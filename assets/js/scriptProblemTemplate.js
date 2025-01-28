let editor;

document.addEventListener('DOMContentLoaded', function () {
    const urlParams = new URLSearchParams(window.location.search);
    const problemName = urlParams.get('name');
    const problemLink = urlParams.get('link');

    const problemElement = document.getElementById('problem-name');
    problemElement.innerHTML = `Problem: <a href="${problemLink}" target="_blank">${problemName}</a>`;

    const linkShown = document.getElementById('problem-link');
    linkShown.innerHTML = `Problem Link: <a href="${problemLink}" target="_blank">${problemLink}</a>`;


    editor = CodeMirror.fromTextArea(document.getElementById('code'), {
        mode: 'text/x-c++src',
        lineNumbers: true,
        theme: 'dracula',
        indentUnit: 4,
        autofocus: true
    });


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

function highlightCode() {
    editor.refresh();
    console.log('Code readability increased.');
}