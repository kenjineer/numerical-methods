Project developed in partial fulfillment of the course MATH-221-1 Numerical Methods for Ordinary and Partial Differential Equations at Mapua University Intramuros, Philippines.

This program is designed to implement the numerical methods of Gauss-Seidel and Doolittle using the C++ programming language. The program is presented as a console application, and by default, it allows for a maximum of 10 equations and a number precision of 5, which can be easily modified within the program. Although there is no fixed limit on the number of iterations that can be inputted, it is important to note that large data sets may be difficult to read on the console.

Additionally, to ensure optimal performance, the maximum number of equations has been capped at 250 and the maximum precision has been capped at 50 due to limitations in array declaration.

How to run the program:
1. Clone the repository
2. Open build/NumericalMethods.exe to run the program

If you want to run in development mode:
1. Make sure that you have g++ compiler. [VSCode Setup](https://code.visualstudio.com/docs/languages/cpp)
2. Install NodeJS (optional)
3. From package.json, copy the value of "build" parameter and execute on a terminal.
4. (NodeJS installed) Run in dev mode by executing "npm i" once, then "npm run dev". No need to run "npm i" again (dependencies saved inside node_modules)

How to use the program:
1. Upon opening the program, the main menu will be readily available with the following options:<br>
[1] 🔁 Gauss-Seidel<br>
  ⇒　Use Gauss-Seidel method<br>
[2] 🔢 Doolittle<br>
  ⇒　Use Doolittle's method<br>
[8] 🛠️ Preferences<br>
  ⇒　Access program preferences<br>
[9] ❌ Exit<br>
  ⇒　Exit the program<br>

![image](https://user-images.githubusercontent.com/12083667/213802139-f3174c7a-1c74-4af5-88d6-eabb36df49e6.png)

2. Access 🛠️ Preferences by inputting 8. This will show another set of options:<br>
[1] 🟰 Max Equations (10)<br>
  ⇒　Set the maximum equations that can be inputted. Currently set value is shown inside the parentheses.<br>
[2] 🔍 Precision (5)<br>
  ⇒　Set the precision/decimal places displayed. Currently set value is shown inside the parentheses.<br>
[9] 🔙 Go Back<br>
  ⇒　Go back to main menu<br>

![image](https://user-images.githubusercontent.com/12083667/213802763-e470d2eb-e9cf-4fb7-b7c8-092ee59e86da.png)

3. From the main menu, access 🔁 Gauss-Seidel by inputting 1. This will prompt for the number of equations, their values, initial values of x, and number of iterations.

![image](https://user-images.githubusercontent.com/12083667/213803695-fc7c42a2-7e9b-4094-9e08-212e31a39947.png)

![image](https://user-images.githubusercontent.com/12083667/213803734-8baa29b7-c9c4-4b24-b6e1-6b1b042fca41.png)

4. The program should then go back to the main menu after executing a numerical method.

![image](https://user-images.githubusercontent.com/12083667/213803887-a8f774e4-f059-4af5-a105-ee9d8186afe8.png)

5. From the main menu, access 🔢 Doolittle by inputting 2. This will prompt for the number of equations, and their values.

![image](https://user-images.githubusercontent.com/12083667/213804048-acb908ee-abb8-42cb-b5c1-297c6192e3f6.png)

![image](https://user-images.githubusercontent.com/12083667/213804116-06fb20e7-ebb6-4c1d-9107-739e1ab4f92e.png)

6. From the main menu, you may exit the program using ❌ Exit by inputting 9.
