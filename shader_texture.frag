#version 330 core

uniform float in_LightPower;
uniform vec3 in_LightPosition;
uniform sampler2D in_Texture;

in vec3 Position_W;
in vec3 NormalDirection_C;
in vec3 LightDirection_W;
in vec2 UV;

out vec3 FragColor;

void main(){
	vec3 LightColor = vec3(1,1,1);
	
	vec3 MaterialColor = texture( in_Texture, UV ).rgb;
	vec3 AmbiantColor = vec3(0.2,0.2,0.2) * MaterialColor;
	
	vec3 n = normalize(NormalDirection_C);
	vec3 l = normalize(LightDirection_W);
	float theta = clamp( dot( n,l ), 0,0.8 );
	
	FragColor = AmbiantColor + MaterialColor * LightColor * in_LightPower * theta;
}