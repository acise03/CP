
document.addEventListener('DOMContentLoaded', function () {
    const container = document.querySelector('.problems');

    const problems = [
        {
            name: "2spooky4me", link: "https://dmoj.ca/problem/2spooky4me", input: `3 100 10
20 59 4
30 69 4
40 79 4` },
        { name: "An Animal Contest 4 P3 - Snowy Slopes", link: "https://dmoj.ca/problem/aac4p3" },
        { name: "An Animal Contest 5 P3 - Ski Resort", link: "https://dmoj.ca/problem/aac5p3" },
        { name: "Another Contest 3 Problem 1 - Diverse Arrays", link: "https://dmoj.ca/problem/acc3p1" },
        { name: "CCC '00 S4 - Golf", link: "https://dmoj.ca/problem/ccc00s4" },
        { name: "CCC '02 S4 - Bridge Crossing", link: "https://dmoj.ca/problem/ccc02s4" },
        { name: "CCC '04 S5 - Super Plumber", link: "https://dmoj.ca/problem/ccc04s5" }
    ];

    problems.forEach(problem => {
        const button = document.createElement('button');
        button.textContent = problem.name;
        button.onclick = () => {
            window.location.href = `problemTemplate.html?name=${encodeURIComponent(problem.name)}&link=${encodeURIComponent(problem.link)}&input=${encodeURIComponent(problem.input)}`;

        };
        container.appendChild(button);
    });
});