## 03/21/26 Commit
This was my initial commit. I just created my project and added it to GitHub. I started the project a few days late because I had a midterm around this time that I put all my focus towards.

## 03/24/26 Commit
For this session, I added over the two files given on canvas main.cpp and ArrayStack.h). I did not start any code yet, but I looked over the two templates to see what I was going to have to do. I also looked over the instructions on cannvas.

## 03/27/26 Commit
I started to do the TODOs in ArrayStack.h
- What I worked on: I worked on the first four TODOS of ArrayStack.h. I finished the main structure of push(), pop(), top(), and empty.
- Issues: Although there were no big issues, I had not originally read the canvas instructions and had not added the parts for pop() and top() to handle them safely.
- How I tested: I tested these later on when using them in main.cpp.
- What I fixed: I later on fixed the handling safely parts.

## 03/28/26 Commit
After reading the canvas instructions better, I realized I had to safely handle top() and pop() so I worked on that.

- What I worked on: For this session, I worked on handling top() and pop() safely. I did this by adding if statements in each function to check to see if the stack is empty when the function is called. If the stack is empty, then the program returns because otherwise it would incorrectly complete the operations. 
- Issues: The issue I had was that there was nothing in the program stopping these functions from running and trying to pop or top an empty stack.
- How I tested: I tested these functions later on in main.cpp
- What I fixed: I fixed the handling issues with top() and pop()

## 03/29/26 Commit
I completed everything I needed to do for ArrayStack.h

- What I worked on: For this session, I worked on a return issue for top() and completed the rest of ArrayStack.h.
- Issues: The issue I had and could not figure out how to fix was the return statement I was using for handling an empty stack was being greyed out by CLion. 
- How I tested: I tested this in main.cpp later on
- What I fixed: I fixed the return issue I was having by replacing return; with return T();. I had to ook up online how to do this, and I still dont really understand why the second one worked.

## 03/31/26 Commit 1
Now I started to work on the main.cpp TODOs, for this session I completed the TODO for tokenize;

- What I worked on: For this session, I worked on the TODO for tokenize. This function takes whatever the user inputs and turns the string into tokens and returns them in a vector. It is useful to identify the parts of the expression. 
- Issues: At the time of this commit, I did not think I had any issues, but later on, I would realize I did. 
- How I tested: I tested this part by adding a part of code in main that outputs what is held in the vector created by tokenize.
- What I fixed: At this time, I did not fix anything, but later I would end up fixing a small but impactful issue.

## 03/31/26 Commit 2
For this session, I completed the detection TODOs.

- What I worked on: During this session, I worked on the detection TODOs. This included isValidPostfix and isValidInfix. I had no problems completing isValidPostfix(), which determines if the input tokens are formed as a valid postfix. However, I had a very hard time with isValidInfix. 
- Issues: The issues I had during this session were mostly with isValidInfix(). This was mostly because there were so many conditions that had to be checked to make sure the postfix was valid.
- How I tested: I tested to see if this worked at the end, since it was one of my final steps.
- What I fixed: I was having a very hard time making sure every condition was taken care of for a valid infix. So I did have to ask ChatGPT for help with it. The way I used ChatGPT is I asked it something about all the properties of an infix expression and if it could give me all possible combinations of the properties for +,-,*,/, (, and ) to use for if statements to check a valid infix expression. Then I would use the help that it gave me to complete the function and once I thought I had completed it, I would copy my answer and ask ChatGPT if it was correct. 

## 03/31/26 Commit 3
For this session, I completed the rest of the TODOs I had left 

- What I worked on: In this session, I completed the rest of the TODOs I had left in the program template. This was infixToPostfix(), and evalPostfix(). InfixtoPostfix is used to convert an infix expression that is given, into a postfix expression to help evaluate it using a stack. EvalPostfix is used to compute a postfix expression using a stack.     
- Issues: For this part, I had no issues really, and it all made sense to me.
- How I tested: I tested this at the end of the program because this was the last step I needed to complete the full program.
- What I fixed: I did not fix anything new.

## 03/31/26 Commit 4
After running my program, I noticed there was an issue with the outputs

- What I worked on: I had completed the program and when I was running test numbers, I was seeing that the ouput was not what the correct output should be. So, I looked through the program and after searching forever I found I was missing an i-- in one part of tokenize().
- Issues: I was not seeing the correct output. This was because in tokenize() I had a part where i++ was happening twice causing items in the stack to be skipped, so I just had to add a i-- to counter this
- How I tested: I re-entered the test expressions, and they all outputted correctly afterward.
- What I fixed: I added the i-- to counter the two i++ that were causing elements in the array to be skipped.



