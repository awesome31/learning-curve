const express = require("express");
const cors = require("cors");

const app = express();
app.use(cors()); // Allow cross-origin requests if needed

app.get("/events", (req, res) => {
  res.setHeader("Content-Type", "text/event-stream");
  res.setHeader("Cache-Control", "no-cache");
  res.setHeader("Connection", "keep-alive");

  // Send an initial message
  res.write(`data: ${JSON.stringify({ message: "Connected!" })}\n\n`);

  // Send periodic updates
  const interval = setInterval(() => {
    res.write(
      `data: ${JSON.stringify({ time: new Date().toISOString() })}\n\n`
    );
  }, 3000);

  // Handle client disconnect
  req.on("close", () => {
    clearInterval(interval);
    console.log("Client disconnected");
  });
});

app.listen(3000, () =>
  console.log("SSE server running on http://localhost:3000")
);
