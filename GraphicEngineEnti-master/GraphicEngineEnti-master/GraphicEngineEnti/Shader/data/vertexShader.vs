#version 110
uniform mat4 MVP;
uniform vec4 uColor;
attribute vec4 vCol;
attribute vec3 vPos;

varying vec4 color;
void main()
{
	
    gl_Position = MVP * vec4(vPos, 1.0);
	color =  uColor;//(vCol + uColor)/2.;
	/*if(uColor == vec4(0.0, 0.0, 0.0, 0.0))
    color = uColor + vCol;
	else
	color = uColor  ;*/
}