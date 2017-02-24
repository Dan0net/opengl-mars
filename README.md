OpenGL Mars
===========

OpenGL &amp; C++ animation on the surface of mars. 
### [Youtube video](http://youtu.be/W5GrXgs9pnU)
![Screenshot](http://i.imgur.com/iEQ3Ff7.jpg)

Includes: texture mapping, normal mapping, shadow mapping,  specular shading, point lighting, directional lighting, point clouds, billboard particles, skybox, .obj meshes & animations.

Keys
----
- **W A S D / Arrow keys** : camera acceleration and rotation
- **Page Up / Down** : camera altitude
- **T** : start animated tour
- **E** : exit animated tour
- **H** : help
- **P** : screenshot location
- **ESC / Q** : exit

Requires
--------
- OpenGL
- GLM
- GLEW
- GLFW

3D Models
---------
Landscape rock model imported from 3D Warehouse: http://sketchup.google.com/3dwarehouse/details?mid=492a88d09e2bc900f75b791738ce5d1e.

All other models and animations designed in Blender.

Textures
--------
The sun halo, star and help textures designed in Photoshop & Fireworks.

The scanner and lander textures designed in Blender.

All other textures are designed and generated using Filter Forge.

Code
----
All code is original content. Learnt, implemented and designed from scratch in under 2 weeks, the code is messy and very poorly structured but works.

For the .obj model loader, VAO indexing and tangent calculation, inspiration was taken from http://www.opengl-tutorial.org/.

For the structure of the Texture Shader and Billboard shader, inspiration was taken from http://ogldev.atspace.co.uk/index.html.
