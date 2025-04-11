import image from "./MindfulEating.png?as=srcset";

//It has the metadata of the image.
console.log(image, "image");

function setupImage() {
  const imageDiv = document.getElementById("image");
  const newImage = document.createElement("img");
  newImage.src = image.src;
  imageDiv.appendChild(newImage);
}

export { setupImage };
