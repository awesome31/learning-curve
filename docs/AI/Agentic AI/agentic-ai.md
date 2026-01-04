# Agentic AI

## Introduction

### What is agentic AI?

An Agentic AI workflow is a process where an LLM-based application executes multiple steps to complete a task. What we will learn is how to take a simple task and break it down into smaller tasks to create an iterative loop of LLM calls to complete the desired task.

### Degress of Autonomy

Initially when the word agent was used in AI systems, it was used as a binary. An agent was either autonomous or not. But soon we realised that instead of using a noun its better to use an adjective like 'agentic' because it allows us to describe the degree of autonomy. Autonomy means how much the system can make decisions on its own.

1. Less Autonomy: The system is given a fixed set of instructions and follows them without making any decisions on its own. The automony is in text generation.

2. More Autonomy: The system is given a fixed set of instructions along with tools that it can access, and then the agent decides which tool to use and when to use it.

### Benifits of Agentic AI

1. Parllelization for Speed: Unlike Humans, in an agentic workflow we can run multiple LLM calls in parallel to speed up the process.

2. Better result with pre trained models: Using Agentic workflow techniques, the output that we desire gets better irrespective of the quality of the pre-trained model.

3. Adding and swapping components becomes extremely easy ie its very modular.

### Agentic AI Applications

Lets check the applications that people are building.

1. Invoice processing workflow: In this workflow, people are taking a PDF of an invoice and extracting important fields and if the fields exists, updating the database for the same.

2. Responding to customer email: In this workflow, given the orderId, the system will fetch the order details and respond to the customer email.

3. Customer Service agent: This is a more challenging application to build. Lets assume the user asks for do you have any black jeans or blue jeans, then the tols have to check the inventory etc. Its challenging because, the required steos are not known ahead of time. It can be anything.

4. Very difficult: Agents that can use computers.

The easier things to build using agents are where the steps are known and the assets are text/images only. For things where the required steps are not known ahead of time, it gets difficult to build.

### Task Decomposition

Usually whenever Humans work on somethimg, they break it down into smaller tasks to complete it. This is exactly what should be done for agentic systems. Lets see how we can go about it. The way to break down is to think how a human would approach a task, and then break it step by step. Then for each step, ask this question: "Can LLM do it on its own OR it needs a tool or a function that it can refer to to do the task?"?

Whenever we are building agents, its important to understand the building blocks of the system:

1. Models:

   - LLMs: text extraction, tool use and information extraction.
   - Image analysis models: Analyse image, extract keywords etc.

2. Tools:
   - API - To use the browser or get the weater data etc.
   - Information Retrieval: To fetch relevant information from a database.
   - Code execution: To execute code.

### Evaluating Agentic AI

1. Look for low-quality outputs
2. Add an evaulation code to check for the evaulation errors. For example, if the send email customer agent is also mentioning our competitors name, then we can add code to check for that and penalize the agent. For objective metrics, its easy to write code.

3. We can use the LLM-Judge technique, where we can use another LLM to evaluate the output of the agent.

### Agentic Design Patterns

There are a lot of agentic design patterns that help in creating agentic AI applications. Some of them are:

1. Reflection: Here instead of telling the LLMs what to do, we can ask them to reflect on the task and come up with a plan to complete it. We can even let the LLM critique its own work or give it access to tools for it to run like unit test so that it can critique itself and then build on top of it.

2. Tool use: We can give access to LLMs to tools like Code completion or web search or email or anything and let the LLM decide how to use the tools to complete a specific task.

3. Planning: In this pattern, the system can decide what is the sequence of steps it can take to complete a task.

## Reflection Design Pattern

### What is Reflection Design Pattern?

1. Reflection for LLMs is a design pattern in which we ask the LLM to reflect on the task and then correct or revise the draft state of the task iteratively. We can even use different LLMs, one to do the task the second to reflect and critique.

2. We can also do reflection using external feedback. For example, we can tell it to run unit test or to execute the code that it has written which in turn helps it to reflect and come up with better outputs. This is a much better way.

### Why not just direct generation?

Direct generation means, we prompt the LLM to do the task and let it generate the output. These are called zero-shot prompting. We include zero examples in the prompt. Reflection consistently outperforms direct generation on a variety of tasks. Reasoning models are generally better at reasoning.

### Evaluating the impact of Reflection

Because Reflection is an extra step, it actually slows down the system a little bit. To evaluate if reflection improves the quality of the final output, we can:

1. Create a number of inputs along with the ground truth output and evaluate the agents output with and without the reflection step. This only works if the output is objective.

2. Use LLM-Judge technique to evaluate the output of the agent. Give the LLM judge a criteria, and let it evaluate the output of the agent. But answers are not really good when we want it to COMPARE two things. Most LLMs have a position bias. Instead we can ask the LLM to grade with a rubric where we give it a set of criterias and tell it score using 0 and 1, it tends to give the evaluation in a better way.

### Using external feedback

Reflection with an external feedback, is a much better way. The feedback can be some code or a web search or execution of code.

## Tool use

### What are Tools?

Tools are essentially small functions that our Large Language can call and get some data out of. We can leave it upto the LLM to decide whether it should call a tool or not.

### Creating a Tool

1. Before LLMs could not understand tools. TO make them aware that these tools exist, we first prompt it and tell it that these are the tools that it can use along with a thing that it can return when it wants the developer to call the tool. Then in the code, the programmer used to parse the LLM output and see if a tool call is requested. If yes then the tool call was done AND the output was returned to the LLM along with the conversation history. Obviously this was not a very scalable way to do it.

2. Modern syntax is to use the docstring to describe the tool and the tool name. The LLM can then call the tool using the tool name and the docstring can be used to describe the tool. This is a much better way.

### Code Execution

Instead of letting the LLM call the tool, we can let the LLM write the code and then if the LLM retruns a certain response to execute code, then our code internally executes the code and gives the response back.

To make sure that the code is safe to execute, we can use a sandbox environment.

### MCP

Model Context Protocol was proposed by Anthropic as standard to let Large Language Models access tools that they can call. The idea is that we have a public list of tools that the LLM can call and the LLM can call them based on the context. The idea of MCP was create a standard. There are a lot of MCP Clients and Servers which implement this standard.

## Practical Tips for Building Agentic AI

### Evaluations

Evaluations are important. We can give it a set of inputs and evaluate the output of the agent. The idea is same as what is talked about above.
