#version 330 core

in vec2 v_TexCoord;
// Ouput data
out vec4 color;
uniform vec4 u_Color;
uniform sampler2D u_Texture;

void main()
{
	vec4 texColor = texture(u_Texture,v_TexCoord);
	color = texColor; //vec3(1,0.5,0.3);

}