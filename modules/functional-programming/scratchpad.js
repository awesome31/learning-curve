import * as R from 'ramda';

//This will enforce us to write functional code.
const setNewStoreData = (data) => console.log("Setting store data:",data);
const triggerAnalytics = (data) => console.log("Triggering analytics:", data);
const modifyDataForAnalytics = (data) => ({...data, name: "Rohit here"})

function doSomething() {
  R.pipe(
    R.tap(setNewStoreData),
    modifyDataForAnalytics,
    triggerAnalytics
  )({
    name: "Rohan"
  });
}

doSomething();
