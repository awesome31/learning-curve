# 12 Factor Agents

Here I am jotting down my understanding of what the 12 factor agents are and what the principles behind them are.

## Brief History of Software

The idea is that software always was a DAG. That means that the software engineer had to define a set of things that can be done determinstically. It can be a conditional or a loop. Thats it. With agents, the dynamic shifted. Ideally an agent is:

1. A prompt: To tell the LLM how to behave and what "tools" it has available. The output of the prompt is a JSON object that describe the next step in the workflow. It can either say that it is done or do tool call or function call.
2. Switch Statement: Based on the JSON that the LLM retruns, decided what to do with it.
3. Accumalated context: Store the list of steps that have happened and their results.
4. for loop: Until the LLM emots some sort of Terminal call, add the result of the switch statement to the context window and ask the LLM to choose the next step.

```
initial_event = {"message": "..."}
context = [initial_event]
while True:
  next_step = await llm.determine_next_step(context)
  context.append(next_step)

  if (next_step.intent === "done"):
    return next_step.final_answer

  result = await execute_step(next_step)
  context.append(result)
```

## Factor 1: Natural Language to Tool Calls

Factor 1 is honestly pretty straightforward. One of the most common patterns in agent building is to convert naturla language to tool calls. This pattern when applied takes some input like:

Input: "Can you look for flights in the range of 10k to 20k from Delhi to Mumbai. I only need business class"

Structured Output:

```json
{
  "function": {
    "name": "search_flights",
    "parameters": {
      "origin": "Delhi",
      "destination": "Mumbai",
      "min_price": 10000,
      "max_price": 20000,
      "cabin_class": "business"
    }
  }
}
```

## Factor 2: Own your prompts

Instead of relying in a specific framework to create your prompt, we should OWN the prompt. This gives us control over the prompt and how the tokens are affecting the output. Also we need to treat them as first class code. The benifit of owning the prompts is:

1. Gives you full control.
2. Testing and Evals: Build tests and avals for your prompts just like you would for any other code.
3. Iteration: Quickly modify promots based on real world performance.

## Factor 3: Own your Context Window

At any given point, your input to an LLM in an agent is "here's what's happened so far, what's the next step"

Instead of the standard asssistant, user, tool_call, tool_result format, we can create our own custom context templates. We can use XML or any other formatting that works for our use case. The key benifits to own your context window is:

- Information Density: Structure information in ways that maximize the LLM's understanding.
- Error Handling: Include error information in a format that helps the LLM recover. Consider hiding errors and failed calls from context window once they are resolved.
- Safety: Control what information gets passed to the LLM, filtering out sensitive data
- Flexibility: Adapt the format as you learn what works best for your use case
- Token Efficiency: Optimize context format for token efficiency and LLM understanding

The Context at the end of the day includes: prompts, instructions, RAG documents, history, tool calls, memory.

## Factor 4: Tools are structured outputs

Tools don't need to be complex. At their core, they're just structured output from your LLM that triggers deterministic code.

The pattern is simple:

1. LLM outputs structured JSON
2. Deterministic code executes the appropriate action (like calling an external API)
3. Results are captured and fed back into the context

## Factor 5: Unify execution state and business state

The core idea: don't maintain two separate state systems — one for "where is the agent in its workflow" (execution state) and another for "what has the agent actually done" (business state). Merge them into one.

The problem it solves: Many infrastructure systems (like workflow engines — think Temporal, Airflow) keep separate tracking for execution state (current step, next step, retry count, waiting status) vs. business state (the actual messages, tool calls, results). This creates complexity — you need to keep them in sync, handle edge cases when they diverge, etc.

Ideally the execution state should be inferred from the buisiness state.

## Factor 6: Laucnh/Pause/Resume with Simple APIs

If the state is unified, then it should be simple to launch, pause, and resume. We just append a new even and re run the agent loop. So ideally this is tied to the factor 5.

## Factor 7: Contact human with tools

We might get better results by having the LLM always output json, and then declare it's intent with some natural language tokens.

Benifits:

1. Clear Instructions: Tools for different types of human contact allow for more specificity from the LLM.
2. Inner vs Outer Loop: Enables agents workflows outside of the traditional chatGPT-style interface, where the control flow and context initialization may be Agent->Human rather than Human->Agent (think, agents kicked off by a cron or an event)
3. Multiple Human Access: Can easily track and coordinate input from different humans through structured events
4. Multi-Agent: Simple abstraction can be easily extended to support Agent->Agent requests and responses
5. Durable: Combined with factor 6 - launch/pause/resume with simple APIs, this makes for durable, reliable, and introspectable multiplayer workflows

## Factor 8: Own your control flow

Instead of relying on a framework to control the flow, we should own the control flow. This gives us control over the flow and how the tokens are affecting the output. We might also want to incorporate summarization, LLS as a judge, cloggin and tracing, client side rate limiting etc.

## Factor 9: Compact Errors into Context Window

The idea is that during the execution loop of an agent, if the LLM makes an error, append that as an event for an LLM so that it can self heal and figure out the next step of next action. This also enabled the agent to continue the workflow. We can add a retry count logic to prevent infinite loops. This is really neat.

## Factor 10: Small, focused Agents

We should create small focused agents for a specific task. This makes it easier to reason about the agent and its behavior. It also makes it easier to test and debug the agent. Ideally an agent should be able to do ~10-20 steps in a workflow. This also helps us in managing the contetxt well.

## Factor 11: Trigger from Anywhere

Enable users to trigger agents from slack, email, sms, or whatever other channel they want. Enable agents to respond via the same channels.

Benefits:

1. Meet users where they are: This helps you build AI applications that feel like real humans, or at the very least, digital coworkers
2. Outer Loop Agents: Enable agents to be triggered by non-humans, e.g. events, crons, outages, whatever else. They may work for 5, 20, 90 minutes, but when they get to a critical point, they can contact a human for help, feedback, or approval

## Factor 12: Make your agent a stateless reducer

An AI Agent is a foldL where the accumaltor is the context windiow and the reducer is an LLM DetermineNextStep + a switch statement to handle it.

## Appendix

### Outer Loop Agents vs Inner Loop Agents

Inner Loop Agent — Human drives, agent responds. The classic chat pattern. User sends a message, agent reacts.
Example: You message Howdy "remind me at 9am" → agent asks "about what?" → you reply → agent sets reminder.

Outer Loop Agent — Agent drives, contacts humans only when needed. Triggered by events/crons/webhooks, runs autonomously, and pulls in a human at critical moments.
Example: Howdy's calendar agent notices a conflict at 3am, works out options, then pings you at 8am: "You're double-booked at 2pm — want me to reschedule the standup?"

### Messaging Loop

The agent is a **stateless reducer**: a `while` loop that sends the full thread to the LLM each time. The LLM returns `{ intent: "..." }`. A switch statement decides what to do.

**Tools & Control Flow:**

| Tool                | Shows msg?     | Pauses? | Loop                    |
| ------------------- | -------------- | ------- | ----------------------- |
| `ask_user`          | Yes            | Yes     | Exits, resumes on reply |
| `confirm_with_user` | Yes            | Yes     | Exits, resumes on reply |
| `reply`             | Yes            | No      | Continues               |
| `send_message`      | No (to others) | No      | Continues               |
| `schedule_reminder` | No             | No      | Continues               |
| `done`              | Yes            | No      | **Exits**               |

**Switch statement:**

```python
while True:
    next_step = await llm.determine_next_step(thread)
    thread.append(next_step)

    if next_step.intent == "done":
        render_message(next_step.message)
        return                          # EXIT

    elif next_step.intent == "reply":
        render_message(next_step.message)
        continue                        # KEEP GOING

    elif next_step.intent in ("ask_user", "confirm_with_user"):
        render_message(next_step.message)
        save_thread(thread)
        return                          # EXIT, wait for user

    else:  # action tools (send_message, schedule_reminder, etc.)
        result = await execute_tool(next_step)
        thread.append(result)
        continue                        # KEEP GOING
```

**Resume after pause:**

```python
async def on_user_message(user_id, message):
    thread = await load_thread(user_id)
    thread.append({ type: "howdy_message", data: message })
    await agent_loop(thread)  # re-enters the while loop fresh
```

**Context window format (XML — more token-efficient than JSON):**

```xml
<howdy_message>
    From: @rohit
    Text: Send Priya a message saying I'll be late
</howdy_message>
<send_message>
    intent: "send_message"
    to: "priya"
    text: "Hey, Rohit will be a bit late!"
</send_message>
<send_message_result>
    status: "delivered"
</send_message_result>
<done>
    intent: "done"
    message: "Sent! ✅"
</done>
```

**Inner loop** = user drives (messages Howdy, agent responds).
**Outer loop** = agent drives (triggered by cron/webhook/event, contacts user when needed).
Howdy is **both** — same code, only difference is what creates the first event in the thread.
