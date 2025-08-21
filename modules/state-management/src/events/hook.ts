import { useState } from "react";

const useEvents = () => {
  const [steps] = useState({
    welcome: {
      next: "introduction",
      previous: "",
      skip: "",
      reset: ""
    },
    "introduction": {
      next: "understanding",
      previous: "welcome",
      skip: "done",
      reset: "welcome"
    },
    "understanding": {
      next: "done",
      previous: "introduction",
      skip: "done",
      reset: "welcome"
    },
    "done": {
      next: "",
      previous: "understanding",
      skip: "",
      reset: "welcome"
    },
  })
  const [currentStep, setCurrentStep] = useState<"welcome" | "introduction" | "understanding" | "done">("welcome");

  const dummyAction = (actionName: string) => () => {
    if(actionName === 'CLICKED_NEXT') {
      setCurrentStep(steps[currentStep].next);
    }
    if(actionName === 'CLICKED_PREVIOUS') {
      setCurrentStep(steps[currentStep].previous);
    }
    if(actionName === 'CLICKED_SKIP') {
      setCurrentStep(steps[currentStep].skip);
    }
    if(actionName === 'CLICKED_RESET') {
      setCurrentStep(steps[currentStep].reset);
    }
  }


  return {
    currentStep,
dummyAction
  }
}

export default useEvents;
