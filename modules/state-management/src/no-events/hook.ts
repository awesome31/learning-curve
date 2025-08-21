import { useState } from "react";

const useNoEvents = () => {
  const [currentStepIndex, setCurrentStepIndex] = useState(0);

  const handleNextStep = () => {
    setCurrentStepIndex(currentStepIndex + 1);
  };

  const handlePreviousStep = () => {
    if(currentStepIndex > 0) {
      setCurrentStepIndex(currentStepIndex - 1);
    }
  };

  const handleSkipStep = () => {
    setCurrentStepIndex(3);
  };

  const handleReset = () => {
    setCurrentStepIndex(0);
  };

  return {
    currentStepIndex,
    handleNextStep,
    handlePreviousStep,
    handleSkipStep,
    handleReset
  }
}

export default useNoEvents;
