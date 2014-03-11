#version 330 core
precision highp float;

out vec4 FragColor;

uniform vec3 in_Color;

void main(void) {
    FragColor = vec4(in_Color, 1.0);
}
