# miniRT - A Minimal Raytracer in C

## 📝 About the Project

MiniRT is a minimal raytracer implemented in C as part of the 42 School curriculum. This project introduces the fundamentals of ray tracing, a rendering technique that generates realistic 3D images by simulating the physical behavior of light.

<img width="1112" alt="Screenshot 2025-03-08 at 12 24 43 AM" src="https://github.com/user-attachments/assets/2f4e87e8-b372-428b-888e-6821ad96d1a9" />


### Features

- Rendering of basic 3D objects (spheres, planes, cylinders)
- Light sources with adjustable brightness
- Phong reflection model for realistic lighting and shading
- Shadows
- Scene description via simple configuration files (.rt)
- Camera manipulation with adjustable field of view

## 🔧 Prerequisites

- macOS or Linux operating system
- GCC or Clang compiler
- Make build system
- X Window System libraries (X11, Xext)
- MinilibX graphics library (included)

## 🚀 Installation

Clone the repository and compile the program:

```bash
git clone https://github.com/seongil99/miniRT.git
cd miniRT
make
```

The compilation process will generate the `miniRT` executable.

## 🎮 Usage

Run the program with a scene file (.rt) as a parameter:

```bash
./miniRT rt_files/sphere1.rt
```

### Included Scene Files

The project comes with several predefined scene files in the `rt_files/` directory:

- `plain1.rt` - A simple plane scene
- `plains.rt` - Multiple planes forming a room
- `plains_spheres.rt` - Planes and spheres together
- `sphere1.rt`, `sphere2.rt`, `sphere3.rt` - Simple sphere scenes with different lighting
- `temple.rt` - A more complex scene resembling a temple structure

### Controls

- **ESC key**: Exit the program
- **Close window button**: Exit the program

## 🗺️ Scene File Format

Scene files use a simple custom format to define 3D elements:

```
# Element type | Parameters

# Ambient lighting (required, only one)
A   light_ratio   r,g,b

# Camera (required, only one)
C   x,y,z   nx,ny,nz   fov

# Light (optional, multiple allowed)
L   x,y,z   brightness   r,g,b

# Sphere
sp  x,y,z   diameter   r,g,b

# Plane
pl  x,y,z   nx,ny,nz   r,g,b

# Cylinder
cy  x,y,z   nx,ny,nz   diameter   height   r,g,b
```

### Parameters Explanation

- `x,y,z`: Coordinates in 3D space (position)
- `nx,ny,nz`: Normalized orientation vector [-1,1]
- `fov`: Camera field of view in degrees [0-180]
- `light_ratio`, `brightness`: Values between 0 and 1
- `r,g,b`: RGB color values [0-255]
- `diameter`, `height`: Positive values for dimensions

## 🧠 Technical Implementation

The raytracer follows these fundamental steps:

1. Parse the scene file to create a 3D scene with objects, lights, and a camera
2. For each pixel in the output image:
   - Generate a ray from the camera through the pixel
   - Find intersections with scene objects
   - Calculate lighting and shading using the Phong reflection model
   - Determine the pixel color based on material properties and light sources

The project follows the principles of ray tracing described by Peter Shirley in "Ray Tracing in One Weekend" and implements:

- Vector mathematics in 3D space
- Ray-object intersection algorithms
- Diffuse and specular reflection
- Shadow calculation
- Phong lighting model

## 📁 Project Structure

```
miniRT/
├── includes/           # Header files
├── libft/              # Custom C library
├── mlx/                # MinilibX graphics library
├── rt_files/           # Sample scene files
└── src/                # Source code
    ├── parsing/        # Scene file parsing
    ├── print/          # Display functions
    ├── scene/          # Scene object management
    ├── trace/          # Ray tracing algorithms
    │   ├── hit/        # Ray-object intersection
    │   └── ray/        # Ray generation and rendering
    └── utils/          # Utility functions
```

## 🖼️ Examples

### Multiple Shapes

<img width="1112" alt="Screenshot 2025-03-08 at 12 22 34 AM" src="https://github.com/user-attachments/assets/fe37ddf1-b9b2-40fd-abff-6813fe0110b6" />


## 💡 Implementation Details

### Vector Operations

The project implements a custom 3D vector library for all vector operations needed for ray tracing:

- Vector creation and manipulation
- Addition, subtraction, scaling
- Dot and cross products
- Vector normalization
- Length calculations

### Ray-Object Intersections

For each object type, specific intersection algorithms are implemented:

- **Spheres**: Solving quadratic equations for ray-sphere intersections
- **Planes**: Using the plane equation and ray direction
- **Cylinders**: Combining ray-cylinder body and ray-cap intersections

### Lighting and Shading

The Phong illumination model is implemented with:

- Ambient light component
- Diffuse reflection (Lambert's cosine law)
- Specular reflection
- Shadow calculation

## 📄 License

This project is developed as part of the 42 School curriculum and is provided for educational purposes.
