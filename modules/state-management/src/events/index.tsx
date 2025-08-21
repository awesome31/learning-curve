import useNoEvents from "./hook";
import "./index.css";

const Events = () => {
  const {currentStep, dummyAction} = useNoEvents();

  if(currentStep === "welcome") {
    return (
      <div className="no-events-container">
        <div className="welcome-screen step-content">
          <h1>Welcome to the Learning Curve!</h1>
          <p>Let's get started with your first step.</p>
          <div className="button-container">
            <button onClick={dummyAction("CLICKED_NEXT")}>Next Step</button>
          </div>
        </div>
      </div>
    );
  }  else if(currentStep === "introduction") {
    return (
      <div className="no-events-container">
        <div className="step-content">
          <h1>Step 1: Introduction</h1>
          <p>Here's what you'll learn in this step:</p>
          <ul>
            <li>Understanding the basics of the Learning Curve</li>
            <li>Setting up your environment</li>
          </ul>
          <div className="button-container">
            <button onClick={dummyAction("CLICKED_NEXT")}>Next Step</button>
            <button onClick={dummyAction("CLICKED_PREVIOUS")}>Previous Step</button>
            {/** Skip step button */}
            <button onClick={dummyAction("CLICKED_SKIP")}>Skip Step</button>
            <button onClick={dummyAction("CLICKED_NEXT")}>Reset</button>
          </div>
        </div>
      </div>
    );
  } else if(currentStep === "understanding") {
    return (
      <div className="no-events-container">
        <div className="step-content">
          <h1>Step 2: Understanding the Basics</h1>
          <p>In this step, you'll learn about the basics of the Learning Curve.</p>
          <div className="button-container">
            <button onClick={dummyAction("CLICKED_NEXT")}>Next Step</button>
            <button onClick={dummyAction("CLICKED_PREVIOUS")}>Previous Step</button>
            <button onClick={dummyAction("CLICKED_RESET")}>Reset</button>
          </div>
        </div>
      </div>
    );
  } else if(currentStep === "done") {
    return (
      <div className="no-events-container">
        <div className="step-content">
          <h1>Step 3: I AM DONE</h1>
          <p>In this step, I am done</p>
          <div className="button-container">
            <button onClick={dummyAction("CLICKED_NEXT")}>Next Step</button>
            <button onClick={dummyAction("CLICKED_PREVIOUS")}>Previous Step</button>
            <button onClick={dummyAction("CLICKED_RESET")}>Reset</button>
          </div>
        </div>
      </div>
    );
  }
}

export default Events;
