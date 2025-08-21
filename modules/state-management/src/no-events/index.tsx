import useNoEvents from "./hook";
import "./index.css";

const NoEvents = () => {
  const {currentStepIndex, handleNextStep, handlePreviousStep, handleSkipStep, handleReset } = useNoEvents();

  if(currentStepIndex === 0) {
    return (
      <div className="no-events-container">
        <div className="welcome-screen step-content">
          <h1>Welcome to the Learning Curve!</h1>
          <p>Let's get started with your first step.</p>
          <div className="button-container">
            <button onClick={handleNextStep}>Next Step</button>
            <button onClick={handleReset}>Reset</button>
          </div>
        </div>
      </div>
    );
  }  else if(currentStepIndex === 1) {
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
            <button onClick={handleNextStep}>Next Step</button>
            <button onClick={handlePreviousStep}>Previous Step</button>
            {/** Skip step button */}
            <button onClick={handleSkipStep}>Skip Step</button>
            <button onClick={handleReset}>Reset</button>
          </div>
        </div>
      </div>
    );
  } else if(currentStepIndex === 2) {
    return (
      <div className="no-events-container">
        <div className="step-content">
          <h1>Step 2: Understanding the Basics</h1>
          <p>In this step, you'll learn about the basics of the Learning Curve.</p>
          <div className="button-container">
            <button onClick={handleNextStep}>Next Step</button>
            <button onClick={handlePreviousStep}>Previous Step</button>
            <button onClick={handleReset}>Reset</button>
          </div>
        </div>
      </div>
    );
  } else if(currentStepIndex === 3) {
    return (
      <div className="no-events-container">
        <div className="step-content">
          <h1>Step 3: I AM DONE</h1>
          <p>In this step, I am done</p>
          <div className="button-container">
            <button onClick={handleNextStep}>Next Step</button>
            <button onClick={handlePreviousStep}>Previous Step</button>
            <button onClick={handleReset}>Reset</button>
          </div>
        </div>
      </div>
    );
  }
}

export default NoEvents;
