document.addEventListener('DOMContentLoaded', function () {
    const container = document.querySelector('.problems');
    const problems = [
        {
            name: "2spooky4me", link: "https://dmoj.ca/problem/2spooky4me", input: `3 100 10
20 59 4
30 69 4
40 79 4` },
        {
            name: "An Animal Contest 4 P3 - Snowy Slopes", link: "https://dmoj.ca/problem/aac4p3", input: `3 4
1 2
4 4
7 1
-1 1
2 1
4 6
-2 2` },
        {
            name: "Another Contest 3 Problem 1 - Diverse Arrays", link: "https://dmoj.ca/problem/acc3p1", input: `4 2
1
2
2
2` },
        {
            name: "CCC '00 S4 - Golf", link: "https://dmoj.ca/problem/ccc00s4", input: `100
3
33
66
1` },
        {
            name: "CCC '02 S4 - Bridge Crossing", link: "https://dmoj.ca/problem/ccc02s4", input: `2
5
alice
1
bob
5
charlie
5
dobson
3
eric
3` },
        {
            name: "CCC '04 S5 - Super Plumber", link: "https://dmoj.ca/problem/ccc04s5", input: `5 10
..3.......
..........
..7.**....
.9**...1..
..8..9....
2 2
99
88
0 0` },
        {
            name: "CCC '05 S4 - Pyramid Message Scheme", link: "https://dmoj.ca/problem/ccc05s4", input: `1
8
Alfred
Cindy
Alfred
Dennis
Alfred
Home
Betty
Home`
        },
        {
            name: "CCC '07 S5 - Bowling for Numbers", link: "https://dmoj.ca/problem/ccc07s5", input: `1
9 2 3
2
8
5
1
9
6
9
3
2`
        }, {
            name: "CCC '09 S5 - Wireless", link: "https://dmoj.ca/problem/ccc09s5", input: `3
5
3
1 3 2 5
3 1 2 7
5 1 1 5`
        }, {
            name: "CCO '08 P2 - King & Weber", link: "https://dmoj.ca/problem/cco08p2", input: `3 3
fourthstreet fifthstreet parallel
fifthstreet sixthstreet parallel
fourthavenue fifthstreet intersect
sixthstreet fourthstreet
sixthstreet fourthavenue
sixthstreet King`
        }, {
            name: "Graph Contest 2 P1 - Connected Components", link: "https://dmoj.ca/problem/graph2p1", input: `5
0 0 0 0 0
0 0 0 0 0
0 0 0 1 1
0 0 1 0 1
0 0 1 1 0`
        }, {
            name: "GlobeX Cup '18 S3 - Playing With Bits", link: "https://dmoj.ca/problem/globexcup18s3", input: `2 1000000007 3 5`
        }, {
            name: "ECOO '14 R2 P4 - What Lies Ahead", link: "https://dmoj.ca/problem/ecoo14r2p4", input: `..TT..
TCURC.
.DLRD.
.BUBB.
.CUCCT
.TS...
.T.T..
TRCDU.
.UCLDT
.RCBL.
TDUCU.
.S....`
        },
        //         {
        //             name: `DWITE '12 R5 #5 - Pattern Lock`, link: "https://dmoj.ca/problem/dwite12c5p5", input: `1
        // 2`
        //         },
        {
            name: "DMOPC '17 Contest 1 P3 - Hitchhiking Fun", link: "https://dmoj.ca/problem/dmopc17c1p3", input: `4 5
            1 2 0
1 3 1
1 4 1
2 3 0
3 4 0`
        }, {
            name: "DMOPC '15 Contest 6 P5 - A Classic Problem", link: "https://dmoj.ca/problem/dmopc15c6p5", input: `5 2
0 3 2 1 4`
        }, {
            name: "CCO '20 P1 - A Game with Grundy", link: "https://dmoj.ca/problem/cco20p1", input: `3
-7 7 3
0 2 3
-4 2 1
3 3 1`
        }, {
            name: "DMOPC '15 Contest 1 P5 - Lelei and Dragon Scales", link: "https://dmoj.ca/problem/dmopc15c1p5", input: `5 5 4
0 0 0 0 10
0 5 0 1 2
2 0 3 7 1
8 9 0 1 3
1 5 2 3 7`
        }, {
            name: "DMOPC '14 Exam Time P4 - Exam Delay", link: "https://dmoj.ca/problem/dmopc14ce1p4", input: `3
3
1 3 350 80
1 2 200 80
2 3 150 100`
        }, {
            name: "DMOPC '14 Contest 5 P4 - Kittan's Dilemma", link: "https://dmoj.ca/problem/dmopc14c5p4", input: `5 11
1 1
6 2
3 1
5 2
4 2`
        }, {
            name: "DMOPC '14 Contest 4 P6 - Save Nagato!", link: "https://dmoj.ca/problem/dmopc14c4p6", input: `3
2 1
2 3`
        }, {
            name: "CPC '21 Contest 1 P2 - AQT and Multiset", link: "https://dmoj.ca/problem/cpc21c1p2", input: `3
84 80 88 84 93 84 86
5 1 12 7 9 5 5`
        }, {
            name: "Cheerio Contest 1 S2 - School Expansion", link: "https://dmoj.ca/problem/cheerio1s2", input: `5 5 7`
        }, {
            name: "Checkerboard Summation (Easy)", link: "https://dmoj.ca/problem/checkereasy", input: `3 3
1 2 5
3 1 -2
2 3 11
0 0 0
2 1 3 3
0 0 0 0`
        }, {
            name: "CCOQR '16 - Stupendous Bowties", link: "https://dmoj.ca/problem/ccoqr16p1", input: `12
-3 6
1 6
-1 4
-3 2
1 2
4 2
-4 -3
-3 -3
1 -3
-1 -4
1 -4
-3 -6`
        }, {
            name: "IOI '10 P6 - Traffic Congestion", link: "https://dmoj.ca/problem/ioi10p6io", input: `5
10 10 10 20 20
0 2
1 2
3 2
4 3`
        }, {
            name: "Yet Another Contest 6 P3 - No More Cell Phone Messaging", link: "https://dmoj.ca/problem/yac6p3", input: `2 3
2
2`
        }, {
            name: "Wesley's Anger Contest 6 Problem 3 - Difference Sorting", link: "https://dmoj.ca/problem/wac6p3", input: `8
1 4 4 2 7 14 12 10`
        }, {
            name: "Tropical Bananas", link: "https://dmoj.ca/problem/tropical", input: `4 5
1 1 4 9 0
1 2 4 10 -7
0 1 2 4 6
0 2 3 3 -9
0 2 3 5 -1`
        }, {
            name: "Triway Cup '18 Summer B - Beautiful Water Pearl", link: "https://dmoj.ca/problem/tc18summerb", input: `110 44 66`
        }, {
            name: "Tree Tasks", link: "https://dmoj.ca/problem/treepractice1", input: `5
1 2 1
2 3 2
3 4 5
2 5 7`
        }, {
            name: "TLE '17 Contest 4 P3 - Fax's Christmas Dish", link: "https://dmoj.ca/problem/tle17c4p3", input: `7 3 8
2 2 3 6
4 2 5 7
1 2 2 4
3 3 6 3 5 4 4 1`
        }, {
            name: "TLE '16 Contest 3 P3 - Mysterious Package", link: "https://dmoj.ca/problem/tle16c3p3", input: `6
1 10
1 3
16 2 1
3 3
7 10 2
1 3
52 7 14
2 3
16 10 52
2 2
14 4
1 2
10 4`
        }, {
            name: "The Cake is a Dessert", link: "https://dmoj.ca/problem/cake", input: `6 5 3
1 3 4 5
1 1 6 1
2 2 3 3
5
2 1 2 2
5 2 6 5
2 4 2 4
3 1 4 2
2 1 4 4`
        }, {
            name: "Sum Maximization", link: "https://dmoj.ca/problem/summaximization", input: `2
1 100
1 9995`
        }, {
            name: "Single Source Shortest Path", link: "https://dmoj.ca/problem/sssp", input: `4 3
1 2 2
1 3 5
2 3 2`
        }, {
            name: "SAC '22 Code Challenge 2 P4 - Cookie Galore ", link: "https://dmoj.ca/problem/sac22cc2p4", input: `6 4
C..C
.CCC
CC.C
..CC
CC..
C.C.`
        }, {
            name: "IOI '14 Practice Task 3 - Tile", link: "https://dmoj.ca/problem/ioi14pp3", input: `1 0 0`
        }
    ];

    problems.sort((a, b) => a.name.localeCompare(b.name));
    
    const button = document.createElement('button');
    button.classList.add('button3');
    button.textContent = 'blank file';
    button.onclick = () => {
        window.location.href = `problemTemplate.html?name=${encodeURIComponent('blank file')}&link=${encodeURIComponent('')}&input=${encodeURIComponent('')}`;

    };
    container.appendChild(button);
    container.appendChild(document.createElement('br'));

    problems.forEach(problem => {
        const button = document.createElement('button');
        button.classList.add('button2');
        button.textContent = problem.name.trim();
        button.onclick = () => {
            window.location.href = `problemTemplate.html?name=${encodeURIComponent(problem.name)}&link=${encodeURIComponent(problem.link)}&input=${encodeURIComponent(problem.input)}`;

        };
        container.appendChild(button);
        container.appendChild(document.createElement('br'));
    });


});
