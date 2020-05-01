#version 330
in vec4 color;
in vec2 uv;

uniform sampler2D ourTexture;
void main()
{
    gl_FragColor = texture(ourTexture,uv) * vec4(uv,0,1);
}