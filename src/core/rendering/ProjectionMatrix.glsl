#version 460 core // Declares what version we're using
// We expect a vertex attribute at location 0 that will have 3 float numbers
/**
First we give a layour qualifier (location = 0), we can let it determine the location by not specifying it

*/
layout (location = 0) in vec3 aPosition;

/// Uniform is a qualifier in GLSL which says that the variable is incoming via the CPU
/// On the CPU side we can upload a variable to the GPU using GLs uniform functions
/// This means that now we have 2 different sets of locations which can be used
layout (location = 0) uniform mat4 uTransform;
uniform mat4 uProjection;
uniform mat4 uView;

void main() {
    /// gl_Position is a special variable which is built into GLSL used by
    /// OpenGL to determine the final position of a vertex
    gl_Position = uProjection * uView * (uTransform * vec4(aPosition, 1.0));
}