# 🧊 Simple Model Viewer Project

## 📘 Introduction

This is a simple 3D model viewer project built using OpenGL. It renders a single cube model with different textures and lighting conditions to help visualize how surface appearance changes based on material and lighting. The project demonstrates how 3D and 2D camera systems can coexist—one used for rendering 3D models and the other for UI elements.

The viewer includes an interactive UI with buttons to switch between different lighting modes and textures. Users can freely pan and orbit the 3D scene using the camera. Additionally, smooth cube rotation is achieved using quaternions.

---

## ✨ Features

- 🔁 Choose between **3 different textures**
- 💡 Visualize how **different Phong lighting components** affect rendering
- 🎮 Move and rotate the cube using **keyboard and mouse**
- 🎥 **Pan and orbit the camera** around the model
- 🧭 **Quaternion-based rotation** for seamless and smooth cube animation

---

## 🚀 Usage

### 🔆 Light Selection

Select lighting modes using the **top-right buttons** in the window:

- **Button 1** → Only ambient lighting  
- **Button 2** → Ambient + diffuse lighting  
- **Button 3 (default)** → Full Phong lighting (ambient + diffuse + specular)

### 🎨 Texture Selection

Choose textures using the **bottom-left buttons**:

- **Button 1 (default)** → Wood texture  
- **Button 2** → Sci-fi texture  
- **Button 3** → Minecraft texture  

### 🕹️ Movement & Interaction

- `W` → Move camera **forward**  
- `S` → Move camera **backward**  
- `A` → Move camera **left**  
- `D` → Move camera **right**  
- **Click and hold** mouse + **drag** → **Rotate the cube**

---

## 🧱 Dependencies

This project uses the following libraries:

- [GLAD](https://github.com/Dav1dde/glad) – OpenGL function loader  
- [GLFW](https://www.glfw.org/) – Windowing and input  
- [GLM](https://github.com/g-truc/glm) – OpenGL Mathematics  
- [KHR](https://github.com/KhronosGroup) – OpenGL header specs  
- [stb_image](https://github.com/nothings/stb) – Image loading  

---

## 🗂️ Project Structure

<details>
<summary><code>model-viewer/</code></summary>

- <code>build/</code>  
  &nbsp;&nbsp;&nbsp;&nbsp;• Compiled build directory

- <code>dependencies/</code>  
  &nbsp;&nbsp;&nbsp;&nbsp;• <code>include/</code> – Header files for dependencies  
  &nbsp;&nbsp;&nbsp;&nbsp;• <code>lib/</code> – Precompiled or source libraries

- <code>header/</code>  
  &nbsp;&nbsp;&nbsp;&nbsp;• <code>2d/element.h</code>  
  &nbsp;&nbsp;&nbsp;&nbsp;• <code>3d/camera3d.h</code>  
  &nbsp;&nbsp;&nbsp;&nbsp;• <code>common/</code>  
  &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;• shader.h  
  &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;• texture.h  
  &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;• vao.h  
  &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;• vbo.h  
  &nbsp;&nbsp;&nbsp;&nbsp;• canvas2d.h  
  &nbsp;&nbsp;&nbsp;&nbsp;• canvas3d.h  
  &nbsp;&nbsp;&nbsp;&nbsp;• window.h

- <code>shaders/</code>  
  &nbsp;&nbsp;&nbsp;&nbsp;• <code>cube/</code> – Vertex/fragment shaders for the cube  
  &nbsp;&nbsp;&nbsp;&nbsp;• <code>element/</code> – Vertex/fragment shaders for UI elements

- <code>src/</code>  
  &nbsp;&nbsp;&nbsp;&nbsp;• <code>2d/element.cpp</code>  
  &nbsp;&nbsp;&nbsp;&nbsp;• <code>3d/camera3d.cpp</code>  
  &nbsp;&nbsp;&nbsp;&nbsp;• <code>common/</code>  
  &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;• shader.cpp  
  &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;• texture.cpp  
  &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;• vao.cpp  
  &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;• vbo.cpp  
  &nbsp;&nbsp;&nbsp;&nbsp;• canvas2d.cpp  
  &nbsp;&nbsp;&nbsp;&nbsp;• canvas3d.cpp  
  &nbsp;&nbsp;&nbsp;&nbsp;• window.cpp  
  &nbsp;&nbsp;&nbsp;&nbsp;• glad.c  
  &nbsp;&nbsp;&nbsp;&nbsp;• stb_image.c  
  &nbsp;&nbsp;&nbsp;&nbsp;• main.cpp

- <code>texture/</code>  
  &nbsp;&nbsp;&nbsp;&nbsp;• wood.jpg  
  &nbsp;&nbsp;&nbsp;&nbsp;• scifi.jpg  
  &nbsp;&nbsp;&nbsp;&nbsp;• minecraft.jpg

- <code>.gitignore</code>  
- <code>CMakeLists.txt</code>  
- <code>README.md</code>

</details>