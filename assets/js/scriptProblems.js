document.addEventListener('DOMContentLoaded', function () {
    const container = document.querySelector('.problems');
    const problems = [
        {
            name: "DMOPC '15 Contest 6 P3 - Harvest", link: "https://dmoj.ca/problem/dmopc15c6p3", input: `5 5 6
2 5
1 3
4 5
3 3
1 2`
        },
        {
            name: "The Third Cellar", link: "https://dmoj.ca/problem/phantom2", input: `2
1 1000
1000 4000`
        }, {
            name: "CCC '10 S4 - Animal Farm", link: "https://dmoj.ca/problem/ccc10s4", input: `4
3 1 2 3 7 4 6
4 1 2 4 5 7 7 2 6
4 4 7 6 5 4 8 9 2
5 3 2 4 7 8 4 7 4 7 7`
        },
        {
            name: "CCC '03 S5 - Trucking Troubles", link: "https://dmoj.ca/problem/ccc03s5", input: `5 7 3
1 2 20
1 3 50
1 4 70
1 5 90
2 3 30
3 4 40
4 5 60
2
4
5`
        },
        {
            name: "2spooky4me", link: "https://dmoj.ca/problem/2spooky4me", input: `3 100 10
20 59 4
30 69 4
40 79 4`
        },
        {
            name: "An Animal Contest 4 P3 - Snowy Slopes", link: "https://dmoj.ca/problem/aac4p3", input: `3 4
1 2
4 4
7 1
-1 1
2 1
4 6
-2 2`
        },
        {
            name: "Another Contest 3 Problem 1 - Diverse Arrays", link: "https://dmoj.ca/problem/acc3p1", input: `4 2
1
2
2
2`
        },
        {
            name: "CCC '00 S4 - Golf", link: "https://dmoj.ca/problem/ccc00s4", input: `100
3
33
66
1`
        },
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
3`
        },
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
0 0`
        },
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
            name: "GlobeX Cup '18 S3 - Playing With Bits",
            link: "https://dmoj.ca/problem/globexcup18s3",
            input: `2 1000000007 3 5`
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
            name: "DMOPC '15 Contest 1 P5 - Lelei and Dragon Scales",
            link: "https://dmoj.ca/problem/dmopc15c1p5",
            input: `5 5 4
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
            name: "Yet Another Contest 6 P3 - No More Cell Phone Messaging",
            link: "https://dmoj.ca/problem/yac6p3",
            input: `2 3
2
2`
        }, {
            name: "Wesley's Anger Contest 6 Problem 3 - Difference Sorting",
            link: "https://dmoj.ca/problem/wac6p3",
            input: `8
1 4 4 2 7 14 12 10`
        }, {
            name: "Tropical Bananas", link: "https://dmoj.ca/problem/tropical", input: `4 5
1 1 4 9 0
1 2 4 10 -7
0 1 2 4 6
0 2 3 3 -9
0 2 3 5 -1`
        }, {
            name: "Triway Cup '18 Summer B - Beautiful Water Pearl",
            link: "https://dmoj.ca/problem/tc18summerb",
            input: `110 44 66`
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
        }, {
            name: "CCO Preparation Test 6 P3 - HopScotch", link: "https://dmoj.ca/problem/ccoprep6p3", input: `4
1 2 1 1
3
1 1
2 1 1
1 1`
        }, {
            name: "NOI '04 P1 - The Depressed Cashier", link: "https://dmoj.ca/problem/noi04p1", input: `9 10
I 60
I 70
S 50
F 2
I 30
S 15
A 5
F 1
F 2`
        }, {
            name: "DMPG '15 S6 - Apples to Oranges", link: "https://dmoj.ca/problem/dmpg15s6", input: `3 4
APPLES
ORANGE
GRAPE
ORANGE APPLES 2.0000000000
APPLES ORANGE 0.5000000000
APPLES GRAPE 1.0000000000
GRAPE ORANGE 0.5000000000`
        }, {
            name: "Fibonacci Sequence (Harder)", link: "https://dmoj.ca/problem/fibonacci2", input: `26`
        }, {
            name: "CCO Preparation Test 1 P3 - K-th Rank Student", link: "https://dmoj.ca/problem/ccoprep1p3", input: `5 1
4 3 2 5 1
1 2
7
Q 3 2
Q 2 1
B 2 3
B 1 5
Q 2 1
Q 2 4
Q 2 3`
        }, {
            name: "CCC '10 S3 - Firehose", link: "https://dmoj.ca/problem/ccc10s3", input: `4
0
67000
68000
77000
2`
        }, {
            name: "CCO '10 P2 - Tree Pruning", link: "https://dmoj.ca/problem/cco10p2", input: `6 3
0 1 2
1
3
1 1 2
2
5
2 1 1
4
3 1 0
4 0 0
5 1 0`
        }, {
            name: "Baltic OI '07 P5 - Connected Points", link: "https://dmoj.ca/problem/btoi07p5", input: `3`
        }, {
            name: "Fibonacci Sequence", link: "https://dmoj.ca/problem/fibonacci", input: `26`
        }, {
            name: "Educational DP Contest AtCoder R - Walk", link: "https://dmoj.ca/problem/dpr", input: `4 2
0 1 0 0
0 0 1 1
0 0 0 1
1 0 0 0`
        }, {
            name: "Baltic OI '13 P2 - Palindrome-Free Numbers", link: "https://dmoj.ca/problem/btoi13p2", input: `123 321`
        }, {
            name: "CCO '14 P2 - King Gruff", link: "https://dmoj.ca/problem/cco14p2", input: `4 5 1 3
1 2 5 1
1 2 8 50
2 3 2 15
3 1 80 1000
3 4 1 1
4
8
6
90
94`
        }, {
            name: "LKP '18 Contest 1 P4 - Fun in Föràg", link: "https://dmoj.ca/problem/lkp18c1p4", input: `4 4
1 4 10
1 2 3
3 4 2
2 3 1
1 4 9`
        }, {
            name: "CCC '15 S4 - Convex Hull", link: "https://dmoj.ca/problem/ccc15s4", input: `10 4 7
1 2 4 4
1 3 7 2
3 1 8 1
3 2 2 2
4 2 1 6
3 4 1 1
1 4 6 12
1 4`
        }, {
            name: "COCI '06 Contest 5 #6 Dvaput", link: "https://dmoj.ca/problem/coci06c5p6", input: `3`
        }, {
            name: "CCO '15 P2 - Artskjid", link: "https://dmoj.ca/problem/cco15p2", input: `3 3
0 2 5
0 1 4
1 2 3`
        }, {
            name: "CCC '18 S4 - Balanced Trees.cpp", link: "https://dmoj.ca/problem/ccc18s4", input: `4`
        }, {
            name: "CCC '14 S4 - Tinted Glass Window", link: "https://dmoj.ca/problem/ccc14s4", input: `4
3
11 11 20 15 1
13 8 14 17 2
17 8 18 17 1
12 12 19 13 1`
        }, {
            name: "IOI '01 P1 - Mobile Phones", link: "https://dmoj.ca/problem/ioi01p1", input: `0 4
1 1 2 3
2 0 0 2 2
1 1 1 2
1 1 2 -1
2 1 1 2 3
3`
        }, {
            name: "CCC '13 S5 - Factor Solitaire", link: "https://dmoj.ca/problem/ccc13s5", input: `15`
        }, {
            name: "CCC '16 S4 - Combining Riceballs", link: "https://dmoj.ca/problem/ccc16s4", input: `7
47 12 12 3 9 9 3`
        }, {
            name: "CCC '02 S3 - Blindfold", link: "https://dmoj.ca/problem/ccc02s3", input: `2
4
....
.XX.
3
F
R
F`
        }, {
            name: "A Fenwick Tree Question", link: "https://dmoj.ca/problem/olyrim2", input: `6 1
4 4 8 10 4 6
2 3 6`
        }, {
            name: "MNYC '16 Rocks", link: "https://dmoj.ca/problem/mnyc16p6", input: `12
A a
A b
A c
M a c
M b c
S a c
M b a
R c d
M d b
A c
A d
N`
        }, {
            name: "COCI '15 Contest 2 #5 Vudu", link: "https://dmoj.ca/problem/coci15c2p5", input: `3
1 2 3
3`
        }, {
            name: "Binary Search Tree Test", link: "https://dmoj.ca/problem/ds4", input: `5 8
9 4 8 11 2
S 4
I 1
S 13
R 10
L 10
L -5
I 8
L 8`
        }, {
            name: "CCO '10 P3 - Wowow", link: "https://dmoj.ca/problem/cco10p3", input: `7
N 10 1000
N 3 1014
Q 1
M 10 2000
Q 1
N 65 1950
Q 2`
        }, {
            name: "DMOPC '19 Contest 6 P4 - Grade 12 Math", link: "https://dmoj.ca/problem/dmopc19c6p4", input: `10 10
1 5
3 4 5 0
1 10
3 9 10 -1
2 8
3 8 10 -1
3 1 10 0
3 6 10 -2
1 5
3 4 9 2`
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
