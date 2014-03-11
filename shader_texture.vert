#version 330 core

in vec3 in_Position;
in vec3 in_Normal;
in vec2 in_UV;

out vec3 NormalDirection_C;
out vec3 LightDirection_W;
out vec2 UV;

uniform mat4 MVP;
uniform mat4 V;
uniform mat4 M;
uniform vec3 in_LightPosition;

void main(){
	gl_Position =  MVP * vec4(in_Position, 1.0);
	
	LightDirection_W = in_LightPosition.xyz - (M * vec4(in_Position,1)).xyz;
	
	NormalDirection_C = (V * M * vec4(in_Normal,0.0)).xyz;
	
	UV = in_UV;
}

