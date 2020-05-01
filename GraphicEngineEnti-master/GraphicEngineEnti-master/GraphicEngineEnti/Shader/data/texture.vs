#version 330
uniform mat4 MVP;
uniform vec4 uColor;
in vec4 vCol;
in vec3 vPos;
in vec2 vUv;

out vec4 color;
out vec2 uv;
void main()
{
	
    gl_Position = MVP * vec4(vPos, 1.0);
	color =  (vCol + uColor)/2.;
	uv = vUv;

	
}